#include "draw.h"

cpctm_createTransparentMaskTable(MASK_TABLE, 0x100, M0, 0);

void
drawScore()
{
  u8* pvm = cpct_getScreenPtr(CPCT_VMEM_START, 56, 168);
  u8 str[6];
  sprintf(str, "%5u", _game.score);
  cpct_drawStringM0(str, pvm, 9, 1);
}

void
drawCharacter()
{
  Game* g = &_game;
  Character* c = &_character;
  AnimationFrame* frame = c->anim->frames[c->anim->frame_idx];

  cpct_etm_drawTileBox2x4(c->db.lastx / 2, c->db.lasty / 4, 6, 8, LEVEL0_1_W, CPCT_VMEM_START, g->lvl->lm->map);

  c->p_vmem = cpct_getScreenPtr(CPCT_VMEM_START, c->db.body.x, c->db.body.y);
  cpct_drawSpriteMaskedAlignedTable(frame->sprite, c->p_vmem, frame->w, frame->h, MASK_TABLE);
}

void
drawBat()
{
  Game* g = &_game;
  Bat* b  = g->lvl->lm->bats;
  u8* pvm;
  AnimationFrame* frame;
    
  frame = b->anim->frames[b->anim->frame_idx];

  cpct_etm_drawTileBox2x4(b->db.lastx / 2, b->db.lasty / 4, (frame->w / 2)+1, (frame->h / 4) + 2, LEVEL0_1_W,
                          CPCT_VMEM_START, g->lvl->lm->map);

  pvm = cpct_getScreenPtr(CPCT_VMEM_START, b->db.body.x, b->db.body.y);
  cpct_drawSpriteMaskedAlignedTable(frame->sprite, pvm, frame->w, frame->h, MASK_TABLE); 

  ++b;
  frame = b->anim->frames[b->anim->frame_idx];
   // cpct_etm_drawTileBox2x4(b->db.lastx / 2, b->db.lasty / 4, (frame->w / 2)+1, (frame->h / 4) + 2, LEVEL0_1_W,
   //                         CPCT_VMEM_START, g->lvl->lm->map);

  pvm = cpct_getScreenPtr(CPCT_VMEM_START, b->db.body.x, b->db.body.y);
  cpct_drawSpriteMaskedAlignedTable(frame->sprite, pvm, frame->w, frame->h, MASK_TABLE); 

}

void
drawMap()
{
  Game* g = &_game;
  cpct_etm_drawTilemap2x4_f(40, 40, CPCT_VMEM_START, g->lvl->lm->map);
}

// void
// drawEmeralds()
// {
//   Game* g = &_game;
//   Body* eme = g->lvl->lm->emeralds + 9;
//   u8* pvm;

//   while(eme != g->lvl->lm->emeralds) {
//     pvm = cpct_getScreenPtr(CPCT_VMEM_START, eme->x, eme->y);
//     cpct_drawSpriteMaskedAlignedTable(sprite_emerald, pvm, eme->w, eme->h, MASK_TABLE);
//     --eme;
//   }
// }