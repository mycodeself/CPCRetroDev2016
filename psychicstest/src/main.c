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

const AABB _platform = {
	{30, 145}, 	// min	
	{42, 151}, 	// max
	{12, 6},	// size
};

void init()
{
	cpct_disableFirmware();
   	cpct_setPalette(_palette, 16);
	cpct_setVideoMode(0);
	cpct_clearScreen(cpct_px2byteM0(BACKGROUND_COLOR,BACKGROUND_COLOR));
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

void main(void) {
   	u8* pvmem;

   	init();

	drawGround();
	while(1)
	{
		cpct_waitVSYNC(); 	//first frame
		updateCharacter();
		blockCollisions();
		//cpct_waitVSYNC();	// second frame
		drawBlock();
		drawCharacter();
	}
}
