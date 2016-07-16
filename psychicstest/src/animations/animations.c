#include "animations.h"

/////////////////// MAIN CHARACTER ANIMATIONS ///////////////////
const AnimationFrame _character_frames[3] = {
	// sprite, width bytes, height bytes, time, look
	{_character_sprite_idle, CHARACTER_IDLE_0_SIZE_X, CHARACTER_IDLE_0_SIZE_Y, 1, al_right}, 
	{_character_walk_0, CHARACTER_WALK_0_SIZE_X, CHARACTER_WALK_0_SIZE_Y, 3, al_right},
	{_character_walk_1, CHARACTER_WALK_1_SIZE_X, CHARACTER_WALK_1_SIZE_Y, 3, al_right}
};
// idle
AnimationFrame* const _character_anim_idle[1] = {
	&_character_frames[0]
};
// walk
AnimationFrame* const _character_anim_walk[2] = {
	&_character_frames[1], &_character_frames[2]
};
// start animation
const Animation _character_animation = {
	_character_anim_idle, 0, 1, as_play, 0, al_right, 
	CHARACTER_IDLE_0_SIZE_X, CHARACTER_IDLE_0_SIZE_Y
};
//////////////////////////////////////////////////////////////////

void updateAnimation(Animation* anim)
{
	if(anim->status == as_play)
	{
		anim->erase_x 	=	anim->frames[anim->frame_idx]->size_x;
		anim->erase_y	=	anim->frames[anim->frame_idx]->size_y;	
		if(anim->time == anim->frames[anim->frame_idx]->time)
		{				
			anim->time 		=	0;
			++anim->frame_idx;
			if(anim->frame_idx == anim->numframes)
				anim->frame_idx = 0;			
		}else{
			++anim->time;
		}
		if(anim->look != anim->frames[anim->frame_idx]->look)
		{
			cpct_hflipSpriteMaskedM0(anim->frames[anim->frame_idx]->size_x, 
										anim->frames[anim->frame_idx]->size_y, 
										anim->frames[anim->frame_idx]->sprite);
			
			anim->frames[anim->frame_idx]->look 	=	anim->look;
		}
		

	}
}