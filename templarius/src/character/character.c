#include "character.h"
#include "sprites/character.h"
#include "sprites/character_attack.h"
#include "../utils/utils.h"
#include "../enemies/skeleton.h"
#include "../game.h"
#include "../hud/hud.h"
#include "../draw/draw.h"

#define MAX_JUMP_H -12
#define JUMP_FORCE 4
#define NUM_FRAMES        14
#define ANIM_IDLE_FRAMES  1
#define ANIM_WALK_FRAMES  4
#define ANIM_JUMP_FRAMES  1
#define ANIM_ATK_FRAMES   1
#define ANIM_HURT_FRAMES  1
#define SPRITE_W          SPRITE_CHARACTER_00_W
#define SPRITE_H          SPRITE_CHARACTER_00_H
#define SPRITE_ATK_W      SPRITE_CHARACTER_ATTACK_0_W
#define SPRITE_ATK_H      SPRITE_CHARACTER_ATTACK_0_H

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Character animations
///////////////////////////////////////////////////////////////////////////////////////////////////////
const AnimationFrame _character_frames[NUM_FRAMES] = {
  // sprite, width bytes, height bytes, time, look  
  { sprite_character_01,        SPRITE_W,     SPRITE_H,  6, as_right }, // WALK R
  { sprite_character_02,        SPRITE_W,     SPRITE_H,  6, as_right },
  { sprite_character_03,        SPRITE_W,     SPRITE_H,  6, as_right }, 
  { sprite_character_00,        SPRITE_W,     SPRITE_H,  1, as_right }, // IDLE R  
  { sprite_character_04,        SPRITE_W,     SPRITE_H,  1, as_right }, // JUMP R
  { sprite_character_07,        SPRITE_W,     SPRITE_H,  6, as_left  }, // WALK L
  { sprite_character_08,        SPRITE_W,     SPRITE_H,  3, as_left  },
  { sprite_character_09,        SPRITE_W,     SPRITE_H,  3, as_left  },
  { sprite_character_06,        SPRITE_W,     SPRITE_H,  1, as_left  }, // IDLE L
  { sprite_character_10,        SPRITE_W,     SPRITE_H,  1, as_left  }, // JUMP L
  { sprite_character_attack_0,  SPRITE_ATK_W, SPRITE_CHARACTER_ATTACK_0_H, 10, as_right  },
  { sprite_character_attack_1,  SPRITE_ATK_W, SPRITE_CHARACTER_ATTACK_0_H, 10, as_left   },
  { sprite_character_05,        SPRITE_W,     SPRITE_H,  10, as_right },  // HURT R
  { sprite_character_11,        SPRITE_W,     SPRITE_H,  10, as_left  }   // HURT L
};
// walk
AnimationFrame* const _character_anim_walk_r[4] = { 
  &_character_frames[0], &_character_frames[1], &_character_frames[0], &_character_frames[2] 
};

AnimationFrame* const _character_anim_walk_l[4] = { 
  &_character_frames[5], &_character_frames[6], &_character_frames[5], &_character_frames[7] 
};
// idle
AnimationFrame* const _character_anim_idle_r[ANIM_IDLE_FRAMES] = { 
  &_character_frames[3] 
};
AnimationFrame* const _character_anim_idle_l[ANIM_IDLE_FRAMES] = { 
  &_character_frames[8] 
};
// jump
AnimationFrame* const _character_anim_jump_r[ANIM_JUMP_FRAMES] = { &_character_frames[4] };
AnimationFrame* const _character_anim_jump_l[ANIM_JUMP_FRAMES] = { &_character_frames[9] };
// attack
AnimationFrame* const _character_anim_attack_r[ANIM_ATK_FRAMES] = { &_character_frames[10] };
AnimationFrame* const _character_anim_attack_l[ANIM_ATK_FRAMES] = { &_character_frames[11] };
// hurt
AnimationFrame* const _character_anim_hurt_r[ANIM_HURT_FRAMES] = { &_character_frames[12] };
AnimationFrame* const _character_anim_hurt_l[ANIM_HURT_FRAMES] = { &_character_frames[13] };
// start animation
const Animation _character_animation = { _character_anim_idle_r, 0, 1, as_play, 0, as_right };
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Character template
///////////////////////////////////////////////////////////////////////////////////////////////////////
const Character _character_template = 
{
  {
    sprite_character_00,  // sprite
    2,                      // draw
    {4, 4, 4},              // x
    {160, 160, 160},        // y
    {SPRITE_W, SPRITE_W, SPRITE_W},  // w
    {SPRITE_H, SPRITE_H, SPRITE_H},  // h
    0                       // grid
  }, // DrawableEntity
  cs_idle,
  cs_idle,
  &_character_animation,
  {0, 0}, // vel
  3,      // HP
  1
};
///////////////////////////////////////////////////////////////////////////////////////////////////////
Character _character;
///////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////////
void doCharacterAction(CharacterStatus status) __z88dk_fastcall;
void attackCharacter();
///////////////////////////////////////////////////////////////////////////////////////////////////////
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
      c->vel.x       = 1;
      c->anim->side  = as_right; // looking right      
      doCharacterAction(cs_walk);
    } else if(cpct_isKeyPressed(Key_CursorLeft)) // walk left
    {
      c->vel.x       = -1;
      c->anim->side  = as_left; // looking left
      doCharacterAction(cs_walk);
    }else if(cpct_isKeyPressed(Key_A) && c->ground && c->lstatus != cs_attack)
    {
      c->status   = cs_attack;
      c->e.draw  = 2;    
    }
    if(cpct_isKeyPressed(Key_Space)) // jump
    {
      doCharacterAction(cs_jump);
    }
  }
}

void 
chooseCharacterAnimation()
{
  Character* c = &_character;
  AnimationFrame* frame;
  frame = c->anim->frames[c->anim->frame_idx];
  if(c->lstatus == cs_attack && frame->side == as_left)
  {
    c->e.x[0] += 5;
  }
  switch(c->status) { 
    case cs_walk:
      if(c->anim->side == as_left)
        c->anim->frames = (AnimationFrame**)_character_anim_walk_l;
      else
        c->anim->frames = (AnimationFrame**)_character_anim_walk_r;
      c->anim->numframes = ANIM_WALK_FRAMES;
      c->anim->status    = as_cycle;
      break;
    case cs_jump:
      if(c->anim->side == as_left)
        c->anim->frames = (AnimationFrame**)_character_anim_jump_l;
      else
        c->anim->frames = (AnimationFrame**)_character_anim_jump_r;
      c->anim->numframes = ANIM_JUMP_FRAMES;
      c->anim->status    = as_play;
      break;
    case cs_attack:
      if(c->anim->side == as_left)
      {
        c->anim->frames = (AnimationFrame**)_character_anim_attack_l;
        c->e.x[0] -= 5;
      }
      else
      {
        c->anim->frames = (AnimationFrame**)_character_anim_attack_r;
      }
      c->anim->numframes = ANIM_ATK_FRAMES;
      c->anim->status    = as_play;
      break;
    case cs_hurt:
      if(c->anim->side == as_left)
        c->anim->frames = (AnimationFrame**)_character_anim_hurt_l;
      else
        c->anim->frames = (AnimationFrame**)_character_anim_hurt_r;
      c->anim->numframes = ANIM_HURT_FRAMES;
      c->anim->status    = as_play;
      break;
    case cs_idle:
      if(c->anim->side == as_left)
        c->anim->frames = (AnimationFrame**)_character_anim_idle_l;
      else
        c->anim->frames = (AnimationFrame**)_character_anim_idle_r;
      c->anim->numframes = ANIM_IDLE_FRAMES;
      c->anim->status    = as_play;
      break;         
  }
  frame = c->anim->frames[c->anim->frame_idx];
  c->e.sprite  = frame->sprite;
}

void
updateCharacterAnimation()
{
  Character* c = &_character;
  AnimationFrame* frame;

  updateAnimation(c->anim);
  frame = c->anim->frames[c->anim->frame_idx];
  if(c->status != c->lstatus) {
    chooseCharacterAnimation();

    c->anim->frame_idx = 0;
    frame = c->anim->frames[c->anim->frame_idx];
    c->anim->time = frame->time;
    c->e.w[0] = frame->w;
    c->e.h[0] = frame->h;
  }else if(c->anim->side != frame->side)
  {
    chooseCharacterAnimation();
    frame = c->anim->frames[c->anim->frame_idx];
  } 
  
  c->e.sprite  = frame->sprite;
}

void 
handleMapLimitsLevel1()
{
  Character* c = &_character;

  if(c->e.x[0] <= 0) { // left limit
    if(prevMap())
      c->e.x[0] = SCREEN_BYTES_WIDTH - c->e.w[0] - 2;
    else
      c->e.x[0] = 2;
  } else if((c->e.x[0] + c->e.w[0]) >= SCREEN_BYTES_WIDTH) {  // right limit
    nextMap();
    c->e.x[0] = 2;
  }
  if(c->e.y[0] <= 40) // top limit
  {
    c->e.y[0] = 40;
  }
}

void 
handleMapLimitsLevel2()
{
  Character* c = &_character;

  if(c->e.x[0] <= 0) { // left limit
      c->e.x[0] = 2;
  } else if((c->e.x[0] + c->e.w[0]) >= SCREEN_BYTES_WIDTH) {  // right limit
      c->e.x[0] = SCREEN_BYTES_WIDTH - c->e.w[0] - 2;
  }
  if(c->e.y[0] <= 40) // top limit
  {
    nextMap();    
    c->e.y[0] = 100;
  }
}


/*void jumpAndGravity()
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
}*/

//void attack()
//{
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
//}

void
gravity()
{
  Character *c = &_character;
  if(!c->ground) {
    ++c->vel.y;
    if(c->vel.y > 4)
      c->vel.y = 4;
    c->e.draw = 2;
  }  
}

void
jumpCharacter()
{
  Character *c = &_character;
  if(c->status == cs_jump) {
    c->vel.y -= 1;
    if(c->vel.y <= -8)
      c->status = cs_fall;
    c->e.draw = 2;
  }
}

void
walkCharacter()
{
  Character *c = &_character;
  c->e.x[0] += c->vel.x;
  c->e.draw = 2;
  if(c->ground)   // only if its in ground its walking, else its moving on air
    c->status = cs_walk;
  
  updateCharacterAnimation();
}

void
doCharacterAction(CharacterStatus status) __z88dk_fastcall
{
  Character* c = &_character;
  switch(status)
  {
    case cs_walk:
      walkCharacter();
      break;
    case cs_jump:
      jumpCharacter();      
      break;
    case cs_attack:
      attackCharacter();
      break;
  }
}

void attackCharacter()
{}

void
updateCharacter()
{
  Character* c    = &_character;    
  
  characterController();

  gravity();

  if(c->ground = isGround())
  {
    c->e.y[0] = (c->e.y[0] & 0b11111100);
    c->vel.y  = 0;    
  }

/*  jumpAndGravity();

  c->e.x[0] += c->vel.x;
  c->e.y[0] += c->vel.y;

  updateCharacterAnimation();
*/
  
/*  if(isGround())
  {
    c->e.y[0] = (c->e.y[0] & 0b11111100);
    c->vel.y   = 0;
    if(c->vel.x == 0)
    {        
      if(c->lstatus != cs_idle)
      {
       c->status = cs_idle;
       c->e.draw += 2;
      }
    }
  }else if(c->status != cs_jump)
  {
    c->status = cs_fall;
  }

  

  c->lstatus  = c->status;  

  //if(c->status == cs_attack && c->stat) 

  //attack(); 

  if((c->e.y[0] + c->e.h[0]) >= 190)
    c->status = cs_dead;


  if(c->e.draw)
  {
    checkEmeraldCollision();
    setGrid(&c->e);
  }

  handleMapLimitsLevel1();
*/
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
  decrementLifeHUD();
  if(c->anim->side == as_left)
    c->e.x[0] +=  4;
  else if(c->e.x[0] < 4)
    c->e.x[0] = 0;
  else
    c->e.x[0] -= 4;  
  
  if(--c->hp)
  {
    c->e.draw = 2;
    c->status = cs_hurt;
    handleMapLimitsLevel1();
  }
  else
  {
    c->status = cs_dead;
  }

}