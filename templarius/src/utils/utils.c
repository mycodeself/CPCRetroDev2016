#include "utils.h"
#include "../game.h"

u8*
getTilePtr(u8 x, u8 y)
{
  Game *g = &_game;
  return g->lvl->m->map + ((y-40)/ 4 * 40 + x / 2);
}

void 
removeEmerald(u8* tile) __z88dk_fastcall
{
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