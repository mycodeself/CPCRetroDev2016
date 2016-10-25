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
#ifndef _BAT_H_
#define _BAT_H_

#include "../common.h"
#include "../animations/animations.h"

typedef enum { bs_fly, bs_hurt, bs_dead } BatStatus;

typedef struct Bat 
{
	Entity		e;
	Animation 	anim;
	BatStatus	status;
	BatStatus	lstatus;	// last status
	u8 			hp;			// health points
} Bat;

typedef struct BatArray {
	Bat* 		current;
	u8 			idx;
	u8 			num;
	Bat*		nearest;
	u8			min_dist;
} BatArray;

extern const Bat _bat_template;

void updateBat();
void drawBats();
void killBat(Bat* b) __z88dk_fastcall;

#endif