#include "game.h"
#include "utils/utils.h"
#include <cpctelera.h>

const u8 _palette[16] = {
  0x47, 0x54, 0x4b, 0x40, 0x44, 0x55, 0x57, 0x46, 0x58, 0x43, 0x52, 0x5a, 0x56, 0x5c, 0x4c, 0x4e
};

void
init()
{
  cpct_disableFirmware();
  cpct_setVideoMode(0);
  cpct_setPalette(_palette, 16);
  cpct_setBorder(HW_BLACK);
}

void
main(void)
{
  init();
  game();
}
