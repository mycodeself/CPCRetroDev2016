#include "level0.h"
#include "level0_1_map.h"
#include "level0_2_map.h"

Skeleton _skeleton0[2];

// Level 0 maps
const LevelMap _level0_maps[2] = { 
	{ LEVEL0_1, { _skeleton0, 0, 2 } }, 
	{ LEVEL0_2, { 0, 0, 0 } } 
};

// Level 0
const Level _level0 = { _level0_maps, 0, 1 };


void
initLevel0()
{
	Level* l = &_level0;
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
	l->lm 	= _level0_maps;
  	l->idx 	= 0;
}