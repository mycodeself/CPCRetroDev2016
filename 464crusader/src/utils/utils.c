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