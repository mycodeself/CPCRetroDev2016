#include "animations.h"

/////////////////// MAIN CHARACTER ANIMATIONS ///////////////////
const AnimationFrame _character_frames[3] = {
	// sprite, width bytes, height bytes	
	{_character_sprite_idle, CHARACTER_IDLE_0_SIZE_X, CHARACTER_IDLE_0_SIZE_Y}, 
	{_character_walk_0, CHARACTER_WALK_0_SIZE_X, CHARACTER_WALK_0_SIZE_Y},
	{_character_walk_1, CHARACTER_WALK_1_SIZE_X, CHARACTER_WALK_1_SIZE_Y}
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
	_character_anim_idle, 0, 1, as_end
};
//////////////////////////////////////////////////////////////////

void updateAnimation(Animation* anim)
{
	if(anim->status == as_play)
	{
		++anim->frame_idx;
		if(anim->frame_idx == anim->numframes)
			anim->frame_idx = 0;
	}
}