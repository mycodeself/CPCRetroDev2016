#include "level1.h"
#include "level1_1_map.h"
#include "level1_2_map.h"

#define MAP1_NUM_SKELETONS	2

Skeleton _skeleton0[MAP1_NUM_SKELETONS];

// Level 0 maps
const LevelMap _level1_maps[2] = { 
	{ LEVEL1_1, { _skeleton0, 0, MAP1_NUM_SKELETONS } }, 
	{ LEVEL1_2, { 0, 0, 0 } } 
};

// Level 1
const Level _level1 = { _level1_maps, 0, 1 };


void
initLevel1()
{
	Level* l = &_level1;
	// map0
	Skeleton *s = _skeleton0;
	// init skeletons
	cpct_memcpy ((void*)s, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s->de.x[0]	= 20;
	++s;

	cpct_memcpy ((void*)s, (void*)&_skeleton_template, sizeof(Skeleton)); 
	s->de.x[0]	= 70;
	++s;

	 // cpct_memcpy ((void*)s, (void*)&_skeleton_template, sizeof(Skeleton)); 
	 // s->de.x[0]	= 30;
	 // ++s;	

	// init level
	l->lm 	= _level1_maps;
  	l->idx 	= 0;
}