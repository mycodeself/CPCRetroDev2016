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
#include "physics.h"
#include "draw/draw.h"


const AABB _platform = {
	{30, 145}, 	// min	
	{42, 151}, 	// max
	{12, 6},	// size
};

const TCharacter _character = {
	{
		{
			{10, 160}, 	// min	
			{15, 190}, 	// max
			{5, 30}, 	// size
		}, // AABB Box
		{0,0}, // velocity
	}, // body	 
	{s_idle}, //status
	CPCT_VMEM_START,
	{10, 140},
};


// Black, Yellow, 
const u8 _palette[16] = {
   0x00, 0x0C, 0x03, 0x18, 0x0D, 0x14, 0x06, 0x1A,
   0x00, 0x02, 0x01, 0x12, 0x08, 0x05, 0x10, 0x09
};


void init()
{
	cpct_disableFirmware();
   	cpct_fw2hw(_palette, 16);
   	cpct_setPalette(_palette, 16);
	cpct_setVideoMode(0);
	cpct_clearScreen_f64(0);
}
void characterController()
{
	TCharacter *c = &_character;
	cpct_scanKeyboard_f();
	// jump
	if(cpct_isKeyPressed(Key_Space) && c->status != s_jump)
	{
		c->body.velocity.y += JUMP_FORCE;
		c->status 			= s_jump;
	}
	// lateral move
	if(cpct_isKeyPressed(Key_CursorRight))
	{
		c->body.velocity.x += 1;
	}else if(cpct_isKeyPressed(Key_CursorLeft))
	{
		c->body.velocity.x -= 1;
	}
}



void blockCollisions()
{
	AABB *platform = &_platform;
	TCharacter *character = &_character;
	u8 *pvmem;
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 15, 50);
	if(AABB_BoxCollision(&character->body.box, platform)){
		switch(checkCollisionSide(platform, &character->body.box))
		{
			case COLLISION_SIDE_BOTTOM:
				character->status = s_idle;
				character->body.velocity.y 	= 0;
				character->body.box.max.y 	= platform->min.y;
				character->body.box.min.y	= platform->min.y - character->body.box.size.y;
				cpct_drawSolidBox(pvmem, cpct_px2byteM0(4, 4), 15, 20);
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
	}else{
	}
}


void updateCharacter()
{
	TCharacter *c = &_character;

	c->body.lastpos.x 	= c->body.box.min.x;
	c->body.lastpos.y	= c->body.box.min.y;
	c->body.velocity.x	= 0;
 
	characterController();
	if(c->body.box.max.y < CHARACTER_MAX_HEIGHT)
	{
		c->body.velocity.y	+= GRAVITY_FORCE;
	}
	c->body.box.min.y += c->body.velocity.y;
	c->body.box.max.y += c->body.velocity.y;
	c->body.box.min.x += c->body.velocity.x;
	c->body.box.max.x += c->body.velocity.x;
	if(c->body.box.max.y > CHARACTER_MAX_HEIGHT)
	{
		c->body.box.min.y -= (c->body.box.max.y - CHARACTER_MAX_HEIGHT);
		c->body.box.max.y -= (c->body.box.max.y - CHARACTER_MAX_HEIGHT);
	}
	if(c->body.box.max.y == CHARACTER_MAX_HEIGHT)
		c->status = s_idle;	
	
	blockCollisions();
	
}


void main(void) {
   	u8* pvmem;

   	init();
	
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 0, 190);
	cpct_drawSolidBox(pvmem,  cpct_px2byteM0(1, 1), 40, 10); 
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 40, 190);
	cpct_drawSolidBox(pvmem,  cpct_px2byteM0(1, 1), 40, 10); 

	while(1)
	{
		cpct_waitVSYNC(); //first frame
		updateCharacter();
		blockCollisions();
		drawBlock();
		drawCharacter();
	}
}
