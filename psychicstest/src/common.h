#ifndef _COMMON_H_
#define _COMMON_H_

#include <cpctelera.h>
#include <stdio.h>
#include <types.h>
#include <math.h>
#include <stdio.h>

// SCREEN SIZE
#define SCREEN_BYTES_WIDTH		80
#define SCREEN_BYTES_HEIGHT		200
#define SCREEN_PIXELS_HEIGHT	200
#define SCREEN_PIXELS_WIDTH		160

#define CHARACTER_MAX_HEIGHT 	190
#define CHARACTER_MAX_WIDTH 	80

// PHYSICS
#define GRAVITY_FORCE 			1
#define JUMP_FORCE				-10

// COLLISIONS
#define COLLISION_SIDE_BOTTOM 	0
#define COLLISION_SIDE_LEFT 	1
#define COLLISION_SIDE_RIGHT	2
#define COLLISION_SIDE_TOP		3

#endif