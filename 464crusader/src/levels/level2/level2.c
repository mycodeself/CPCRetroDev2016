#include "level2.h"
#include "map2_1.h"
#include "map2_2.h"

#define NUM_MAPS 			2
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
	}
};

// Level 1
const Level _level2 = { _maps_level2, 0, NUM_MAPS };