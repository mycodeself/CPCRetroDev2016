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
#include "level1.h"
#include "map1_1.h"
#include "map1_2.h"
#include "map1_3.h"
#include "../../animations/animations.h"

#define NUM_MAPS 			3
// MAP1
#define MAP1_NUM_SKELETONS	1
#define MAP1_NUM_BATS		1
Skeleton _skeletons1_1[MAP1_NUM_SKELETONS];
Bat _bats1_1[MAP1_NUM_BATS];

// MAP2
#define MAP2_NUM_SKELETONS	1
Skeleton _skeletons1_2[MAP2_NUM_SKELETONS];

// MAP3
#define MAP3_NUM_BATS 	1
Bat _bats1_3[MAP3_NUM_BATS];
// Level 1
const Map _maps_level1[NUM_MAPS] = { 
	{ 
		MAP1_1, 
		{ _skeletons1_1, 0, MAP1_NUM_SKELETONS, 0, 255 },
		{ _bats1_1, 0, MAP1_NUM_BATS, 0, 255 } 
	}, 
	{ 
		MAP1_2, 
		{ _skeletons1_2, 0, MAP2_NUM_SKELETONS, 0, 255 },
		{ 0, 0, 0, 0, 0 } 
	},
	{
		MAP1_3,
		{ 0, 0, 0 },
		{ _bats1_3, 0, MAP3_NUM_BATS, 0, 255 }
	} 
};

// Level 1
const Level _level1 = { _maps_level1, 0, NUM_MAPS };


void
initLevel1()
{
	Level* l = &_level1;
	// map0
	Skeleton *s1 = _skeletons1_1;
	Skeleton *s2 = _skeletons1_2;
	Bat* b1	= _bats1_1;
	Bat* b3 = _bats1_3;
	// init skeletons map1
	cpct_memcpy ((void*)s1, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s1->e.x[0]		= 52;
	s1->anim.side	= as_right;
	++s1;

	cpct_memcpy ((void*)s1, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s1->e.x[0]	= 70;
	++s1;

	// init skeletons map2
	cpct_memcpy ((void*)s2, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s2->e.x[0]	= 70;
	s2->e.grid  = 3;	

	cpct_memcpy ((void*)b1, (void*)&_bat_template, sizeof(Bat)); 
	b1->e.x[0] = 40;		b1->e.x[1] = 40;		b1->e.x[2] = 40;
	b1->e.y[0] = 80;		b1->e.y[1] = 80;		b1->e.y[2] = 80;

	cpct_memcpy ((void*)b3, (void*)&_bat_template, sizeof(Bat)); 
	b3->e.x[0] = 40;		b3->e.x[1] = 40;		b3->e.x[2] = 40;
	b3->e.y[0] = 120;		b3->e.y[1] = 120;		b3->e.y[2] = 120;

	// init level
	l->m 	= _maps_level1;
  	l->idx 	= 0;
}