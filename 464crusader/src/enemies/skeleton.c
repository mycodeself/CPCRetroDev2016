/*  
 *
 *  This file is part of 464 Crusader, game for Amstrad CPC 464.
 *
 *  464 Crusader is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  464 Crusader is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 464 Crusader.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "skeleton.h"
#include "sprites/skeleton.h"
#include "sprites/skeleton_attack.h"
#include "../utils/utils.h"
#include "../game.h"
#include "../physics/physics.h"
#include "../character/character.h"
#include "../draw/draw.h"

#define NUM_FRAMES          10
#define WALK_ANIM_FRAMES    2
#define HURT_ANIM_FRAMES    1
#define DEAD_ANIM_FRAMES    1
#define ATTACK_ANIM_FRAMES  1
#define SPRITE_W          SPRITE_SKELETON_0_W
#define SPRITE_H          SPRITE_SKELETON_0_H
#define SPRITE_ATTACK_W   SPRITE_SKELETON_ATTACK_0_W
#define SPRITE_ATTACK_H   SPRITE_SKELETON_ATTACK_0_H
#define SPRITE_WALK_0_L   sprite_skeleton_0
#define SPRITE_WALK_0_R   sprite_skeleton_1
#define SPRITE_WALK_1_L   sprite_skeleton_2
#define SPRITE_WALK_1_R   sprite_skeleton_3
#define SPRITE_HURT_L     sprite_skeleton_4
#define SPRITE_HURT_R     sprite_skeleton_5
#define SPRITE_DEAD_L     sprite_skeleton_6
#define SPRITE_DEAD_R     sprite_skeleton_7
#define SPRITE_ATTACK_L   sprite_skeleton_attack_1
#define SPRITE_ATTACK_R   sprite_skeleton_attack_0
#define ANIM_WALK_0_TIME  3
#define ANIM_HURT_TIME    10
#define ANIM_DEAD_TIME    3
#define ANIM_ATTACK_TIME  6                
// Animation Frames
const AnimationFrame _skeleton_frames[NUM_FRAMES] = {
  // sprite, width bytes, height bytes, time, look
  { SPRITE_WALK_0_L,  SPRITE_W,         SPRITE_H,         ANIM_WALK_0_TIME, as_left  },
  { SPRITE_WALK_1_L,  SPRITE_W,         SPRITE_H,         ANIM_WALK_0_TIME, as_left  },
  { SPRITE_HURT_L,    SPRITE_W,         SPRITE_H,         ANIM_HURT_TIME,   as_left  },
  { SPRITE_DEAD_L,    SPRITE_W,         SPRITE_H,         ANIM_DEAD_TIME,   as_left  },
  { SPRITE_WALK_0_R,  SPRITE_W,         SPRITE_H,         ANIM_WALK_0_TIME, as_right },
  { SPRITE_WALK_1_R,  SPRITE_W,         SPRITE_H,         ANIM_WALK_0_TIME, as_right },
  { SPRITE_HURT_R,    SPRITE_W,         SPRITE_H,         ANIM_HURT_TIME,   as_right },
  { SPRITE_DEAD_R,    SPRITE_W,         SPRITE_H,         ANIM_DEAD_TIME,   as_right },
  { SPRITE_ATTACK_L,  SPRITE_ATTACK_W,  SPRITE_ATTACK_H,  ANIM_ATTACK_TIME, as_left  },
  { SPRITE_ATTACK_R,  SPRITE_ATTACK_W,  SPRITE_ATTACK_H,  ANIM_ATTACK_TIME, as_right }
};

// Left side animations
AnimationFrame* const _skeleton_anim_walk_l[WALK_ANIM_FRAMES] = {
  &_skeleton_frames[0], &_skeleton_frames[1]
};
AnimationFrame* const _skeleton_anim_hurt_l[HURT_ANIM_FRAMES] = {
  &_skeleton_frames[2]
};
AnimationFrame* const _skeleton_anim_dead_l[DEAD_ANIM_FRAMES] = {
  &_skeleton_frames[3]
};
AnimationFrame* const _skeleton_anim_attack_l[ATTACK_ANIM_FRAMES] = {
  &_skeleton_frames[8]
};
// Right side animations
AnimationFrame* const _skeleton_anim_walk_r[WALK_ANIM_FRAMES] = {
  &_skeleton_frames[4], &_skeleton_frames[5]
};
AnimationFrame* const _skeleton_anim_hurt_r[HURT_ANIM_FRAMES] = {
  &_skeleton_frames[6]
};
AnimationFrame* const _skeleton_anim_dead_r[DEAD_ANIM_FRAMES] = {
  &_skeleton_frames[7]
};
AnimationFrame* const _skeleton_anim_attack_r[ATTACK_ANIM_FRAMES] = {
  &_skeleton_frames[9]
};
////////////////////////////////////////////////////////////////////////////////////////////////////
const Skeleton _skeleton_template = 
{
  {
    SPRITE_WALK_1_L,        // sprite
    2,                      // draw
    {60,	 60,   60},       // x
    {164,	164,	164},  	    // y
    { SPRITE_W, SPRITE_W, SPRITE_W },  // w
    { SPRITE_H, SPRITE_H, SPRITE_H },  // h
    0                       // grid
  }, // DrawableEntity
  { _skeleton_anim_walk_l, 0, WALK_ANIM_FRAMES, as_cycle, 0, as_left },   // Animation
  ss_walk,                  // SkeletonStatus
  ss_walk,                  // Last SkeletonStatus
  2,                        // hp
};
////////////////////////////////////////////////////////////////////////////////////////////////////
// THE PARTY
////////////////////////////////////////////////////////////////////////////////////////////////////
void chooseAnimationSkeleton(Skeleton* s) 
{
  AnimationFrame* frame;
  
  switch(s->status)
  {
    case ss_walk:
      if(s->anim.side == as_left)
        s->anim.frames    = (AnimationFrame**)_skeleton_anim_walk_l;
      else
        s->anim.frames    = (AnimationFrame**)_skeleton_anim_walk_r;
      break;
    case ss_hurt:
      if(s->anim.side == as_left)
        s->anim.frames    = (AnimationFrame**)_skeleton_anim_hurt_l;
      else
        s->anim.frames    = (AnimationFrame**)_skeleton_anim_hurt_r;
      break;
    case ss_dying:
      if(s->anim.side == as_left)
        s->anim.frames    = (AnimationFrame**)_skeleton_anim_dead_l;
      else
        s->anim.frames    = (AnimationFrame**)_skeleton_anim_dead_r;
      break;
    case ss_attack:
      if(s->anim.side == as_left)
        s->anim.frames    = (AnimationFrame**)_skeleton_anim_attack_l;
      else
        s->anim.frames    = (AnimationFrame**)_skeleton_anim_attack_r;  
      break;
  }
  frame         = s->anim.frames[s->anim.frame_idx];
  s->e.sprite   = frame->sprite;
  s->e.w[0]     = frame->w;
  s->e.h[0]     = frame->h;
}

void updateSkeletonAnimation(Skeleton* s) 
{
  AnimationFrame* frame;  

  updateAnimation(&s->anim);
  frame = s->anim.frames[s->anim.frame_idx];
  if(s->status != s->lstatus)
  {
    chooseAnimationSkeleton(s);
    switch(s->status)
    {
      case ss_walk:
        s->anim.numframes  = WALK_ANIM_FRAMES;
        s->anim.status     = as_cycle;
        break;
      case ss_hurt:
        s->anim.numframes  = HURT_ANIM_FRAMES;
        s->anim.status     = as_play;
        break;
      case ss_dying:
        s->anim.numframes  = HURT_ANIM_FRAMES;
        s->anim.status     = as_play;
        break;
      case ss_attack:
        s->anim.numframes  = ATTACK_ANIM_FRAMES;
        s->anim.status     = as_play;
        break;
    }
    s->anim.frame_idx = 0;
    frame = s->anim.frames[s->anim.frame_idx];
    s->anim.time = frame->time;
  }  
  s->e.sprite  = frame->sprite;
  s->e.w[0]    = frame->w;
  s->e.h[0]    = frame->h;
}

u8 
endGround(Skeleton* s) 
{
  u8* tile;
  if(s->anim.side == as_right)
    tile = getTilePtr(s->e.x[0]+s->e.w[0], s->e.y[0]+s->e.h[0]);
  else
    tile = getTilePtr(s->e.x[0], s->e.y[0]+s->e.h[0]);

  if(*(tile) <= 5)
    return 0;
  return 1;
}


void
attackSkeleton(Skeleton* s)
{  
  if(s->status != ss_attack && s->lstatus != ss_attack)
  {
    Collision* col = &_col;
    if(s->anim.side == as_right)
      col->x[0] = s->e.x[0] + 3;
    else
      col->x[0] = s->e.x[0];
    col->y[0] = s->e.y[0] + 2;  
    col->w[0] = 2;
    col->h[0] = 2;
    col->x[1] = _character.e.x[0];
    col->y[1] = _character.e.y[0];
    col->w[1] = _character.e.w[0];
    col->h[1] = _character.e.h[0];
    checkCollision(col);
    if(col->collision)
    {
      s->status  = ss_attack;
      s->e.draw  = 2;
      doCharacterAction(cs_hurt);
    }
  }
}

void
moveSkeleton(Skeleton* s) __z88dk_fastcall
{

  if(s->anim.side == as_left)
  {    
    --s->e.x[0]; 
  }
  else if(s->anim.side == as_right)
  {
    ++s->e.x[0];
  }

  if(endGround(s) || s->e.x[0] == 0 || (s->e.x[0]+s->e.w[0]) == 80)
  {
    if(s->anim.side == as_right)
    {
      --s->e.x[0];
      s->anim.side = as_left;
    }
    else
    {
      ++s->e.x[0];
      s->anim.side = as_right;
    }
    chooseAnimationSkeleton(s);
  }

  setGrid(&s->e);

  s->e.draw = 2;
}

void
updateSkeleton()
{
  Game* g           = &_game;
  SkeletonArray* s  = &g->lvl->m->s;
  Skeleton* current = s->current + s->idx;
  u8 dist;

  if(current->status != ss_dead)
  {
    current->e.draw = 2;
    switch(current->status)
    {
      case ss_attack:
        if(current->anim.status == as_end)
        {
          current->status = ss_walk;
        }
        break; 
      case ss_walk:
        moveSkeleton(current);
        dist = distanceToCharacter(&current->e);        
        if(dist <= s->min_dist)
        {
          s->min_dist = dist;
          s->nearest  = s->current + s->idx;
          if(_character.e.grid == current->e.grid)
            attackSkeleton(current);
        }
        break;
      case ss_hurt:
        if(current->anim.status == as_end)
        {
          current->status = ss_walk;
        }
        break;
      case ss_dying:
        if(current->anim.status == as_end)
        {
          current->status = ss_dead;
          eraseEntityBuffersSolidBox(&current->e);
          current->e.draw = 0;
        }
        break;        
    }

    updateSkeletonAnimation(current);

    current->lstatus = current->status;
  }

  ++s->idx;
  if(s->idx == s->num)
    s->idx = 0;   
}

void
drawSkeletons()
{
  Game *g           = &_game;
  SkeletonArray* s  = &g->lvl->m->s;
  Skeleton* current = s->current + s->num;
  while(current != s->current)
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

void 
hurtSkeleton(Skeleton *s) __z88dk_fastcall
{
  if(--s->hp)
  {
    s->status = ss_hurt;
  }
  else
  {
    s->status = ss_dying;
  } 
  updateSkeletonAnimation(s);
}