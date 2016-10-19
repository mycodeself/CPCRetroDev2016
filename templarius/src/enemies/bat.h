#ifndef _BAT_H_
#define _BAT_H_

#include "../common.h"
#include "../animations/animations.h"

typedef enum { bs_fly, bs_hurt, bs_dead } BatStatus;

typedef struct Bat 
{
	Entity		e;
	Animation 	anim;
	BatStatus	status;
	BatStatus	lstatus;	// last status
	u8 			hp;			// health points
} Bat;

typedef struct BatArray {
	Bat* 		current;
	u8 			idx;
	u8 			num;
} BatArray;

extern const Bat _bat_template;

void updateBat();
void drawBats();

#endif