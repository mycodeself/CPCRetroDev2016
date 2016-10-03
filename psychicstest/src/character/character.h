#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../animations/animations.h"
#include "../common.h"
#include "../levels/level0/level0.h"
#include "../physics/physics.h"
#include "../utils/utils.h"
#include "sprites/idle.h"
#include "sprites/walk0.h"
#include "sprites/walk1.h"

#define MAX_JUMP_H -12
#define JUMP_FORCE 4

// CHARACTER NUMBER OF FRAMES PER ANIM
#define CHARACTER_IDLE_ANIM_FRAMES 1
#define CHARACTER_WALK_ANIM_FRAMES 2

#define CHARACTER_VMEM_START cpctm_screenPtr(CPCT_VMEM_START, LEVEL0_START_POSITION_X, LEVEL0_START_POSITION_Y)

// CHARACTER START POSITION
#define CHARACTER_START_X 10
#define CHARACTER_START_Y 100

typedef enum { cs_idle, cs_jump, cs_walk, cs_fall, cs_dead } CharacterStatus;

typedef struct TCharacter {
  DynamicBody db;
  CharacterStatus status;
  CharacterStatus last_status;
  u8* p_vmem;
  Animation* anim;
} TCharacter;

extern const TCharacter _character;

void updateCharacter();
void drawCharacter();
void eraseCharacter();
void updateCharacterAnimation();

#endif