#ifndef _COMMON_H_
#define _COMMON_H_

#include <cpctelera.h>
#include <math.h>
#include <types.h>

// SCREEN SIZE
#define SCREEN_BYTES_WIDTH 	80	// bytes
#define SCREEN_BYTES_HEIGHT 200 // bytes

#define GAME_SCREEN_W 		80  // bytes
#define GAME_SCREEN_H 		160 // bytes
#define GAME_SCREEN_START_X 0
#define GAME_SCREEN_START_Y 40

#define GAME_VMEM0_START	cpctm_screenPtr(0xC000, 0, 40)
#define GAME_VMEM1_START	cpctm_screenPtr(0x8000, 0, 40)

#define HUD_POSITION_X 		0	// bytes
#define HUD_POSITION_Y 		0 	// bytes
#define HUD_SIZE_W 			80 	// bytes
#define HUD_SIZE_H 			40	// bytes

// EMERALD TILE ID
#define EMERALD_TILE_ID_0	22
#define EMERALD_TILE_ID_1 	23
#define EMERALD_TILE_ID_2	30
#define EMERALD_TILE_ID_3	31		

// PHYSICS
#define GRAVITY_FORCE 		2

// Double buffer
extern u8* _screenMem;
extern u8* _backBuffer;

// Entity
typedef struct Entity
{
  	u8*	sprite;				  	
  	u8	draw;
  	u8 	x[3], y[3];
  	u8 	w[3], h[3];	
  	u8	grid;			 
} Entity;



#endif