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