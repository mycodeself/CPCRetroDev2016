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
#include "level2.h"
#include "map2_1.h"
#include "map2_2.h"
#include "map2_3.h"

#define NUM_MAPS 			3
// MAP1

// Maps
const Map _maps_level2[NUM_MAPS] = { 
	{ 
		MAP2_1, 
		{ 0, 0, 0 },
		{ 0, 0, 0 } 
	}, 
	{ 
		MAP2_2, 
		{ 0, 0, 0 },
		{ 0, 0, 0 } 
	},
	{
		MAP2_3,
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	}
};

// Level 1
const Level _level2 = { _maps_level2, 0, NUM_MAPS };

void
initLevel2()
{
	Level* l = &_level2;
	// map0

	// init level
	l->m 	= _maps_level2;
  	l->idx 	= 0;
}