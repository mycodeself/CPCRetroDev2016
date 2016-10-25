#ifndef _DRAW_H_
#define _DRAW_H_

#include "../common.h"

void drawEntity(Entity*) __z88dk_fastcall;
void eraseEntityTileBox(Entity*) __z88dk_fastcall;
void eraseEntitySolidBox(Entity*) __z88dk_fastcall;
void updateDrawableEntity(Entity*) __z88dk_fastcall;
void eraseEntityBuffersSolidBox(Entity*);
void drawMap();

#endif