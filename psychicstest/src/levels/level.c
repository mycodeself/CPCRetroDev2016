#include "level.h"


void
startLevel()
{
  Game *g = _game;
  g->lvl.idx = 0;
  cpct_etm_setTileset2x4(LEVEL0_tileset);
  cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(1, 1), 0x4000);
  drawLevel0();
}

u8
nextLevel()
{
  Game* g = &_game;
  if(level0_index < LEVEL0_NUM_MAPS) {
    g->map = level0_maps[++level0_index];
    drawLevel0();
    return 1;
  }
  return 0;
}

u8
prevLevel()
{
  Game* g = &_game;
  if(g->lvl->idx != 0)
  {
    g->
  }
  if(level0_index != 0) {
    g->map = level0_maps[--level0_index];
    drawLevel0();
    return 1;
  }
  return 0;
}