#ifndef _LEVEL0_H_
#define _LEVEL0_H_

#include <cpctelera.h>
#include "level0_tileset.h"
#include "level0_1_map.h"
#include "level0_2_map.h"
#include "../level.h"
#include "../../game.h"
#include "../../physics/physics.h"

#define LEVEL0_START_POSITION_X 5   // bytes
#define LEVEL0_START_POSITION_Y 108 // 160 px full map - 20 px ground - 32 character size
#define LEVEL0_NUM_MAPS 1

extern const Level _level0;

void startLevel0();
u8 nextLevel0();
u8 prevLevel0();

#endif