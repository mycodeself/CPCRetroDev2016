#include "game.h"

const Game _game = {
  &_level0, 0, gs_play
};



void game()
{
  startLevel0();
  drawHUB();
  
//  while(_character.status != cs_dead) {
//
//    //    blockCollisions();
//    // cpct_waitVSYNC(); // second frame
//    //    drawBlock();
//    // drawCharacter();
//
//    cpct_waitVSYNC();      
//    drawCharacter(); 
//    //drawRewards();
//    updateCharacter(); 
//  }
}
