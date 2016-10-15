#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_

#include <cpctelera.h>

typedef enum { as_play, as_cycle, as_end } AnimationStatus;

typedef enum { as_right, as_left } AnimationSide;

typedef struct AnimationFrame {
  u8* sprite;
  u8 w, h; // bytes
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

void updateAnimation(Animation* anim);

#endif