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
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../common.h"
#include "../physics/physics.h"
#include "../animations/animations.h"

typedef enum { cs_idle, cs_jump, cs_walk, cs_fall, cs_dead, cs_attack, cs_endattack, cs_hurt } CharacterStatus;

typedef struct Character {
  Entity 			e;				// Drawing properties
  CharacterStatus 	status;			// Status 
  CharacterStatus 	lstatus;		// Last status
  Animation* 		anim;			// Animation
  Velocity 			vel;
  u8 				hp;
  u8 				ground;			// 0 is not in ground, 1 is in ground
} Character;						

extern Character _character;

void initCharacter();
void updateCharacter();
void drawCharacter();
void doCharacterAction(CharacterStatus status) __z88dk_fastcall;

#endif