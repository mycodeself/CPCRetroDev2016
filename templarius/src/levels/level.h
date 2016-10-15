#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <types.h>
#include "../enemies/skeleton.h"

typedef struct LevelMap
{
  u8* 		map;
  Skeletons s;
} LevelMap;

typedef struct Level
{
  LevelMap* lm;
  u8 idx;
  u8 num_maps;
} Level;

void startLevel();
u8 nextLevelMap();
u8 prevLevelMap();

#endif