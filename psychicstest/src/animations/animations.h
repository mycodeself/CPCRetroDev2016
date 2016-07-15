#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_

#include <types.h>
#include "../common.h"
#include "../assets/assets.h"
typedef enum {
	as_play,
	as_cycle,
	as_pause,
	as_end
}AnimationStatus;

typedef struct AnimationFrame {
	u8*		sprite;
	u8		size_x;	// bytes
	u8		size_y;	// bytes
}AnimationFrame;

typedef struct Animation {
	AnimationFrame** 	frames;
	u8					frame_idx;
	u8 					numframes;
	AnimationStatus 	status;
}Animation;

extern AnimationFrame* const 	_character_anim_idle[1];
extern AnimationFrame* const	_character_anim_walk[2];
extern const Animation 			_character_animation;

void updateAnimation(Animation* anim);

#endif