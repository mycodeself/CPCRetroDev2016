#include "draw.h"

void drawBorder()
{
	u8 *pvmem;
	u8 i;
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, BORDER_TOP_POSITION_X, BORDER_TOP_POSITION_Y);
	for(i=16;i!=0;--i)
	{
		cpct_drawSprite(_border, pvmem, BORDER_SIZE_X, BORDER_SIZE_Y);
		pvmem += 5;
	}	
	
}

void drawBlock()
{
	u8 *pvmem;
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, _platform.min.x, _platform.min.y);
	cpct_drawSolidBox(pvmem, cpct_px2byteM0(6,6), _platform.size.x, _platform.size.y);
}

void drawCharacter()
{
	TCharacter *c = &_character;
	AnimationFrame* frame = c->anim->frames[c->anim->frame_idx];

	c->p_vmem = cpct_getScreenPtr(CPCT_VMEM_START, c->body.lastpos.x, c->body.lastpos.y);
	cpct_drawSolidBox(c->p_vmem, cpct_px2byteM0(BACKGROUND_COLOR, BACKGROUND_COLOR), c->body.box.size.x, c->body.box.size.y);
	c->p_vmem = cpct_getScreenPtr(CPCT_VMEM_START, c->body.box.min.x, c->body.box.min.y);
	cpct_drawSpriteMasked(frame->sprite, c->p_vmem, frame->size_x, frame->size_y);
}


void drawGround()
{
	u8 *pvmem;
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, GROUND_POSITION_X, GROUND_POSITION_Y+3);
	cpct_drawSolidBox(pvmem, cpct_px2byteM0(11,11), 50, GROUND_SIZE_Y-3);
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, GROUND_POSITION_X, GROUND_POSITION_Y);
	cpct_drawSolidBox(pvmem, cpct_px2byteM0(5,5), 50, 3);
}