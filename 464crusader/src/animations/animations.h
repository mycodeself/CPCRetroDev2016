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
#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_

#include <cpctelera.h>

typedef enum { as_play, as_cycle, as_end } AnimationStatus;

typedef enum { as_right, as_left } AnimationSide;

typedef struct AnimationFrame {
  u8* sprite;
  u8 w, h; // bytes
  u8 time;
  AnimationSide side;
} AnimationFrame;

typedef struct Animation {
  AnimationFrame** frames;
  u8 frame_idx;
  u8 numframes;
  AnimationStatus status;
  u8 time;
  AnimationSide side;
} Animation;

void updateAnimation(Animation* anim);

#endif