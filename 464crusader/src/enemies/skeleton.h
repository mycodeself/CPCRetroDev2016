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
#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "../common.h"
#include "../animations/animations.h"

typedef enum { ss_walk, ss_hurt, ss_dead, ss_attack, ss_dying } SkeletonStatus;

typedef struct Skeleton 
{
	Entity			e;
	Animation 		anim;
	SkeletonStatus	status;
	SkeletonStatus	lstatus;	// last status
	u8 				hp;			// health points
} Skeleton;

typedef struct SkeletonArray {
	Skeleton* 	current;
	u8 			idx;
	u8 			num;
	Skeleton* 	nearest;
	u8 			min_dist;
} SkeletonArray;

extern const Skeleton _skeleton_template;

void updateSkeleton();
void drawSkeletons();
void hurtSkeleton(Skeleton *s) __z88dk_fastcall;


#endif