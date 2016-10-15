#include "utils.h"
#include "../levels/level0/level0.h"
#include "../game.h"

u8*
getTilePtr(u8 x, u8 y)
{
  Game *g = &_game;
  return g->lvl->lm->map + ((y-40)/ 4 * 40 + x / 2);
}