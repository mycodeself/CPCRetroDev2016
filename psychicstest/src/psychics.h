#ifndef _PSYCHICS_H_
#define _PSYCHICS_H_

#include <types.h>
#include <math.h>
#include <stdio.h>

#define GRAVITY_FORCE 	4
#define JUMP_FORCE		-15

#define COLLISION_SIDE_BOTTOM 	0
#define COLLISION_SIDE_LEFT 	1
#define COLLISION_SIDE_RIGHT	2
#define COLLISION_SIDE_TOP		3

typedef struct Vector2D{
	u8 x;
	u8 y;
}Vector2D;

typedef struct Box {
	Vector2D min;
	Vector2D max;
}Box;

typedef struct Body {
	Box box;
	Vector2D velocity;
	Vector2D size;
}Body;


f32 EuclideanDistance(const Vector2D *a, const Vector2D *b);

//Collision
u8 AABB_BoxCollision(const Box *a, const Box *b);
u8 checkBodyCollisionSide(const Body *a, const Body *b);

#endif