#include "draw.h"

cpctm_createTransparentMaskTable(MASK_TABLE, 0x100, M0, 0);

void
drawCharacter()
{
  Game* g = &_game;
  TCharacter* c = &_character;
  AnimationFrame* frame = c->anim->frames[c->anim->frame_idx];

  cpct_etm_drawTileBox2x4(c->db.lastpos.x / 2, c->db.lastpos.y / 4, 6, 8, LEVEL0_1_W, CPCT_VMEM_START, g->lvl->lm->map);

  c->p_vmem = cpct_getScreenPtr(CPCT_VMEM_START, c->db.body.pos.x, c->db.body.pos.y);
  cpct_drawSpriteMaskedAlignedTable(frame->sprite, c->p_vmem, frame->size_x, frame->size_y, MASK_TABLE);
}

void
drawLevel()
{
  Game *g = &_game;
  
  // cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(1, 1), 0x4000);
  cpct_etm_drawTilemap2x4_f(LEVEL0_1_W, LEVEL0_1_H, CPCT_VMEM_START, g->lvl->lm->map);
}
