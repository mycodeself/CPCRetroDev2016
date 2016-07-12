#include "draw.h"

void drawBlock()
{
	u8 *pvmem;
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, _platform.min.x, _platform.min.y);
	cpct_drawSolidBox(pvmem, cpct_px2byteM0(6,6), _platform.size.x, _platform.size.y);
}

void drawCharacter()
{
	TCharacter *b = &_character;
	b->p_vmem = cpct_getScreenPtr(CPCT_VMEM_START, b->body.lastpos.x, b->body.lastpos.y);
	cpct_drawSolidBox(b->p_vmem, cpct_px2byteM0(0, 0), b->body.box.size.x, b->body.box.size.y);
	b->p_vmem = cpct_getScreenPtr(CPCT_VMEM_START, b->body.box.min.x, b->body.box.min.y);
	cpct_drawSolidBox(b->p_vmem, cpct_px2byteM0(3, 3), b->body.box.size.x, b->body.box.size.y);
}