#ifndef _COMMON_H_
#define _COMMON_H_

#include <cpctelera.h>
#include <math.h>
#include <stdio.h>
#include <types.h>

// SCREEN SIZE
#define SCREEN_BYTES_WIDTH 80    // bytes
#define SCREEN_BYTES_HEIGHT 200  // bytes

#define GAME_SCREEN_W 80  // bytes
#define GAME_SCREEN_H 160 // bytes

#define HUD_POSITION_X 0   // bytes
#define HUD_POSITION_Y 160 // bytes
#define HUD_SIZE_W 80      // bytes
#define HUD_SIZE_H 40      // bytes


// PHYSICS
#define GRAVITY_FORCE 2

// COLLISIONS
#define COLLISION_SIDE_BOTTOM 0
#define COLLISION_SIDE_LEFT 1
#define COLLISION_SIDE_RIGHT 2
#define COLLISION_SIDE_TOP 3

#endif