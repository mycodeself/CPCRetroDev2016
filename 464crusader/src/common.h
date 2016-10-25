/*	
 *
 *  This file is part of 464 Crusader, game for Amstrad CPC 464.
 *
 *  464 Crusader is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  464 Crusader is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 464 Crusader.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef _COMMON_H_
#define _COMMON_H_

#include <cpctelera.h>
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