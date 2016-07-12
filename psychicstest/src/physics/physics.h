#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "../common.h"

// structs
typedef struct Vector2D{
	u8 x;
	u8 y;
}Vector2D;

typedef struct AABB {
	Vector2D min;		// min position (top-left corner)
	Vector2D max;		// max position (bottom-right corner)
	Vector2D size;		// size
}AABB;

typedef struct DynamicBody {
	AABB box;			// AABB Box
	Vector2D velocity;	// velocity
	Vector2D lastpos;	// last position
}DynamicBody;

//Collision
u8 AABB_BoxCollision(const AABB *a, const AABB *b);
u8 checkCollisionSide(const AABB *a, const AABB *b);

#endif