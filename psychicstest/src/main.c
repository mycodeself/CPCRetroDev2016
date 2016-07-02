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
#include <stdio.h>
#include "psychics.h"

#define SCREEN_MAX_WIDTH 		80
#define SCREEN_MAX_HEIGHT 		200
#define CHARACTER_MAX_HEIGHT 	190
#define CHARACTER_MAX_WIDTH 	80

typedef enum {
	s_idle,
	s_jump
}Status;

typedef struct Entity  
{
	Body body;
	Status status;	
	u8* p_vmem;
	Vector2D lastpos;
}Entity;

const Body block = {
	{
		{30, 165}, // min	
		{42, 171}, // max
	}, // box
	{0,0}, // velocity
	{12, 6}, // size	
};

const Entity box = {
	{
		{
			{10, 160}, // min	
			{15, 190}, // max
		}, // box
		{0,0}, // velocity
		{5, 30}, // size
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

void updateBox()
{
	Entity *b 			= &box;	
	b->body.velocity.x 	= 0;
	b->lastpos.x 		= b->body.box.min.x;
	b->lastpos.y 		= b->body.box.min.y;
	// gravity
	if(b->body.box.max.y < CHARACTER_MAX_HEIGHT)
	{
		b->body.velocity.y += GRAVITY_FORCE;
	}
	cpct_scanKeyboard_f();
	if(cpct_isKeyPressed(Key_Space) && b->status != s_jump)
	{
		b->body.velocity.y += JUMP_FORCE;
		b->status 			= s_jump;
	}else if(cpct_isKeyPressed(Key_CursorRight))
	{
		b->body.velocity.x += 1;
	}else if(cpct_isKeyPressed(Key_CursorLeft))
	{
		b->body.velocity.x -= 1;
	}
	b->body.box.min.y += b->body.velocity.y;
	b->body.box.max.y += b->body.velocity.y;
	b->body.box.min.x += b->body.velocity.x;
	b->body.box.max.x += b->body.velocity.x;
	if(b->body.box.max.y > CHARACTER_MAX_HEIGHT)
	{
		b->body.box.min.y -= (b->body.box.max.y - CHARACTER_MAX_HEIGHT);
		b->body.box.max.y -= (b->body.box.max.y - CHARACTER_MAX_HEIGHT);
	}
	if(b->body.box.max.y == CHARACTER_MAX_HEIGHT)
		b->status = s_idle;
}

void blockCollisions()
{
	Body *block_ = &block;
	Entity *box_ = &box;
	u8 *pvmem;
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, block_->box.min.x, block_->box.min.y);
	if(AABB_BoxCollision(&box_->body.box, &block_->box)){
		switch(checkBodyCollisionSide(&box_->body, block_))
		{
			case COLLISION_SIDE_BOTTOM:
				box_->body.box.min.y -= (box_->body.box.max.y - block_->box.min.y);
				box_->body.box.max.y -= (box_->body.box.max.y - block_->box.min.y);
				cpct_drawStringM0("BOT", CPCT_VMEM_START, _palette[0], _palette[1]);
				break;
			case COLLISION_SIDE_RIGHT:
				//box_->body.box.min.x -= (box_->body.box.max.x - block_->box.min.x);
				//box_->body.box.max.x -= (box_->body.box.max.x - block_->box.min.x);
				cpct_drawStringM0("RIGHT", CPCT_VMEM_START, _palette[0], _palette[1]);
				break;
			case COLLISION_SIDE_LEFT:
				cpct_drawStringM0("LEFT", CPCT_VMEM_START, _palette[0], _palette[1]);
				break;
			case COLLISION_SIDE_TOP:
				cpct_drawStringM0("TOP", CPCT_VMEM_START, _palette[0], _palette[1]);				
				break;
		}
		
	}
}

void drawBlock()
{
	u8 *pvmem;
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, block.box.min.x, block.box.min.y);
	cpct_drawSolidBox(pvmem, cpct_px2byteM0(6,6), block.size.x, block.size.y);
}

void drawBox()
{
	Entity *b = &box;
	b->p_vmem = cpct_getScreenPtr(CPCT_VMEM_START, b->lastpos.x, b->lastpos.y);
	cpct_drawSolidBox(b->p_vmem, cpct_px2byteM0(0, 0), b->body.size.x, b->body.size.y);
	b->p_vmem = cpct_getScreenPtr(CPCT_VMEM_START, b->body.box.min.x, b->body.box.min.y);
	cpct_drawSolidBox(b->p_vmem, cpct_px2byteM0(3, 3), b->body.size.x, b->body.size.y);
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
		drawBlock();
		drawBox();
		updateBox();
		blockCollisions();
		cpct_waitVSYNC();
	}
}
