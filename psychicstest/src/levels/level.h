#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <types.h>
#include "../physics/physics.h"

typedef struct LevelMap
{
  u8* map;
  Body* emeralds;
//Enemies  
} LevelMap;

typedef struct Level
{
  LevelMap* lm;
  u8 idx;
  u8 num_maps;
} Level;

void startLevel();
void nextLevelMap();
void prevLevelMap();

#endif