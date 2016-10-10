#include "level.h"


void
startLevel()
{
  Game *g = &_game;
  g->lvl->idx = 0;
  cpct_etm_setTileset2x4(LEVEL0_tileset);
  drawMap();
}


u8
nextLevelMap()
{
  Game* g = &_game;
  if(g->lvl->idx < g->lvl->num_maps){
    ++g->lvl->lm;
    ++g->lvl->idx;
    drawMap();
    return 1;
  }
  return 0;
}

u8
prevLevelMap()
{
  Game* g = &_game;
  if(g->lvl->idx != 0)
  {
    --g->lvl->lm;
    --g->lvl->idx;
    drawMap();
    return 1;
  }
  return 0;
}