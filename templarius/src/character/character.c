#include "character.h"
#include "sprites/character_walk0.h"
#include "sprites/character_walk1.h"
#include "sprites/character_walk2.h"
#include "sprites/character_idle.h"
#include "sprites/character_jump.h"
#include "sprites/character_attack.h"
#include "../common.h"
#include "../utils/utils.h"
#include "../levels/level1/level1.h"
#include "../enemies/skeleton.h"
#include "../game.h"
#include "../hud/hud.h"

#define MAX_JUMP_H -12
#define JUMP_FORCE 4

// CHARACTER NUMBER OF FRAMES PER ANIM
#define CHARACTER_IDLE_ANIM_FRAMES    1
#define CHARACTER_WALK_ANIM_FRAMES    4
#define CHARACTER_JUMP_ANIM_FRAMES    1
#define CHARACTER_ATTACK_ANIM_FRAMES  1

// Character animations
const AnimationFrame _character_frames[6] = {
  // sprite, width bytes, height bytes, time, look  
  { sprite_character_walk0,   SPRITE_CHARACTER_WALK0_W,   SPRITE_CHARACTER_WALK0_H,  3, as_right },
  { sprite_character_walk1,   SPRITE_CHARACTER_WALK1_W,   SPRITE_CHARACTER_WALK1_H,  3, as_right },
  { sprite_character_walk2,   SPRITE_CHARACTER_WALK2_W,   SPRITE_CHARACTER_WALK2_H,  3, as_right },
  { sprite_character_idle,    SPRITE_CHARACTER_IDLE_W,    SPRITE_CHARACTER_IDLE_H,   1, as_right },    
  { sprite_character_jump,    SPRITE_CHARACTER_JUMP_W,    SPRITE_CHARACTER_JUMP_H,   1, as_right },
  { sprite_character_attack,  SPRITE_CHARACTER_ATTACK_W,  SPRITE_CHARACTER_ATTACK_H, 5, as_right },
};

// walk
AnimationFrame* const _character_anim_walk[4] = { &_character_frames[0], &_character_frames[1], &_character_frames[0], &_character_frames[2] };
// idle
AnimationFrame* const _character_anim_idle[1] = { &_character_frames[3] };
// jump
AnimationFrame* const _character_anim_jump[1] = { &_character_frames[4] };
// attack
AnimationFrame* const _character_anim_attack[1] = { &_character_frames[5] };
// start animation
const Animation _character_animation = { _character_anim_idle, 0, 1, as_play, 0, as_right };

// Character template
const Character _character_template = 
{
  {
    sprite_character_idle,  // sprite
    2,                      // draw
    {LEVEL0_START_POSITION_X, LEVEL0_START_POSITION_X, LEVEL0_START_POSITION_X},  // x
    {LEVEL0_START_POSITION_Y, LEVEL0_START_POSITION_Y, LEVEL0_START_POSITION_Y},  // y
    {SPRITE_CHARACTER_IDLE_W, SPRITE_CHARACTER_IDLE_W, SPRITE_CHARACTER_IDLE_W},  // w
    {SPRITE_CHARACTER_IDLE_H, SPRITE_CHARACTER_IDLE_H, SPRITE_CHARACTER_IDLE_H},  // h
    0                       // grid
  }, // DrawableEntity
  cs_idle,
  cs_idle,
  &_character_animation,
  {0, 0}, // vel
  3,      // HP
  0
};

Character _character;

void
initCharacter()
{
  cpct_memcpy ((void*)&_character, (void*)&_character_template, sizeof(Character));
}

u8
isGround()
{
  u8* tile = getTilePtr(_character.e.x[0], _character.e.y[0] + _character.e.h[0]);
  if(*(tile + 2) <= 5) 
    return 1;
  else
    return 0;
}

void
checkEmeraldCollision()
{
  u8* tile = getTilePtr(_character.e.x[0]+(_character.e.w[0]/2), _character.e.y[0]);
  if(*tile == EMERALD_TILE_ID_2 || *tile == EMERALD_TILE_ID_3)
  {
    incrementScore();
    if(*tile == EMERALD_TILE_ID_2)
      tile -= 40;
    else
      tile -= 41;

    removeEmerald(tile);
  }
  tile = getTilePtr(_character.e.x[0]+(_character.e.w[0]/2), _character.e.y[0]+_character.e.h[0]);
  if(*tile == EMERALD_TILE_ID_0 || *tile == EMERALD_TILE_ID_1)
  {
    incrementScore();
    if(*tile == EMERALD_TILE_ID_1)
      --tile;

    removeEmerald(tile);
  }
  if(_character.anim->side == as_right)
  {
    tile = getTilePtr(_character.e.x[0]+_character.e.w[0], _character.e.y[0]+(_character.e.h[0]/2));
    if(*tile == EMERALD_TILE_ID_0 || *tile == EMERALD_TILE_ID_2)
    {
      incrementScore();
      if(*tile == EMERALD_TILE_ID_2)
        tile -= 40;
      
      removeEmerald(tile);
    }
  }
  else
  {
    tile = getTilePtr(_character.e.x[0]+_character.e.w[0], _character.e.y[0]+(_character.e.h[0]/2));
    if(*tile == EMERALD_TILE_ID_1 || *tile == EMERALD_TILE_ID_3)
    {
      incrementScore();
      if(*tile == EMERALD_TILE_ID_1)
        --tile;
      else
        tile -= 41;

      removeEmerald(tile);
    }
  }
}

void
characterController()
{
  Character* c = &_character;
  cpct_scanKeyboard_f();
  if(cpct_isAnyKeyPressed_f()) {
    if(cpct_isKeyPressed(Key_CursorRight)) // walk right
    {
      c->vel.x       += 1;
      c->anim->side   = as_right; // looking right      
      c->e.draw      = 2;
      if(isGround())
       c->status = cs_walk;
    } else if(cpct_isKeyPressed(Key_CursorLeft)) // walk left
    {
      c->vel.x       -= 1;
      c->anim->side   = as_left; // looking left
      c->e.draw      = 2;
      if(isGround())
       c->status = cs_walk;
    }else if(cpct_isKeyPressed(Key_A) && isGround() && c->status != cs_attack)
    {
      c->status   = cs_attack;
      c->e.draw  = 2;    }
    if(cpct_isKeyPressed(Key_Space)) // jump
    {
      if(c->lstatus != cs_jump && isGround()) {
        c->status  = cs_jump;
      }
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
  if(c->status != c->lstatus) {
    switch(c->status) {
      case cs_idle:
        c->anim->frames     = (AnimationFrame**)_character_anim_idle;
        c->anim->numframes  = CHARACTER_IDLE_ANIM_FRAMES;
        c->anim->status     = as_play;
        break;
      case cs_walk:
        c->anim->frames     = (AnimationFrame**)_character_anim_walk;
        c->anim->numframes  = CHARACTER_WALK_ANIM_FRAMES;
        c->anim->status     = as_cycle;
        break;
      case cs_jump:
        c->anim->frames     = (AnimationFrame**)_character_anim_jump;
        c->anim->numframes  = CHARACTER_JUMP_ANIM_FRAMES;
        c->anim->status     = as_play;
        break;
      case cs_attack:
        c->anim->frames     = (AnimationFrame**)_character_anim_attack;
        c->anim->numframes  = CHARACTER_ATTACK_ANIM_FRAMES;
        c->anim->status     = as_play;
        break;
    }
    c->anim->frame_idx = 0;
    frame = c->anim->frames[c->anim->frame_idx];
    c->anim->time = frame->time;
  }  
  
  c->e.w[0]    = frame->w;
  c->e.h[0]    = frame->h;
  c->e.sprite  = frame->sprite;
}

void 
handleMapLimits()
{
  Character* c = &_character;

  if(c->e.x[0] <= 0) { // left limit
    if(prevLevelMap())
      c->e.x[0] = SCREEN_BYTES_WIDTH - c->e.w[0] - 2;
    else
      c->e.x[0] = 2;
  } else if((c->e.x[0] + c->e.w[0]) >= SCREEN_BYTES_WIDTH) {  // right limit
    if(nextLevelMap())
      c->e.x[0] = 2;
    else
      c->e.x[0] = SCREEN_BYTES_WIDTH - c->e.w[0] - 2;
  }
  if(c->e.y[0] <= 40) // top limit
  {
    c->e.y[0] = 40;
  }
}

void jumpAndGravity()
{
  Character *c = &_character;
  if(c->status == cs_jump) {
    c->vel.y -= 1;
    if(c->vel.y <= -8)
      c->status = cs_fall;
    c->e.draw = 2;
  }

  if(!isGround() && c->status != cs_jump) {
    ++c->vel.y;
    if(c->vel.y > 4)
      c->vel.y = 4;
    c->e.draw = 2;
  }
}

void attack()
{
  // u8* pvm = cpct_getScreenPtr(_backBuffer, 40, 0);
  // Character* c = &_character;
  // Collision col;
  // Skeleton *s = &_skeleton_template;
  // if(c->anim->status == as_end)
  // {
  //   c->status = cs_endattack;
  // }
  // else
  // {
  //   col.x[0]  =   c->e.x[0] + 8;
  //   col.y[0]  =   c->e.y[0];
  //   col.w[0]  =   4;
  //   col.h[0]  =   c->e.h[0];
  //   col.x[1]  =   s->e.x[0];
  //   col.y[1]  =   s->e.y[0];
  //   col.w[1]  =   s->e.w[0];
  //   col.h[1]  =   s->e.h[0];
  //   col.collision = 0;
  //   checkCollision(&col);
  //   if(col.collision)
  //   {
  //     s->status = ss_hurt;
  //   }
  // }
}

void
updateCharacter()
{
  Character* c    = &_character;
  c->vel.x        = 0;
  c->lstatus  = c->status;

  characterController();

  jumpAndGravity();

  c->e.x[0] += c->vel.x;
  c->e.y[0] += c->vel.y;
  
  if(isGround())
  {
    c->e.y[0] = (c->e.y[0] & 0b11111100);
    c->vel.y   = 0;
    if(c->vel.x == 0)
    {        
      if(c->lstatus != cs_idle && c->status != cs_attack)
      {
       c->status = cs_idle;
       c->e.draw += 2;
      }
    }
  }else if(c->status != cs_jump)
  {
    c->status = cs_fall;
  }

  updateCharacterAnimation();

  // if(c->status == cs_attack)
  //   attack(); 
  
  if(c->e.draw)
  {
    checkEmeraldCollision();
    setGrid(&c->e);
  }

  if((c->e.y[0] + c->e.h[0]) >= 190)
    c->status = cs_dead;

  handleMapLimits();

}

void
drawCharacter()
{
  Character* c = &_character;
  if(c->e.draw)
  {    
    eraseEntityTileBox(&c->e);
    drawEntity(&c->e);
    updateDrawableEntity(&c->e);
  }  
}

void hurtCharacter()
{
  Character* c = &_character;
  if(c->anim->side == as_left)
    c->e.x[0] +=  2;
  else if(c->e.x[0] < 4)
    c->e.x[0] = 0;
  else
    c->e.x[0] -= 2;

  --c->hp;
  if(c->hp)
  {
    c->e.draw = 2;
    handleMapLimits();
  }
  else
  {
    c->status = cs_dead;
  }

}