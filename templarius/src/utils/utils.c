#include "utils.h"

u8*
getTilePtr(u8 x, u8 y)
{
  Game *g = &_game;
  return g->lvl->lm->map + (y / 4 * LEVEL0_1_W + x / 2);
}