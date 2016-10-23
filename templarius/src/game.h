#ifndef _GAME_H_
#define _GAME_H_

#include <cpctelera.h>
#include "levels/level.h"

typedef enum { gs_play, gs_pause, gs_gameover } GameStatus;

typedef struct Game 
{
  Level* 		lvl;       	// Current level
  u8 			lvlidx;     // Level index
  GameStatus 	gs;    		// GameStatus
  u8			time;
} Game;

extern const Game _game;

void game();

#endif