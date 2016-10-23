#include "draw.h"
#include "../game.h"

cpctm_createTransparentMaskTable(MASK_TABLE, 0x100, M0, 0);


void 
drawEntity(Entity* e) __z88dk_fastcall
{
  u8* pvm = cpct_getScreenPtr(_backBuffer, e->x[0], e->y[0]);
  cpct_drawSprite(e->sprite, pvm, e->w[0], e->h[0]);
  //cpct_drawSpriteMaskedAlignedTable(e->sprite, pvm, e->w[0], e->h[0], MASK_TABLE);
  pvm = cpct_getScreenPtr(_backBuffer, 0, 60);
}
void 
eraseEntityTileBox(Entity* e) __z88dk_fastcall
{
  Game* g = &_game;
  u8 x = e->x[2] / 2;
  u8 y = (e->y[2] - 40) / 4;
  u8 w = (e->w[2] / 2) + 1;
  u8 h = (e->h[2] / 4) + 1;
  u8* pvm  = cpct_getScreenPtr(_backBuffer, 0, 40);
  cpct_etm_drawTileBox2x4(x, y, w, h, 40, pvm, g->lvl->m->map);
}

void
eraseEntitySolidBox(Entity* e) __z88dk_fastcall
{
  u8* pvm = cpct_getScreenPtr(_backBuffer, e->x[2], e->y[2]);
  cpct_drawSolidBox(pvm, 0, e->w[2], e->h[2]);
}

void eraseEntityBuffersSolidBox(Entity* e)
{
  u8* pvm = cpct_getScreenPtr(0x8000, e->x[0], e->y[0]);
  cpct_drawSolidBox(pvm, 0, e->w[0], e->h[0]); 
  pvm = cpct_getScreenPtr(0xC000, e->x[0], e->y[0]);
  cpct_drawSolidBox(pvm, 0, e->w[0], e->h[0]);
}

void movePosition(u8 *p) __z88dk_fastcall
{
  *p = *(p-1); 
  --p;
  *p = *(p-1);
}

void
updateDrawableEntity(Entity* e) __z88dk_fastcall
{
  movePosition(e->x + 2);
  movePosition(e->y + 2);
  movePosition(e->w + 2);
  movePosition(e->h + 2);
  --e->draw;  
}

void
drawMap()
{
  Game* g = &_game;
  cpct_etm_drawTilemap2x4_f(40, 40, GAME_VMEM0_START, g->lvl->m->map);
  cpct_etm_drawTilemap2x4_f(40, 40, GAME_VMEM1_START, g->lvl->m->map);
}