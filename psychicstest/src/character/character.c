#include "character.h"

const TCharacter _character = {
	{
		{
			{CHARACTER_START_X, CHARACTER_START_Y}, 	// min	
			{17, 180}, 	// max
			{CHARACTER_IDLE_0_SIZE_X, CHARACTER_IDLE_0_SIZE_Y}, 	// size
		}, // AABB Box
		{0,0}, // velocity
	}, // DynamicBody	 
	{cs_idle}, //status
	{cs_idle}, //last_status
	CPCT_VMEM_START, // pvmem
	&_character_animation // Animation
};


void characterController()
{
	TCharacter *c = &_character;
	cpct_scanKeyboard_f();
	// jump
	if(cpct_isKeyPressed(Key_Space) && c->status != cs_jump)
	{
		c->body.velocity.y += JUMP_FORCE;
		c->status 			= cs_jump;
	}
	// lateral move
	if(cpct_isKeyPressed(Key_CursorRight))
	{
		c->body.velocity.x += 1;
		c->status			= cs_walk_right;
	}else if(cpct_isKeyPressed(Key_CursorLeft))
	{
		c->body.velocity.x -= 1;
		c->status			= cs_walk_left;
	}
}

void updateCharacter()
{
	TCharacter *c = &_character;

	c->body.lastpos.x 	= c->body.box.min.x;
	c->body.lastpos.y	= c->body.box.min.y;
	c->body.velocity.x	= 0;
	c->last_status 		= c->status;
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
	/*if(c->body.box.max.y == GROUND_POSITION_Y){
		c->status 			= cs_idle;	
		c->body.velocity.y 	= 0;
	}*/	
	if(c->body.velocity.x == 0) 
		if(c->status == cs_walk_left || c->status == cs_walk_right)
			c->status = cs_idle;
	
	updateCharacterAnimation();
		
}

void updateCharacterAnimation()
{
	TCharacter*		c 	= 	&_character;
	AnimationFrame* frame;
	if(c->status != c->last_status)
	{
		switch(c->status)
		{
			case cs_idle: 	
				c->anim->frames 	= 	(AnimationFrame**) _character_anim_idle;
				c->anim->numframes	=	CHARACTER_IDLE_ANIM_FRAMES;
				break;
			case cs_walk_right:
				c->anim->frames = (AnimationFrame**) _character_anim_walk;
				c->anim->numframes	=	CHARACTER_WALK_ANIM_FRAMES;
				break;
		}
		c->anim->status 		=	as_play;
		c->anim->frame_idx		=	0;
	}
	
	updateAnimation(c->anim);
	
	frame = c->anim->frames[c->anim->frame_idx];
	c->body.box.size.x 	=	frame->size_x;
	c->body.box.size.y 	=	frame->size_y;
	c->body.box.max.x 	=	c->body.box.min.x + c->body.box.size.x;
	c->body.box.max.y 	=	c->body.box.min.y + c->body.box.size.y;
}