#include "character/character.h"
#include "levels/level1/level1.h"
#include "enemies/skeleton.h"
#include "game.h"

const Game _game = { &_level1, 0, gs_play };

// void
// drawString(u8 *s)
// {
//   u8 str[6];
//   u8* pvm = cpct_getScreenPtr(CPCT_VMEM_START, 0,  0);
//   sprintf(str, "%5u", s);
//   cpct_drawStringM0(str, pvm, 15, 8);
// }

void initBuffers()
{
  __asm
    __backBuffer::   .dw 0x8000
    __screenMem::    .dw 0xC000
  __endasm;
}

void
switchBuffers()
{
  u8* aux     = _backBuffer;
  _backBuffer = _screenMem;
  _screenMem  = aux;

  cpct_setVideoMemoryPage( ((u16)_screenMem) >> 10 ); 
}

void
game()
{
  initScore();
  startLevel();
  initCharacter();
  initLevel1();  
  while(_character.status != cs_dead)
  {
    updateSkeleton();
    updateCharacter();
    cpct_waitVSYNC();
    switchBuffers();
  }
  game();
}
