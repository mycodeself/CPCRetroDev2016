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
#include "../../utils/utils.h"

#define NUM_MAPS 			2
///////////////////////////////////////////////////////////////////////////////////////////////////////
// MAP1
#define MAP1_NUM_SKELETONS	1
Skeleton _skeletons1_1[MAP1_NUM_SKELETONS];
///////////////////////////////////////////////////////////////////////////////////////////////////////
// MAP2
#define MAP2_NUM_SKELETONS	1
#define MAP2_NUM_BATS		1
Skeleton _skeletons1_2[MAP2_NUM_SKELETONS];
Bat _bats1_2[MAP2_NUM_BATS];
///////////////////////////////////////////////////////////////////////////////////////////////////////
// MAP3
#define MAP3_NUM_BATS 	1
Bat _bats1_3[MAP3_NUM_BATS];
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Level 1
const Map _maps_level1[NUM_MAPS] = { 
	{ 
		MAP1_1, 
		{ _skeletons1_1, 0, MAP1_NUM_SKELETONS, 0, 255 },
		{ 0, 0, 0, 0, 0 } 
	}, 
	{ 
		MAP1_2, 
		{ _skeletons1_2, 0, MAP2_NUM_SKELETONS, 0, 255 },
		{ _bats1_2, 0, MAP2_NUM_BATS, 0, 255 } 
	}
};

const Level _level1 = { _maps_level1, 0, NUM_MAPS };
///////////////////////////////////////////////////////////////////////////////////////////////////////
void initEmeraldsLevel1();
///////////////////////////////////////////////////////////////////////////////////////////////////////

void
initLevel1()
{
	Level* l 		= &_level1;
	Skeleton *s1 	= _skeletons1_1;
	Skeleton *s2 	= _skeletons1_2;
	Bat* b2			= _bats1_2;
	Bat* b3 		= _bats1_3;
	// init map1
	cpct_memcpy ((void*)s1, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s1->e.x[0] = 50;	s1->e.x[1] = 50;	s1->e.x[2] = 50;

	// init map2
	cpct_memcpy ((void*)s2, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s2->e.x[0] = 70;	s2->e.x[1] = 70;	s2->e.x[2] = 70;

	cpct_memcpy ((void*)b2, (void*)&_bat_template, sizeof(Bat)); 
	b2->e.x[0] = 60;	b2->e.x[1] = 60;	b2->e.x[2] = 60;
	b2->e.y[0] = 70;	b2->e.y[1] = 70;	b2->e.y[2] = 70;

	// init map3
	cpct_memcpy ((void*)b3, (void*)&_bat_template, sizeof(Bat)); 
	b3->e.x[0] = 40;	b3->e.x[1] = 40;	b3->e.x[2] = 40;
	b3->e.y[0] = 94;	b3->e.y[1] = 94;	b3->e.y[2] = 94;

	// init emeralds
	initEmeraldsLevel1();
	// init level
	l->m 	= _maps_level1;
  	l->idx 	= 0;
  	l->num 	= NUM_MAPS;
}

void
initEmeraldsLevel1()
{
	// map1
	u8 *m = MAP1_1 + 523; 	initEmerald(m);
	m = MAP1_1 + 227;		initEmerald(m);	
	m = MAP1_1 + 347;		initEmerald(m);
	m = MAP1_1 + 214;		initEmerald(m);
	m = MAP1_1 + 217;		initEmerald(m);
	m = MAP1_1 + 908;		initEmerald(m);
	m = MAP1_1 + 788;		initEmerald(m);
	m = MAP1_1 + 771;		initEmerald(m);
	m = MAP1_1 + 780;		initEmerald(m);
	m = MAP1_1 + 697;		initEmerald(m);	
	m = MAP1_1 + 694;		initEmerald(m);	
	// map2
	m = MAP1_2 + 463;		initEmerald(m);
	m = MAP1_2 + 577;		initEmerald(m);
	m = MAP1_2 + 590;		initEmerald(m);
	m = MAP1_2 + 697;		initEmerald(m);
	m = MAP1_2 + 708;		initEmerald(m);	
	m = MAP1_2 + 755;		initEmerald(m);	
	m = MAP1_2 + 830;		initEmerald(m);	
	m = MAP1_2 + 875;		initEmerald(m);
	m = MAP1_2 + 995;		initEmerald(m);		
	m = MAP1_2 + 1051;		initEmerald(m);	
	m = MAP1_2 + 1064;		initEmerald(m);		
	m = MAP1_2 + 1115;		initEmerald(m);		
	m = MAP1_2 + 1243;		initEmerald(m);	
	m = MAP1_2 + 1246;		initEmerald(m);	
	m = MAP1_2 + 1258;		initEmerald(m);	
	// map3	
	m = MAP1_3 + 991;		initEmerald(m);	
	m = MAP1_3 + 1111;		initEmerald(m);		
	m = MAP1_3 + 1208;		initEmerald(m);		
	m = MAP1_3 + 1211;		initEmerald(m);	
	m = MAP1_3 + 1214;		initEmerald(m);	
	m = MAP1_3 + 1222;		initEmerald(m);	
}
