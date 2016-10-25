#include "character/character.h"
#include "levels/level1/level1.h"
#include "enemies/skeleton.h"
#include "hud/hud.h"
#include "mainscreen/mainscreen.h"
#include "game.h"

const Game _game = { &_level1, 0, gs_play };

void
switchBuffers()
{
  u8* aux     = _backBuffer;
  _backBuffer = _screenMem;
  _screenMem  = aux;

  cpct_setVideoMemoryPage( ((u16)_screenMem) >> 10 ); 
}

void
initGame()
{
  cpct_memset((u8*)0x8000, 0, 0x4000);
  cpct_memset((u8*)0xC000, 0, 0x4000);
}

void
game()
{
  Game* g = &_game;
  initGame();
  initHUD();  
  initLevel1();  
  initCharacter();
  startLevel();
  while(_character.status != cs_dead)
  {    
    updateCharacter();    
    if(g->time == 1)
      updateSkeleton();
    if(g->time == 2)
    {      
      updateBat();  
      g->time = 0;
    }    
    drawCharacter();    
    drawSkeletons();
    drawBats();
    ++g->time;
    cpct_waitVSYNC();
    switchBuffers();
  }

  drawGameover();
  while(!cpct_isAnyKeyPressed_f())
    cpct_scanKeyboard_f();

  mainScreen();
}
