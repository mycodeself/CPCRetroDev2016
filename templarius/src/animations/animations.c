#include "animations.h"


void
updateAnimation(Animation* anim)
{
  if(anim->time == anim->frames[anim->frame_idx]->time)
  {
    switch(anim->status)
    {
      case as_cycle:
          anim->time = 0;
          ++anim->frame_idx;
          if(anim->frame_idx == anim->numframes)
            anim->frame_idx = 0;
        break;
      case as_play:
        ++anim->frame_idx;
        if(anim->frame_idx == anim->numframes)
        {
          anim->status = as_end;
          --anim->frame_idx;
        }
        break;
    }
  }else{
    ++anim->time;
  }
  
  // if(anim->side != anim->frames[anim->frame_idx]->side) {
  //   cpct_hflipSpriteM0(anim->frames[anim->frame_idx]->w, anim->frames[anim->frame_idx]->h,
  //                       anim->frames[anim->frame_idx]->sprite);
  //   anim->frames[anim->frame_idx]->side = anim->side;
  // }
}