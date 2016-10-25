#include "bat.h"
#include "sprites/bat.h"
#include "../game.h"
#include "../draw/draw.h"
#include "../character/character.h"
#include "../utils/utils.h"
#define NUM_FRAMES		    6
#define ANIM_FLY_FRAMES	  2 
#define ANIM_DEAD_FRAMES  1
#define SPRITE_FLY_0_L    sprite_bat_0
#define SPRITE_FLY_0_R	  sprite_bat_1
#define SPRITE_FLY_1_L	  sprite_bat_2
#define SPRITE_FLY_1_R	  sprite_bat_3
#define SPRITE_DEAD_L     sprite_bat_4
#define SPRITE_DEAD_R     sprite_bat_5
#define SPRITE_W          SPRITE_BAT_0_W
#define SPRITE_H          SPRITE_BAT_0_H
#define ANIM_FLY_TIME     2
#define ANIM_DEAD_TIME    5
////////////////////////////////////////////////////////////////////////////////////////////////////
// Animation
////////////////////////////////////////////////////////////////////////////////////////////////////
const AnimationFrame _bat_frames[NUM_FRAMES] = {
  // sprite, width bytes, height bytes, time, look
  { SPRITE_FLY_0_L, SPRITE_W, SPRITE_H, ANIM_FLY_TIME,  as_left	 },
  { SPRITE_FLY_1_L, SPRITE_W, SPRITE_H, ANIM_FLY_TIME,  as_left	 },
  { SPRITE_FLY_0_R, SPRITE_W, SPRITE_H, ANIM_FLY_TIME,  as_right },
  { SPRITE_FLY_1_R, SPRITE_W, SPRITE_H, ANIM_FLY_TIME,  as_right },
  { SPRITE_DEAD_L,  SPRITE_W, SPRITE_H, ANIM_DEAD_TIME, as_left  },
  { SPRITE_DEAD_R,  SPRITE_W, SPRITE_H, ANIM_DEAD_TIME, as_right }
};

AnimationFrame* const _bat_anim_fly_l[ANIM_FLY_FRAMES] = { 
  &_bat_frames[0], &_bat_frames[1] 
};
AnimationFrame* const _bat_anim_fly_r[ANIM_FLY_FRAMES] = { 
  &_bat_frames[2], &_bat_frames[3] 
};
AnimationFrame* const _bat_anim_dead_l[ANIM_DEAD_FRAMES] = { 
  &_bat_frames[4]
};
AnimationFrame* const _bat_anim_dead_r[ANIM_DEAD_FRAMES] = { 
  &_bat_frames[5]
};
////////////////////////////////////////////////////////////////////////////////////////////////////
// THE BAT
////////////////////////////////////////////////////////////////////////////////////////////////////
const Bat _bat_template = 
{
  {
    SPRITE_FLY_0_L,        	// sprite
    2,                      // draw
    {0,	0,	0},         // x
    {0,	0,	0},  	    // y
    { SPRITE_W, SPRITE_W, SPRITE_W },  // w
    { SPRITE_H, SPRITE_H, SPRITE_H },  // h
    0                       // grid
  }, // Entity
  { _bat_anim_fly_l, 0, ANIM_FLY_FRAMES, as_cycle, 0, as_left },   // Animation
  bs_fly,                  	// SkeletonStatus
  bs_fly,                  	// Last SkeletonStatus
  1,                        // hp
};
////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONSSS
////////////////////////////////////////////////////////////////////////////////////////////////////
void updateBatAnimation(Bat* b);
////////////////////////////////////////////////////////////////////////////////////////////////////
void 
chooseBatAnimation(Bat* b) 
{
  AnimationFrame* frame = b->anim.frames[b->anim.frame_idx];
  
  switch(b->status)
  {
    case bs_fly:
      if(b->anim.side == as_left)
        b->anim.frames = (AnimationFrame**)_bat_anim_fly_l;
      else
        b->anim.frames = (AnimationFrame**)_bat_anim_fly_r;
      break;
    case bs_dead:
      if(b->anim.side == as_left)
        b->anim.frames = (AnimationFrame**)_bat_anim_dead_l;
      else
        b->anim.frames = (AnimationFrame**)_bat_anim_dead_r;
      break;    
  }
  b->e.sprite = frame->sprite;
  b->e.w[0]   = frame->w;
  b->e.h[0]   = frame->h;
}

void
collisionBat(Bat* b)
{
  Collision* col = &_col;
  setGrid(&b->e);
  if(b->e.grid == _character.e.grid)  
  {
    col->x[0] = b->e.x[0];
    col->y[0] = b->e.y[0];  
    col->w[0] = SPRITE_W;
    col->h[0] = SPRITE_H;
    col->x[1] = _character.e.x[0];
    col->y[1] = _character.e.y[0];
    col->w[1] = _character.e.w[0];
    col->h[1] = _character.e.h[0];
    checkCollision(col);
    if(col->collision && _character.status != cs_hurt)
    {
      doCharacterAction(cs_hurt);
    }
  }

}

void 
moveBat(Bat* b) __z88dk_fastcall
{
  if(b->anim.side == as_left)
  {
    if(b->e.x[0] >= 1)
    {
      --b->e.x[0];
    }
    else
    {
      b->anim.side = as_right;  
      updateBatAnimation(b);
    }    
  }
  else
  {
    if(b->e.x[0] < 73)
    {
      ++b->e.x[0];      
    }
    else
    {
      b->anim.side = as_left;
      updateBatAnimation(b);
    }    
  }
  b->e.draw = 2;
}

void 
updateBatAnimation(Bat* b)
{
  AnimationFrame* frame;  

  updateAnimation(&b->anim);
  frame = b->anim.frames[b->anim.frame_idx];

  if(b->status != b->lstatus)
  {
    chooseBatAnimation(b);
    switch(b->status)
    {
      case bs_fly:
        b->anim.numframes   = ANIM_FLY_FRAMES;
        b->anim.status      = as_cycle;
        break;
      case bs_dead:
        b->anim.numframes   = ANIM_DEAD_FRAMES;
        b->anim.status      = as_play;
        break;
    }
    b->anim.frame_idx = 0;
    frame             = b->anim.frames[b->anim.frame_idx];
    b->anim.time      = frame->time;     
  }else if(b->anim.side != frame->side)
  {
    chooseBatAnimation(b);
  }
  b->e.sprite   = frame->sprite;
  b->e.w[0]     = frame->w;
  b->e.h[0]     = frame->h;  
}

void
updateBat()
{
  Game* g = &_game;
  BatArray* b = &g->lvl->m->b;
  Bat* current;
  u8 dist;

  if(b->num)
  {
    current = b->current + b->idx;
    if(current->status != bs_dead)
    {
      moveBat(current);
      dist = distanceToCharacter(&current->e);        
      if(dist <= b->min_dist)
      {
        b->min_dist = dist;
        b->nearest  = b->current + b->idx;
        collisionBat(current);
      }
      updateBatAnimation(current);
    }
    else
    {
      if(current->anim.time == 0)
      {
        eraseEntityBuffersSolidBox(&current->e);
      }
      else
      {
        updateBatAnimation(current);
        current->e.draw = 2;
      }
    }

    current->lstatus  = current->status;

    ++b->idx;
    if(b->idx == b->num)
      b->idx = 0;   
  }
}

void 
killBat(Bat* b) __z88dk_fastcall
{
  b->status = bs_dead;
  updateBatAnimation(b);
}

void
drawBats()
{
  Game *g       = &_game;
  BatArray* ba  = &g->lvl->m->b;
  Bat* current  = ba->current + ba->num;
  if(ba->num)
  {
    while(current != ba->current)
    {
      --current;
      if(current->e.draw)
      {
        eraseEntitySolidBox(&current->e);
        drawEntity(&current->e);
        updateDrawableEntity(&current->e);
      }
    }
  }
}