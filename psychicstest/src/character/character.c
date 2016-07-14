#include "character.h"

const TCharacter _character = {
	{
		{
			{10, 136}, 	// min	
			{17, 180}, 	// max
			{CHARACTER_SPRITE_SIZE_X, CHARACTER_SPRITE_SIZE_Y}, 	// size
		}, // AABB Box
		{0,0}, // velocity
	}, // DynamicBody	 
	{s_idle}, //status
	CPCT_VMEM_START, // pvmem
};


void characterController()
{
	TCharacter *c = &_character;
	cpct_scanKeyboard_f();
	// jump
	if(cpct_isKeyPressed(Key_Space) && c->status != s_jump)
	{
		c->body.velocity.y += JUMP_FORCE;
		c->status 			= s_jump;
	}
	// lateral move
	if(cpct_isKeyPressed(Key_CursorRight))
	{
		c->body.velocity.x += 1;
	}else if(cpct_isKeyPressed(Key_CursorLeft))
	{
		c->body.velocity.x -= 1;
	}
}

void updateCharacter()
{
	TCharacter *c = &_character;

	c->body.lastpos.x 	= c->body.box.min.x;
	c->body.lastpos.y	= c->body.box.min.y;
	c->body.velocity.x	= 0;
 
	characterController();
	if(c->body.box.max.y < GROUND_POSITION_Y)
	{
		c->body.velocity.y	+= GRAVITY_FORCE;
	}
	c->body.box.min.y += c->body.velocity.y;
	c->body.box.max.y += c->body.velocity.y;
	c->body.box.min.x += c->body.velocity.x;
	c->body.box.max.x += c->body.velocity.x;
	if(c->body.box.max.y > GROUND_POSITION_Y)
	{
		c->body.box.min.y -= (c->body.box.max.y - GROUND_POSITION_Y);
		c->body.box.max.y -= (c->body.box.max.y - GROUND_POSITION_Y);
	}
	if(c->body.box.max.y == GROUND_POSITION_Y){
		c->status 			= s_idle;	
		c->body.velocity.y 	= 0;
	}
		
}