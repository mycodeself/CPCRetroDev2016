#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../common.h"
#include "../physics/physics.h"
#include "../animations/animations.h"

typedef enum {
	cs_idle,
	cs_jump,
	cs_walk_right,
	cs_walk_left,
	cs_jump_right,
	cs_jump_left
}CharacterStatus;

typedef struct TCharacter  
{
	DynamicBody 	body;
	CharacterStatus status;
	CharacterStatus last_status;
	u8* 			p_vmem;
	Animation* 		anim;
}TCharacter;

extern const TCharacter _character;

void characterController();
void updateCharacter();
void updateCharacterAnimation();


#endif