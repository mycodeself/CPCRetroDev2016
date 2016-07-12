#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../common.h"
#include "../physics/physics.h"

typedef enum {
	s_idle,
	s_jump
}Status;

typedef struct TCharacter  
{
	DynamicBody body;
	Status status;
	u8* p_vmem;
	
}TCharacter;

extern const TCharacter _character;

void characterController();
void updateCharacter();

#endif