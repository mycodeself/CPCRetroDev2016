//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------
#include <cpctelera.h>
#include "common.h"
#include "character/character.h"
#include "draw/draw.h"
#include "assets/level0.h"
#include "assets/level0_tileset.h"
#define _level0_VMEM		cpctm_screenPtr(CPCT_VMEM_START,0,40)
#define LEVEL0_MAXSCROLL	100


typedef struct {
	u8* video_ptr;
	u8* tile_ptr;
	u8	scroll;
} ScreenPointer;

const ScreenPointer _screen_ptr = {CPCT_VMEM_START, _level0, 0};


void scrollScreen(i16 scroll)
{
	ScreenPointer *scr = &_screen_ptr;
   // Select leftmost or rightmost column of the tilemap to be redrawn 
   // depending on the direction of the scrolling movement made
   u8 column = (scroll > 0) ? (40-1) : (0);

   // Update pointers to tilemap drawable window, tilemap upper-left corner in video memory
   // and scroll offset
   scr->video_ptr   += 2*scroll; // Video memory starts now 2 bytes to the left or to the right
   scr->tile_ptr += scroll;   // Move the start pointer to the tilemap 1 tile (1 byte) to point to the drawable zone (viewport)
   scr->scroll   += scroll;   // Update scroll offset to produce scrolling
	
   // Wait for VSYNC before redrawing,
   cpct_waitVSYNC(); 
   // Do hardware scrolling to the present offset
   cpct_setVideoMemoryOffset(scr->scroll);    
   
   // Redraw newly appearing column (either it is left or right)
   cpct_etm_drawTileBox2x4(column, 0,         // (X, Y) Upper-left Location of the Box (column in this case) to be redrawn
                           1, _level0_H,     // (Width, Height) of the Box (column) to be redrawn
                           _level0_W,         // Width of the full tilemap (which is wider than the screen in this case)
                           scr->video_ptr,       // Pointer to the upper-left corner of the tilemap in video memory
                           scr->tile_ptr);    // Pointer to the first tile of the tilemap to be drawn (upper-left corner
                                              // ... of the tilemap viewport window)

   // When scrolling to the right, erase the character (2x8) bytes that scrolls-out
   // through the top-left corner of the screen. Othewise, this pixel values will 
   // loop and appear through the bottom-down corner later on.
   // When scrolling to the left, erase the character that appears on the left, just
   // below the visible tilemap
   if (scroll > 0) 
      cpct_drawSolidBox(scr->video_ptr - 2, 0, 2, 8);  // top-left scrolled-out char
   else {
      u8* br_char = cpct_getScreenPtr(scr->video_ptr, 0, _level0_H);
      cpct_drawSolidBox(br_char, 0, 2, 8);  // bottom-right scrolled-out char
   }
}

i16 wait4KeyboardInput(){
   // Read keyboard continuously until the user perfoms an action
   while(1) {
      // Scan Keyboard
      cpct_scanKeyboard_f(); 

      // Check user keys for controlling scroll. If one of them is pressed
      // return the associated scroll offset.
      if      (cpct_isKeyPressed(Key_CursorRight)) return  1;
      else if (cpct_isKeyPressed(Key_CursorLeft))  return -1;
   }
}


const AABB _platform = {
	{30, 145}, 	// min	
	{42, 151}, 	// max
	{12, 6},	// size
};

void init()
{
	cpct_disableFirmware();
   	cpct_setPalette(_palette, 16);
	cpct_clearScreen(cpct_px2byteM0(BACKGROUND_COLOR, BACKGROUND_COLOR));
	cpct_setBorder(HW_BLACK);
	cpct_setVideoMode(0);
}


void blockCollisions()
{
	AABB *platform = &_platform;
	TCharacter *character = &_character;
	if(AABB_BoxCollision(&character->body.box, platform)){
		switch(checkCollisionSide(platform, &character->body.box))
		{
			case COLLISION_SIDE_BOTTOM:
				character->status = cs_idle;
				character->body.velocity.y 	= 0;
				character->body.box.max.y 	= platform->min.y;
				character->body.box.min.y	= platform->min.y - character->body.box.size.y;
				break;
			case COLLISION_SIDE_TOP:
				character->body.velocity.y 	= 0;
				character->body.box.min.y 	= platform->max.y + 1;
				character->body.box.max.y	= character->body.box.min.y + character->body.box.size.y;
				break;
			case COLLISION_SIDE_RIGHT:
				character->body.box.max.x 	= platform->min.x;
				character->body.box.min.x 	= platform->min.x - character->body.box.size.x;
				character->body.velocity.x	= 0;
				break;
			case COLLISION_SIDE_LEFT:
				character->body.box.min.x 	= platform->max.x;
				character->body.box.max.x	= platform->max.x + character->body.box.size.x;
				character->body.velocity.x	= 0;
				break;
		}
	}
}


void startLevel0()
{
   	cpct_etm_setTileset2x4(_level0_tileset);
}

void drawLevel0()
{
	
	//cpct_etm_drawTilemap2x4(_level0_W, _level0_H, _level0_VMEM, _level0);

	cpct_etm_drawTileBox2x4(0, 0, 35, _level0_H, _level0_W, _level0_VMEM, _level0_tileset);
}

void main(void) {
   	u8* pvmem;
   	i16 scroll_offset;
   	init();
   	startLevel0();
   	drawLevel0();



	while(1)
	{

		/*scroll_offset = wait4KeyboardInput();
		if (scroll_offset > 0 ) {
			if(_screen_ptr.scroll == LEVEL0_MAXSCROLL) continue;  // Do not scroll passed the right limit
		} else if(_screen_ptr.scroll == 0) continue;  // Do not scroll passed the left limit

		// Scroll and redraw the tilemap
		scrollScreen(scroll_offset);		*/
//		cpct_waitVSYNC(); 	//first frame
//		updateCharacter();
//		blockCollisions();
//		cpct_waitVSYNC();	// second frame
//		drawBlock();
		//drawCharacter();
	}
}
