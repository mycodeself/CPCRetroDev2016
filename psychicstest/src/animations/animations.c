#include "animations.h"

void
updateAnimation(Animation* anim)
{
  if(anim->status == as_play) {

    if(anim->time == anim->frames[anim->frame_idx]->time) {
      anim->time = 0;
      ++anim->frame_idx;
      if(anim->frame_idx == anim->numframes)
        anim->frame_idx = 0;
    } else {
      ++anim->time;
    }
    if(anim->side != anim->frames[anim->frame_idx]->side) {
      cpct_hflipSpriteM0(anim->frames[anim->frame_idx]->size_x, anim->frames[anim->frame_idx]->size_y,
                         anim->frames[anim->frame_idx]->sprite);
      anim->frames[anim->frame_idx]->side = anim->side;
    }
  }
}