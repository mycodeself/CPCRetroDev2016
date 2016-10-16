#include "skeleton.h"
#include "sprites/skeleton.h"
#include "../utils/utils.h"
#include "../game.h"

#define WALK_ANIM_FRAMES  2
#define HURT_ANIM_FRAMES  1
#define DEAD_ANIM_FRAMES  1
#define SPRITE_W          SPRITE_SKELETON_0_W
#define SPRITE_H          SPRITE_SKELETON_0_H
#define SPRITE_WALK_0_L   sprite_skeleton_0
#define SPRITE_WALK_0_R   sprite_skeleton_1
#define SPRITE_WALK_1_L   sprite_skeleton_2
#define SPRITE_WALK_1_R   sprite_skeleton_3
#define SPRITE_HURT_L     sprite_skeleton_4
#define SPRITE_HURT_R     sprite_skeleton_5
#define SPRITE_DEAD_L     sprite_skeleton_6
#define SPRITE_DEAD_R     sprite_skeleton_7

// Animation Frames
const AnimationFrame _skeleton_frames[8] = {
  // sprite, width bytes, height bytes, time, look
  { SPRITE_WALK_0_L,  SPRITE_W,   SPRITE_H,   2, as_left  },
  { SPRITE_WALK_1_L,  SPRITE_W,   SPRITE_H,   2, as_left  },
  { SPRITE_HURT_L,    SPRITE_W,   SPRITE_H,   1, as_left  },
  { SPRITE_DEAD_L,    SPRITE_W,   SPRITE_H,   1, as_left  },
  { SPRITE_WALK_0_R,  SPRITE_W,   SPRITE_H,   2, as_right },
  { SPRITE_WALK_1_R,  SPRITE_W,   SPRITE_H,   2, as_right },
  { SPRITE_HURT_R,    SPRITE_W,   SPRITE_H,   1, as_right },
  { SPRITE_DEAD_R,    SPRITE_W,   SPRITE_H,   1, as_right }
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

//const Animation _skeleton_animation = { _skeleton_anim_walk_l, 0, WALK_ANIM_FRAMES, as_cycle, 0, as_left };

const Skeleton _skeleton_template = 
{
  {
    SPRITE_WALK_0_L,        // sprite
    2,                      // draw
    {0,	  0,    0},         // x
    {164,	164,	164},  	    // y
    { SPRITE_W, SPRITE_W, SPRITE_W },  // w
    { SPRITE_H, SPRITE_H, SPRITE_H }   // h
  }, // DrawableEntity
  { _skeleton_anim_walk_l, 0, WALK_ANIM_FRAMES, as_cycle, 0, as_left },   // Animation
  ss_walk,                  // SkeletonStatus
  ss_walk,                  // Last SkeletonStatus
  2,                        // hp
};

void chooseSprite(Skeleton* s)
{
  AnimationFrame* frame = s->anim.frames[s->anim.frame_idx];
  if(s->anim.side != frame->side) {
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
      case ss_dead:
        if(s->anim.side == as_left)
          s->anim.frames    = (AnimationFrame**)_skeleton_anim_dead_l;
        else
          s->anim.frames    = (AnimationFrame**)_skeleton_anim_dead_r;
        break;
    }
  }
  s->de.sprite  = frame->sprite;
  s->de.w[0]    = frame->w;
  s->de.h[0]    = frame->h;
}

void updateSkeletonAnimation(Skeleton* s)
{
  AnimationFrame* frame;  

  updateAnimation(&s->anim);
  frame = s->anim.frames[s->anim.frame_idx];
  if(s->status != s->lstatus)
  {
    chooseSprite(s);
    switch(s->status)
    {
      case ss_idle:
        break;
      case ss_walk:
        s->anim.numframes  = WALK_ANIM_FRAMES;
        s->anim.status     = as_cycle;
        break;
      case ss_hurt:
        s->anim.numframes  = HURT_ANIM_FRAMES;
        s->anim.status     = as_play;
        break;
      case ss_dead:
        s->anim.numframes  = HURT_ANIM_FRAMES;
        s->anim.status     = as_play;
    }
    s->anim.frame_idx = 0;
    s->anim.time      = 0;
  }
  s->de.sprite  = frame->sprite;
  s->de.w[0]    = frame->w;
  s->de.h[0]    = frame->h;
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
    chooseSprite(s);
  }
}

void
updateSkeleton()
{
  Game* g = &_game;
  Skeletons* s = &g->lvl->lm->s;
  Skeleton* current;

  current = s->current + s->idx;
  
  current->de.draw = 2;

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

  current->lstatus  = current->status;

  ++s->idx;
  if(s->idx == s->num)
    s->idx = 0;   
}

void
drawSkeletons()
{
  Game *g           = &_game;
  Skeletons* s      = &g->lvl->lm->s;
  Skeleton* current = s->current + s->num;
  while(current != s->current)
  {
    --current;
    if(current->de.draw)
    {
      eraseEntity(&current->de);
      drawEntity(&current->de);
      updateDrawableEntity(&current->de);
    }
  }
}