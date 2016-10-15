#include "skeleton.h"
#include "sprites/skeleton_walk0.h"
#include "sprites/skeleton_walk1.h"
#include "sprites/skeleton_hurt.h"
#include "../utils/utils.h"
#include "../game.h"

#define WALK_ANIM_FRAMES  2
#define HURT_ANIM_FRAMES  1

const AnimationFrame _skeleton_frames[3] = {
  // sprite, width bytes, height bytes, time, look
  { sprite_skeleton_walk0, SPRITE_SKELETON_WALK0_W, SPRITE_SKELETON_WALK0_H, 1, as_left },
  { sprite_skeleton_walk1, SPRITE_SKELETON_WALK1_W, SPRITE_SKELETON_WALK1_H, 1, as_left },
  { sprite_skeleton_hurt, SPRITE_SKELETON_HURT_W, SPRITE_SKELETON_HURT_H, 10, as_left }
};

AnimationFrame* const _skeleton_anim_walk[WALK_ANIM_FRAMES] = {
  &_skeleton_frames[0], &_skeleton_frames[1]
};

AnimationFrame* const _skeleton_anim_hurt[HURT_ANIM_FRAMES] = {
  &_skeleton_frames[2]
};

const Animation _skeleton_animation = { _skeleton_anim_walk, 0, WALK_ANIM_FRAMES, as_cycle, 0, as_left };

const Skeleton _skeleton_template = 
{
  {
    sprite_skeleton_walk0,  // sprite
    2,                      // draw
    {30,	30,		30},        // x
    {164,	164,	164},  	    // y
    {SPRITE_SKELETON_WALK0_W, SPRITE_SKELETON_WALK0_W, SPRITE_SKELETON_WALK0_W},  // w
    {SPRITE_SKELETON_WALK0_H, SPRITE_SKELETON_WALK0_H, SPRITE_SKELETON_WALK0_H}   // h
  }, // DrawableEntity
  { _skeleton_anim_walk, 0, WALK_ANIM_FRAMES, as_cycle, 0, as_left },             // Animation
  ss_walk,                  // SkeletonStatus
  ss_walk,                  // Last SkeletonStatus
  2,                        // hp
};

void updateSkeletonAnimation(Skeleton* s)
{
  AnimationFrame* frame;
  
  updateAnimation(&s->anim);
  frame = s->anim.frames[s->anim.frame_idx];

  if(s->status != s->lstatus)
  {
    switch(s->status)
    {
      case ss_idle:
        break;
      case ss_walk:
        s->anim.frames     = (AnimationFrame**)_skeleton_anim_walk;
        s->anim.numframes  = WALK_ANIM_FRAMES;
        s->anim.status     = as_cycle;
        break;
      case ss_hurt:
        s->anim.frames     = (AnimationFrame**)_skeleton_anim_hurt;
        s->anim.numframes  = HURT_ANIM_FRAMES;
        s->anim.status     = as_play;
        break;
    }
    s->anim.frame_idx = 0;
    frame = s->anim.frames[s->anim.frame_idx];
    s->anim.time = 0;
  }

  s->de.sprite = frame->sprite;
  s->de.w[0] = frame->w;
  s->de.h[0] = frame->h;

}


u8 
endGround(Skeleton* s)
{
  u8* tile;
  if(s->anim.side == as_right)
    tile = getTilePtr(s->de.x[0]+s->de.w[0], s->de.y[0]+s->de.h[0]);
  else
    tile = getTilePtr(s->de.x[0], s->de.y[0]+s->de.h[0]);

  if(*(tile) <= 5)
    return 0;
  return 1;
}

void
move(Skeleton* s)
{
  u8 changeDirection = 0;
  if(s->anim.side == as_left)
    --s->de.x[0]; 
  else if(s->anim.side == as_right)
    ++s->de.x[0];
  
  if(endGround(s) || s->de.x[0] == 0 || (s->de.x[0]+s->de.w[0]) == 80)
  {
    changeDirection = 1;
  }

  if(changeDirection)
  {
    if(s->anim.side == as_right)
    {
      --s->de.x[0];
      s->anim.side = as_left;
    }
    else
    {
      ++s->de.x[0];
      s->anim.side = as_right;
    }
  }
}

void
updateSkeleton()
{
  Game* g = &_game;
  Skeletons* s = &g->lvl->lm->s;
  Skeleton* current;

  current = s->current + s->idx;

  if(current->de.draw == 2)
  {
    switch(current->status)
    {
      case ss_walk:
        move(current);
        break;
      case ss_hurt:
        if(current->anim.status == as_end)
        {
          current->status = ss_walk;
        }
    }
    updateSkeletonAnimation(current);
  }

  if(current->de.draw)
  {
    eraseEntity(&current->de);
    drawEntity(&current->de);
    updateDrawableEntity(&current->de);
  }

  current->lstatus  = current->status;
  if(!current->de.draw)
  {
    ++s->idx;
    if(s->idx == s->num)
      s->idx = 0;
    current->de.draw = 2;    
  }

}