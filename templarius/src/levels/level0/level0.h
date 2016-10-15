#ifndef _LEVEL0_H_
#define _LEVEL0_H_

#include <cpctelera.h>
#include "../level.h"

#define LEVEL0_START_POSITION_X 6   		
#define LEVEL0_START_POSITION_Y 200 - 20 - 20 // 200 px full map - 20 px ground - 18 character size

extern const Level _level0;

void
initLevel0();

#endif