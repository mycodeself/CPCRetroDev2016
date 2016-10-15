#ifndef _DRAW_H_
#define _DRAW_H_

#include <types.h>

typedef struct DrawableEntity
{
  	u8*	sprite;				  	
  	u8	draw;
  	u8 	x[3], y[3];
  	u8 	w[3], h[3];	
} DrawableEntity;

void drawEntity(DrawableEntity* de) __z88dk_fastcall;
void eraseEntity(DrawableEntity* de) __z88dk_fastcall;
void updateDrawableEntity(DrawableEntity* de) __z88dk_fastcall;
void drawMap();

#endif