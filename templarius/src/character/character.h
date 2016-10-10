#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../animations/animations.h"
#include "../common.h"
#include "../levels/level.h"
#include "../physics/physics.h"
#include "../utils/utils.h"
#include "sprites/character_walk0.h"
#include "sprites/character_walk1.h"
#include "sprites/character_walk2.h"

#define MAX_JUMP_H -12
#define JUMP_FORCE 4

// CHARACTER NUMBER OF FRAMES PER ANIM
#define CHARACTER_IDLE_ANIM_FRAMES 1
#define CHARACTER_WALK_ANIM_FRAMES 4

#define CHARACTER_VMEM_START cpctm_screenPtr(GAME_VMEM_PTR, LEVEL0_START_POSITION_X, LEVEL0_START_POSITION_Y)

typedef enum { cs_idle, cs_jump, cs_walk, cs_fall, cs_dead } CharacterStatus;

typedef struct Character {
  DynamicBody db;
  CharacterStatus status;
  CharacterStatus last_status;
  u8* p_vmem;
  Animation* anim;
} Character;

extern const Character _character;

void updateCharacter();

#endif