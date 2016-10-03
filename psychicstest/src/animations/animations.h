#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_

#include "../common.h"
#include <types.h>

typedef enum { as_play, as_cycle, as_pause, as_end } AnimationStatus;

typedef enum { as_right, as_left } AnimationSide;

typedef struct AnimationFrame {
  u8* sprite;
  u8 size_x, size_y; // bytes
  u8 time;
  AnimationSide side;
} AnimationFrame;

typedef struct Animation {
  AnimationFrame** frames;
  u8 frame_idx;
  u8 numframes;
  AnimationStatus status;
  u8 time;
  AnimationSide side;
} Animation;

extern AnimationFrame* const _character_anim_idle[1];
extern AnimationFrame* const _character_anim_walk[2];
extern const Animation _character_animation;

void updateAnimation(Animation* anim);

#endif