#ifndef _UTILS_H_
#define _UTILS_H_

#include "../common.h"

u8* getTilePtr(u8 x, u8 y); 
void removeEmerald(u8* tile) __z88dk_fastcall;
void setGrid(Entity*) __z88dk_fastcall;
u8 distanceToCharacter(Entity*) __z88dk_fastcall;

#endif