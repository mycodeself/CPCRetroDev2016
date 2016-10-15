#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "../animations/animations.h"
#include "../draw/draw.h"

typedef enum { ss_idle, ss_walk, ss_hurt, ss_dead } SkeletonStatus;

typedef struct Skeleton 
{
	DrawableEntity	de;
	Animation 		anim;
	SkeletonStatus	status;
	SkeletonStatus	lstatus;	// last status
	u8 				hp;			// health points
} Skeleton;

typedef struct Skeletons {
	Skeleton* 	current;
	u8 			idx;
	u8 			num;
} Skeletons;

extern const Skeleton _skeleton_template;

void
updateSkeleton();

#endif