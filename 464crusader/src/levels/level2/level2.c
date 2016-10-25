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