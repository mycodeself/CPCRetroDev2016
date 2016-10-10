#include "game.h"

const Game _game = { &_level0, 0, gs_play };

void
game()
{
  u8 lastscore = 0; // last score, for draw the score when change
  startLevel();
  drawHUD();
  // drawScore();
  // drawEmeralds();
  while(_character.status != cs_dead) {
    cpct_waitVSYNC();
    //drawCharacter();
    drawBat();    
    //updateCharacter();
    //updateBat(&_bat);
    // if(_game.score != lastscore) {
    //   drawScore();
    //   lastscore = _game.score;
    // }
  }
}
