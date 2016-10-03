#include <cpctelera.h>
#include "game.h"

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
