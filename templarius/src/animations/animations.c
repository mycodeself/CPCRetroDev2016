#include "animations.h"


void
updateAnimation(Animation* anim)
{
  AnimationFrame* frame;
  if(anim->time == 0)
  {
    switch(anim->status)
    {
      case as_cycle:                    
          ++anim->frame_idx;
          if(anim->frame_idx == anim->numframes)
            anim->frame_idx = 0;
          frame = anim->frames[anim->frame_idx];
          anim->time = frame->time;
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
    --anim->time;
  }
}