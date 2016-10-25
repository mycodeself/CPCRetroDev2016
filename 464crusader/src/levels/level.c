#include "level.h"
#include "level1/level1_tileset.h"
#include "level2/level2.h"
#include "../draw/draw.h"
#include "../game.h"

#define LEVEL1 0
#define LEVEL2 1
#define LEVEL3 2

void
startLevel()
{
  Game *g = &_game;
  g->lvl->idx = 0;
  cpct_etm_setTileset2x4(LEVEL1_tileset);
  drawMap();
}

void
nextLevel()
{
  Game* g = &_game;
  switch(g->lvlidx)
  {
    case LEVEL1:
      g->lvl = &_level2;
      break;
    case LEVEL2:
      break;
    case LEVEL3:
      break;
  }
  ++g->lvlidx;
  drawMap();
}


void 
nextMap()
{
  Game* g = &_game;
  if(++g->lvl->idx < g->lvl->num){
    ++g->lvl->m;       
    drawMap();
  }else if(g->lvl->idx == g->lvl->num)
  {
    nextLevel();
  }
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