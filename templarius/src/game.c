#include "character/character.h"
#include "levels/level1/level1.h"
#include "enemies/skeleton.h"
#include "hud/hud.h"
#include "game.h"

const Game _game = { &_level1, 1, gs_play };

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
  initHUD();  
  initLevel1();  
  initCharacter();
  startLevel();
  while(_character.status != cs_dead)
  {    
    updateCharacter();
    updateSkeleton();
    // updateBat();
    drawCharacter();
    drawSkeletons();
    // drawBats();    
    cpct_waitVSYNC();
    switchBuffers();
  }

  drawGameover();
  while(!cpct_isAnyKeyPressed_f())
    cpct_scanKeyboard_f();

  game();
}
