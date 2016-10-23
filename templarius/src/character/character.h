#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../common.h"
#include "../physics/physics.h"
#include "../animations/animations.h"

typedef enum { cs_idle, cs_jump, cs_walk, cs_fall, cs_dead, cs_attack, cs_endattack, cs_hurt } CharacterStatus;

typedef struct Character {
  Entity 			e;				// Drawing properties
  CharacterStatus 	status;			// Status 
  CharacterStatus 	lstatus;		// Last status
  Animation* 		anim;			// Animation
  Velocity 			vel;
  u8 				hp;
  u8 				ground;			// 0 is not in ground, 1 is in ground
} Character;						

extern Character _character;

void initCharacter();
void updateCharacter();
void drawCharacter();
void doCharacterAction(CharacterStatus status) __z88dk_fastcall;

#endif