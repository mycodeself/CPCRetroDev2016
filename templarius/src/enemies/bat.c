#include "bat.h"
#include "sprites/bat.h"
#include "../game.h"
#include "../draw/draw.h"

#define NUM_FRAMES		4
#define FLY_ANIM_FRAMES	2
#define SPRITE_FLY_0_L	sprite_bat_0
#define SPRITE_FLY_0_R	sprite_bat_1
#define SPRITE_FLY_1_L	sprite_bat_2
#define SPRITE_FLY_1_R	sprite_bat_3
#define SPRITE_W 		SPRITE_BAT_0_W
#define SPRITE_H 		SPRITE_BAT_0_H

const AnimationFrame _bat_frames[NUM_FRAMES] = {
  // sprite, width bytes, height bytes, time, look
  { SPRITE_FLY_0_L, SPRITE_W, SPRITE_H, 8, as_left 	},
  { SPRITE_FLY_1_L, SPRITE_W, SPRITE_H, 8, as_left 	},
  { SPRITE_FLY_0_R, SPRITE_W, SPRITE_H, 8, as_right	},
  { SPRITE_FLY_1_L, SPRITE_W, SPRITE_H, 8, as_right }
};

AnimationFrame* const _bat_anim_fly_l[FLY_ANIM_FRAMES] = { &_bat_frames[0], &_bat_frames[1] };
AnimationFrame* const _bat_anim_fly_r[FLY_ANIM_FRAMES] = { &_bat_frames[2], &_bat_frames[3] };
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
  { _bat_anim_fly_l, 0, FLY_ANIM_FRAMES, as_cycle, 0, as_left },   // Animation
  bs_fly,                  	// SkeletonStatus
  bs_fly,                  	// Last SkeletonStatus
  1,                        // hp
};
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
    case bs_hurt:
      break;
    case bs_dead:
      break;
  }
  
  b->e.sprite = frame->sprite;
  b->e.w[0]   = frame->w;
  b->e.h[0]   = frame->h;
}

void 
updateBatAnimation(Bat* b)
{
  AnimationFrame* frame;  

  updateAnimation(&b->anim);
  if(b->status != b->lstatus)
  {
    chooseBatAnimation(b);
    switch(b->status)
    {
      case bs_fly:
        b->anim.numframes  = FLY_ANIM_FRAMES;
        b->anim.status     = as_cycle;
        break;
      case bs_hurt:
        break;
      case bs_dead:
        break;
    }
    b->anim.frame_idx = 0;
    b->anim.time      = 0;
  }  
  frame         = b->anim.frames[b->anim.frame_idx];
  b->e.sprite   = frame->sprite;
  b->e.w[0]     = frame->w;
  b->e.h[0]     = frame->h;
}

void
updateBat()
{
  Game* g = &_game;
  BatArray* b = &g->lvl->lm->b;
  Bat* current;

  current = b->current + b->idx;

  current->e.draw = 2;
  updateBatAnimation(current);

  current->lstatus  = current->status;

  ++b->idx;
  if(b->idx == b->num)
    b->idx = 0;   
}

void
drawBats()
{
  Game *g       = &_game;
  BatArray* ba  = &g->lvl->lm->b;
  Bat* current  = ba->current + ba->num;
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