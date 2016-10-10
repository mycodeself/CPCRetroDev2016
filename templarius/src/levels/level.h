#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <types.h>
#include "../physics/physics.h"
#include "level0/level0_tileset.h"
#include "../enemies/bat.h"

typedef struct LevelMap
{
  u8* map;
  Body* emeralds;
  Bat* bats;
//Enemies  
} LevelMap;

typedef struct Level
{
  LevelMap* lm;
  u8 idx;
  u8 num_maps;
} Level;

#include "../game.h"

void startLevel();
u8 nextLevelMap();
u8 prevLevelMap();

#endif