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

typedef enum {
	al_right,
	al_left
}AnimationLook;

typedef struct AnimationFrame {
	u8*				sprite;
	u8				size_x, size_y;		// bytes
	u8 				time;	
	AnimationLook	look;
}AnimationFrame;

typedef struct Animation {
	AnimationFrame** 	frames;
	u8					frame_idx;
	u8 					numframes;
	AnimationStatus 	status;
	u8					time;
	AnimationLook 		look;
	u8 					erase_x, erase_y;	// bytes to erase y
}Animation;

extern AnimationFrame* const 	_character_anim_idle[1];
extern AnimationFrame* const	_character_anim_walk[2];
extern const Animation 			_character_animation;

void updateAnimation(Animation* anim);

#endif