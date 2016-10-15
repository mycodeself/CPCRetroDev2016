#include "draw.h"
#include "../game.h"

cpctm_createTransparentMaskTable(MASK_TABLE, 0x100, M0, 0);


void 
drawEntity(DrawableEntity* de) __z88dk_fastcall
{
  u8* pvm = cpct_getScreenPtr(_backBuffer, de->x[0], de->y[0]);
  cpct_drawSpriteMaskedAlignedTable(de->sprite, pvm, de->w[0], de->h[0], MASK_TABLE);
}
void 
eraseEntity(DrawableEntity* de) __z88dk_fastcall
{
  Game* g = &_game;
  u8 x = de->x[2] / 2;
  u8 y = (de->y[2] - 40) / 4;
  u8 w = (de->w[2] / 2) + 1;
  u8 h = (de->h[2] / 4) + 1;
  u8* pvm  = cpct_getScreenPtr(_backBuffer, 0, 40);
  cpct_etm_drawTileBox2x4(x, y, w, h, 40, pvm, g->lvl->lm->map);
}

void movePosition(u8 *p) __z88dk_fastcall
{
  *p = *(p-1); 
  --p;
  *p = *(p-1);
}

void
updateDrawableEntity(DrawableEntity* de) __z88dk_fastcall
{
  movePosition(de->x + 2);
  movePosition(de->y + 2);
  movePosition(de->w + 2);
  movePosition(de->h + 2);
  --de->draw;  
}

void
drawMap()
{
  Game* g = &_game;
  u8* pvm = cpct_getScreenPtr(_backBuffer, 0, 40);
  cpct_etm_drawTilemap2x4_f(40, 40, pvm, g->lvl->lm->map);
  pvm = cpct_getScreenPtr(_screenMem, 0, 40);
  cpct_etm_drawTilemap2x4_f(40, 40, pvm, g->lvl->lm->map);
}
