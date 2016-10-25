#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "../common.h"

typedef struct Velocity
{
  i8 x;
  i8 y;
} Velocity;

typedef struct Collision
{
	u8 x[2], y[2];
	u8 w[2], h[2];
	u8 collision;
} Collision;

extern const Collision _col;

void checkCollision(Collision* c);

#endif