#ifndef _GAME_H_
#define _GAME_H_

#include <cpctelera.h>
#include "levels/level.h"

typedef enum { gs_play, gs_pause, gs_gameover } GameStates;

typedef struct Game 
{
  Level* lvl;       // Current level
  u8 lvl_idx;       // Level index
  GameStates gs;    // GameState
} Game;

extern const Game _game;

extern u8* _screenMem;
extern u8* _backBuffer;

void game();

#endif