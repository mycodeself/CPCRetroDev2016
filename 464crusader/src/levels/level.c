/*  
 *
 *  This file is part of 464 Crusader, game for Amstrad CPC 464.
 *
 *  464 Crusader is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  464 Crusader is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 464 Crusader.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "level.h"
#include "level1/level1_tileset.h"
#include "../draw/draw.h"
#include "../game.h"
#include "../character/character.h"
#include "../mainscreen/mainscreen.h"

void
startLevel()
{
  Game *g = &_game;
  cpct_etm_setTileset2x4(LEVEL1_tileset);
  drawMap();
}

u8
nextMap()
{
  Game* g = &_game;
  if(g->lvl->idx < 1)
  {
    ++g->lvl->m;
    ++g->lvl->idx;
    drawMap();
    return 1;
  }else{
    mainScreen();
  }
  return 0;
}

u8
prevMap()
{
  Game* g = &_game;
  if(g->lvl->idx != 0)
  {
    --g->lvl->m;
    --g->lvl->idx;
    drawMap();
    return 1;
  }
  return 0;
}

void 
mapLimitsLevel1()
{
  Character* c = &_character;

  if(c->e.x[0] <= 1) { // left limit
    if(prevMap())
      c->e.x[0] = SCREEN_BYTES_WIDTH - c->e.w[0] - 4;
    else
      c->e.x[0] = 2;
  } else if((c->e.x[0] + c->e.w[0]) >= SCREEN_BYTES_WIDTH-1) {  // right limit
    if(nextMap())
      c->e.x[0] = 4;
    else
      c->e.x[0] = SCREEN_BYTES_WIDTH - c->e.w[0] - 2;
  }
  if(c->e.y[0] <= 40) // top limit
  {
    c->e.y[0] = 40;
  }
}

// void
// adjustPositionLevel2()
// {
//   Character* c  = &_character;
//   Game* g       = &_game;
//   switch(g->lvl->idx)
//   {
//     case 0:
//       c->e.x[0] = 52;
//       c->e.y[0] = 140;
//       break;
//     case 1:
//       c->e.x[0] = 22;
//       c->e.y[0] = 136;
//       break;
//     case 2:
//       c->e.x[0] = 34;
//       c->e.y[0] = 140;  
//       break;
//   }
// }

// void 
// mapLimitsLevel2()
// {
//   Character* c = &_character;
//   if(c->e.x[0] <= 0) { // left limit
//       c->e.x[0] = 2;
//   } else if((c->e.x[0] + c->e.w[0]) >= SCREEN_BYTES_WIDTH) {  // right limit
//       c->e.x[0] = SCREEN_BYTES_WIDTH - c->e.w[0] - 2;
//   }
//   if(c->e.y[0] <= 40) // top limit
//   {
//     c->e.y[0] = 38;
//     nextMap();    
//     adjustPositionLevel2();
//   }
// }

void
mapLimits()
{
  mapLimitsLevel1();

}