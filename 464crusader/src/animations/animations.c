/*  
 *
 *  This file is part of 464 Crusader, game for Amstrad CPC 464.
 *
 *  464 Crusader is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  464 Crusader is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 464 Crusader.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
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