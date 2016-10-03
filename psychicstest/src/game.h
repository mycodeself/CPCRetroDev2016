#ifndef _GAME_H_
#define _GAME_H_

#include <types.h>
#include "common.h"
#include "character/character.h"
#include "hud/hud.h"
#include "levels/level0/level0.h"
#include "utils/utils.h"
#include "draw/draw.h"
#include "levels/level0/level0.h"

typedef enum { gs_play, gs_pause, gs_gameover } GameStates;

typedef struct Game 
{
  Level* lvl;       // Current level
  u8 lvl_idx;       // Level index
  GameStates gs;    // GameState
} Game;

extern const Game _game;

void game();

#endif