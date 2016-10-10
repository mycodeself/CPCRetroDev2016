#include "character.h"

u8 esmeralds_size = 10;

// Character animations

const AnimationFrame _character_frames[3] = {
  // sprite, width bytes, height bytes, time, look
  { sprite_character_walk0, SPRITE_CHARACTER_WALK0_W, SPRITE_CHARACTER_WALK0_H, 2, as_right },
  { sprite_character_walk1, SPRITE_CHARACTER_WALK1_W, SPRITE_CHARACTER_WALK1_H, 5, as_right },
  { sprite_character_walk2, SPRITE_CHARACTER_WALK2_W, SPRITE_CHARACTER_WALK2_H, 5, as_right },
    
};
// idle
AnimationFrame* const _character_anim_idle[1] = { &_character_frames[0] };
// walk
AnimationFrame* const _character_anim_walk[4] = { &_character_frames[0], &_character_frames[1], &_character_frames[0], &_character_frames[2] };
// start animation
const Animation _character_animation = { _character_anim_idle, 0, 1, as_play, 0, as_right };

// Character definition
const Character _character = {
  {
    {
      LEVEL0_START_POSITION_X, LEVEL0_START_POSITION_Y,   // position
      SPRITE_CHARACTER_WALK0_W, SPRITE_CHARACTER_WALK0_H  // size
    },                                                    // Body
    LEVEL0_START_POSITION_X,
    LEVEL0_START_POSITION_Y, // last position
    { 0, 0 },                // velocity
  },                         // DynamicBody
  { cs_idle },               // status
  { cs_idle },               // last status
  CPCT_VMEM_START,             // pvmem
  &_character_animation      // Animation
};

u8
isGround()
{
  u8* tile = getTilePtr(_character.db.body.x, _character.db.body.y + _character.db.body.h);
  if(*tile <= 5 || *(tile + _character.db.body.w / 2) <= 5)
    return 1;
  else
    return 0;
}

void
characterController()
{
  Character* c = &_character;
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
  Character* c = &_character;
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

  c->db.body.w = frame->w;
  c->db.body.h = frame->h;
}

void checkEmeraldsCollision()
{
  Character* c = &_character;
  Game* g = &_game;
  Body* eme = g->lvl->lm->emeralds;
  u8 i = 0;
  
  if(eme){
    for(;i != esmeralds_size;i++)
    {
      if(checkCollision(&c->db.body, eme)){      
        cpct_memcpy(&g->lvl->lm->emeralds[i], &g->lvl->lm->emeralds[i+1], esmeralds_size-(i+1));
        --esmeralds_size;
        ++g->score;
        break;
      }
      ++eme;
    }
  }
}


void
updateCharacter()
{
  Character* c = &_character;
  c->db.lastx = c->db.body.x;
  c->db.lasty = c->db.body.y;
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

  c->db.body.x += c->db.vel.x;
  c->db.body.y += c->db.vel.y;

  if(isGround()) {
    c->db.body.y = (c->db.body.y & 0b11111100);
    c->db.vel.y = 0;
    if(c->db.vel.x == 0)
      c->status = cs_idle;
    else
      c->status = cs_walk;
  } else if(c->status != cs_jump) {
    c->status = cs_fall;
  }

  if(c->db.body.x <= 1) {
    if(prevLevelMap())
      c->db.body.x = SCREEN_BYTES_WIDTH - c->db.body.w - 4;
    else
      c->db.body.x = 4;
  } else if((c->db.body.x + c->db.body.w) >= SCREEN_BYTES_WIDTH) {
    if(nextLevelMap())
      c->db.body.x = 4;
    else
      c->db.body.x = SCREEN_BYTES_WIDTH - c->db.body.w - 4;
  }

  if((c->db.body.y + c->db.body.h) >= GAME_SCREEN_H)
    c->status = cs_dead;
    
  updateCharacterAnimation();
  
//  checkEmeraldsCollision();
}
