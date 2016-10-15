#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../animations/animations.h"
#include "../draw/draw.h"
#include "../physics/physics.h"

#define MAX_JUMP_H -12
#define JUMP_FORCE 4

// CHARACTER NUMBER OF FRAMES PER ANIM
#define CHARACTER_IDLE_ANIM_FRAMES		1
#define CHARACTER_WALK_ANIM_FRAMES		4
#define CHARACTER_JUMP_ANIM_FRAMES		1
#define CHARACTER_ATTACK_ANIM_FRAMES	1

// START POSITION OF CHARACTER
#define CHARACTER_VMEM_START cpctm_screenPtr(CPCT_VMEM_START, 5, 160)


typedef enum { cs_idle, cs_jump, cs_walk, cs_fall, cs_dead, cs_attack, cs_endattack } CharacterStatus;

typedef struct Character {
  DrawableEntity 	de;				// Drawing properties
  CharacterStatus 	status;			// Status 
  CharacterStatus 	last_status;	// Last status
  Animation* 		anim;			// Animation
  Velocity 			vel;
} Character;						

extern Character _character;

void initCharacter();
void updateCharacter();

#endif