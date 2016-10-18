#include "level1.h"
#include "level1_1_map.h"
#include "level1_2_map.h"

#define NUM_MAPS 			2
#define MAP1_NUM_SKELETONS	2
#define MAP2_NUM_SKELETONS	1

Skeleton _skeleton1[MAP1_NUM_SKELETONS];
Skeleton _skeleton2[MAP2_NUM_SKELETONS];

// Level 0 maps
const LevelMap _level1_maps[NUM_MAPS] = { 
	{ LEVEL1_1, { _skeleton1, 0, MAP1_NUM_SKELETONS } }, 
	{ LEVEL1_2, { _skeleton2, 0, MAP2_NUM_SKELETONS } } 
};

// Level 1
const Level _level1 = { _level1_maps, 0, 1 };


void
initLevel1()
{
	Level* l = &_level1;
	// map0
	Skeleton *s1 = _skeleton1;
	Skeleton *s2 = _skeleton2;
	// init skeletons map1
	cpct_memcpy ((void*)s1, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s1->e.x[0]	= 24;
	s1->e.grid 	= 1;
	++s1;

	cpct_memcpy ((void*)s1, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s1->e.x[0]	= 70;
	s1->e.grid  = 3;
	++s1;

	// init skeletons map2
	cpct_memcpy ((void*)s2, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s2->e.x[0]	= 70;
	s2->e.grid  = 3;
	++s1;

	// init level
	l->lm 	= _level1_maps;
  	l->idx 	= 0;
}