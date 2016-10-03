#include "character.h"

/*
 * Character animations
 */
const AnimationFrame _character_frames[3] = {
  // sprite, width bytes, height bytes, time, look
  { character_idle, CHARACTER_IDLE_W, CHARACTER_IDLE_H, 1, as_right },
  { character_walk0, CHARACTER_WALK0_W, CHARACTER_WALK0_H, 3, as_right },
  { character_walk1, CHARACTER_WALK1_W, CHARACTER_WALK1_H, 6, as_right }
};
// idle
AnimationFrame* const _character_anim_idle[1] = { &_character_frames[0] };
// walk
AnimationFrame* const _character_anim_walk[2] = { &_character_frames[1], &_character_frames[2] };
// start animation
const Animation _character_animation = { _character_anim_idle, 0, 1, as_play, 0, as_right, CHARACTER_IDLE_W,
                                         CHARACTER_IDLE_H };

/*
 * Character definition
 */
const TCharacter _character = {
  {
    {
      { LEVEL0_START_POSITION_X, LEVEL0_START_POSITION_Y }, // position
      { CHARACTER_IDLE_W, CHARACTER_IDLE_H },               // size
    },                                                      // Body
    { LEVEL0_START_POSITION_X, LEVEL0_START_POSITION_Y },   // last position
    { 0, 0 },                                               // velocity
  },                                                        // DynamicBody
  { cs_idle },                                              // status
  { cs_idle },                                              // last status
  CPCT_VMEM_START,                                          // pvmem
  &_character_animation                                     // Animation
};

u8
isGround()
{
  u8* tile = getTilePtr(_character.db.body.pos.x, _character.db.body.pos.y + _character.db.body.size.y);
  if(*tile <= 5 || *(tile + _character.db.body.size.x / 2) <= 5)
    return 1;
  else
    return 0;
}

void
characterController()
{
  TCharacter* c = &_character;
  cpct_scanKeyboard_f();
  if(cpct_isAnyKeyPressed()) {
    if(cpct_isKeyPressed(Key_Space)) // jump
    {
      if(isGround() && c->status != cs_jump) {
        // c->db.velocity.y -= JUMP_FORCE;
        c->status = cs_jump;
      }
    }
    if(cpct_isKeyPressed(Key_CursorRight)) // walk right
    {
      c->db.vel.x += 1;
      c->anim->side = as_right; // looking right
      if(isGround() && c->status != cs_jump)
        c->status = cs_walk;
    } else if(cpct_isKeyPressed(Key_CursorLeft)) // walk left
    {
      c->db.vel.x -= 1;
      c->anim->side = as_left; // looking left
      if(isGround() && c->status != cs_jump)
        c->status = cs_walk;
    }
  }
}

void
updateCharacterAnimation()
{
  TCharacter* c = &_character;
  AnimationFrame* frame;

  updateAnimation(c->anim);
  frame = c->anim->frames[c->anim->frame_idx];

  if(c->status != c->last_status) {
    switch(c->status) {
    case cs_idle:
      c->anim->frames = (AnimationFrame**)_character_anim_idle;
      c->anim->numframes = CHARACTER_IDLE_ANIM_FRAMES;
      break;
    case cs_walk:
      c->anim->frames = (AnimationFrame**)_character_anim_walk;
      c->anim->numframes = CHARACTER_WALK_ANIM_FRAMES;
      break;
    }
    c->anim->status = as_play;
    c->anim->frame_idx = 0;
    c->anim->time = frame->time;
  }

  c->db.body.size.x = frame->size_x;
  c->db.body.size.y = frame->size_y;
}

void
updateCharacter()
{
  TCharacter* c = &_character;
  c->db.lastpos.x = c->db.body.pos.x;
  c->db.lastpos.y = c->db.body.pos.y;
  c->db.vel.x = 0;
  c->last_status = c->status;

  characterController();

  if(c->status == cs_jump) {
    c->db.vel.y -= JUMP_FORCE;
    if(c->db.vel.y <= MAX_JUMP_H)
      c->status = cs_fall;
  }

  if(!isGround() && c->status != cs_jump) {
    c->db.vel.y += GRAVITY_FORCE;
    if(c->db.vel.y > 6)
      c->db.vel.y = 6;
  }

  c->db.body.pos.x += c->db.vel.x;
  c->db.body.pos.y += c->db.vel.y;

  if(isGround()) {
    c->db.body.pos.y = (c->db.body.pos.y & 0b11111100); // + 1;
    c->db.vel.y = 0;
    if(c->db.vel.x == 0)
      c->status = cs_idle;
    else
      c->status = cs_walk;
  } else if(c->status != cs_jump) {
    c->status = cs_fall;
  }

  if(c->db.body.pos.x <= 1) {
    if(prevLevel0())
      c->db.body.pos.x = SCREEN_BYTES_WIDTH - c->db.body.size.x - 4;
    else
      c->db.body.pos.x = 4;
  } else if((c->db.body.pos.x + c->db.body.size.x) >= SCREEN_BYTES_WIDTH) {
    if(nextLevel0())
      c->db.body.pos.x = 4;
    else
      c->db.body.pos.x = SCREEN_BYTES_WIDTH - c->db.body.size.x - 4;
  }

  if((c->db.body.pos.y + c->db.body.size.y) >= GAME_SCREEN_H)
    c->status = cs_dead;

  updateCharacterAnimation();
}

/*void
drawCharacter()
{

  TCharacter* c = &_character;
  AnimationFrame* frame = c->anim->frames[c->anim->frame_idx];

  c->p_vmem = cpct_getScreenPtr(CPCT_VMEM_START, c->db.body.pos.x, c->db.body.pos.y);
  cpct_drawSpriteMaskedAlignedTable(frame->sprite, c->p_vmem, frame->size_x, frame->size_y, MASK_TABLE);
}

void
eraseCharacter()
{
  TCharacter* c = &_character;

  u8 w = 6; // + (c->db.lastpos.x & 1);
  u8 h = 8; // + (c->db.lastpos.y & 3);

  cpct_etm_drawTileBox2x4(c->db.lastpos.x / 2, c->db.lastpos.y / 4, w, h, LEVEL0_1_W, CPCT_VMEM_START, _game.map);
}*/