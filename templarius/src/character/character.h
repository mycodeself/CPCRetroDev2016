#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../common.h"
#include "../animations/animations.h"
#include "../physics/physics.h"

typedef enum { cs_idle, cs_jump, cs_walk, cs_fall, cs_dead, cs_attack, cs_endattack } CharacterStatus;

typedef struct Character {
  Entity 			e;				// Drawing properties
  CharacterStatus 	status;			// Status 
  CharacterStatus 	lstatus;		// Last status
  Animation* 		anim;			// Animation
  Velocity 			vel;
  u8 				hp;
} Character;						

extern Character _character;

void initCharacter();
void updateCharacter();
void drawCharacter();
void hurtCharacter();

#endif