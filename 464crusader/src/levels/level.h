#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <types.h>
#include "../enemies/skeleton.h"
#include "../enemies/bat.h"

typedef struct Map
{
  u8* 			map;
  SkeletonArray s;
  BatArray		b;
} Map;

typedef struct Level
{
  Map* 	m;
  u8 	idx;
  u8 	num;
} Level;

void startLevel();
void nextMap();
u8 prevMap();

#endif