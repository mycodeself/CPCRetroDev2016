#ifndef _COMMON_H_
#define _COMMON_H_

#include <cpctelera.h>
#include <stdio.h>
#include <types.h>
#include <math.h>
#include <stdio.h>

// SCREEN SIZE
#define SCREEN_BYTES_WIDTH			80	// bytes
#define SCREEN_BYTES_HEIGHT			200	// bytes
#define SCREEN_PIXELS_HEIGHT		200 // pixels
#define SCREEN_PIXELS_WIDTH			160	// pixels

// WORLD SIZE
#define WORLD_MIN_X					0
#define WORLD_MIN_Y					40	// pixels
#define WORLD_MAX_X					160	// pixels
#define WORLD_MAX_Y					200	// pixels 

#define GROUND_POSITION_X			0	// bytes
#define GROUND_POSITION_Y			180	// bytes
#define GROUND_SIZE_X				80 	// bytes
#define GROUND_SIZE_Y				20	// bytes

#define BACKGROUND_COLOR			8	// 

// CHARACTER SPRITE SIZES
#define CHARACTER_IDLE_0_SIZE_X		8	// bytes
#define CHARACTER_IDLE_0_SIZE_Y 	32	// bytes

#define CHARACTER_WALK_0_SIZE_X		10	// bytes
#define CHARACTER_WALK_0_SIZE_Y		32	// bytes

#define CHARACTER_WALK_1_SIZE_X		11	// bytes
#define CHARACTER_WALK_1_SIZE_Y		32	// bytes

// CHARACTER NUMBER OF FRAMES PER ANIM
#define CHARACTER_IDLE_ANIM_FRAMES	1
#define CHARACTER_WALK_ANIM_FRAMES	2


// CHARACTER START POSITION
#define CHARACTER_START_X			10
#define CHARACTER_START_Y			148


// PHYSICS
#define GRAVITY_FORCE 				1
#define JUMP_FORCE					-9

// COLLISIONS
#define COLLISION_SIDE_BOTTOM 		0
#define COLLISION_SIDE_LEFT 		1
#define COLLISION_SIDE_RIGHT		2
#define COLLISION_SIDE_TOP			3

#endif