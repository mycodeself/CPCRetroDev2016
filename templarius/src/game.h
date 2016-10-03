#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include "levels/level.h"
#include "levels/level0/level0.h"
#include "character/character.h"
#include "enemies/bat.h"
#include "draw/draw.h"

typedef enum { gs_play, gs_pause, gs_gameover } GameStates;

typedef struct Game 
{
  Level* lvl;       // Current level
  u8 lvl_idx;       // Level index
  GameStates gs;    // GameState
  u16 score;        // Score
} Game;

extern const Game _game;

void game();

#endif