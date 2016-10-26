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
  Game* g = &_game;
  cpct_memset((u8*)0x8000, 0, 0x4000);
  cpct_memset((u8*)0xC000, 0, 0x4000);
  g->lvl    = &_level1;
  g->lvlidx = 0;
  g->gs     = gs_play;
  g->time   = 0;
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
}
