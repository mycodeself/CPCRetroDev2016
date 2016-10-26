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
#include "utils.h"
#include "../game.h"
#include "../character/character.h"

u8*
getTilePtr(u8 x, u8 y)
{
  Game *g = &_game;
  return g->lvl->m->map + ((y-40)/ 4 * 40 + x / 2);
}

void 
removeEmerald(u8* tile) __z88dk_fastcall
{
  switch(*tile)
  {
    case EMERALD_TILE_ID_1: --tile;     break;
    case EMERALD_TILE_ID_2: tile -= 40; break;
    case EMERALD_TILE_ID_3: tile -= 41; break;
  }
  *tile = 39;
  ++tile;
  *tile = 39;
  tile += 40;
  *tile = 39;
  --tile;
  *tile = 39;
}

void 
initEmerald(u8* tile)  __z88dk_fastcall
{
  *tile = 22;
  ++tile;
  *tile = 23;
  tile += 40;
  *tile = 31;
  --tile;
  *tile = 30;
} 

void 
setGrid(Entity* e) __z88dk_fastcall
{
  if(e->x[0] > 20)
  {
    if(e->x[0] > 40)
    {
      if(e->x[0] > 60)
      {
        e->grid = 3;
      }
      else
      {
        e->grid = 2;
      }
    }
    else
    {
      e->grid = 1;
    }
  }
  else
  {
    e->grid = 0;
  }
}

u8 distanceToCharacter(Entity* e) __z88dk_fastcall
{
  i8 x = (_character.e.x[0] - e->x[0]);
  i8 y = (_character.e.y[0] - e->y[0]);
  if(x < 0) (x = x * -1);
  if(y < 0) (y = y * -1); 
  return x+y;
}