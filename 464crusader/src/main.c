/*  
 *
 *  This file is part of 464 Crusader, game for Amstrad CPC 464.
 *
 *  464 Crusader is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  464 Crusader is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 464 Crusader.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <cpctelera.h>
#include "game.h"
#include "utils/utils.h"
#include "mainscreen/mainscreen.h"
#include "common.h"

const u8 _palette[16] = {
  0x54, 0x47, 0x4b, 0x40, 0x44, 0x55, 0x57, 0x46, 0x58, 0x43, 0x52, 0x5a, 0x56, 0x5c, 0x4c, 0x4e
};

void initBuffers()
{
  __asm
    __backBuffer::   .dw 0x8000
    __screenMem::    .dw 0xC000
  __endasm;
}

void
init()
{
  cpct_disableFirmware();
  cpct_setVideoMode(0);
  cpct_setPalette(_palette, 16);
  cpct_memset((u8*)0x8000, 0, 0x4000);
  cpct_memset((u8*)0xC000, 0, 0x4000);
  cpct_setBorder(HW_BLUE);
}

void
main(void)
{
  cpct_setStackLocation((void*)0x8000);
  init();
  mainScreen();
}
