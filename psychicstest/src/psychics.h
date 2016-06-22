#ifndef _PSYCHICS_H_
#define _PSYCHICS_H_

#include <types.h>
#include <math.h>
#include <stdio.h>

typedef struct Vector2D{
	i16 x;
	i16 y;
}Vector2D;

typedef struct Box {
	Vector2D min;
	Vector2D max;
}Box;

typedef struct Body {
	Box position;
	Vector2D velocity;
}Body;



f32 EuclideanDistance(const Vector2D *a, const Vector2D *b);

//Collision
u8 AABB_BoxCollision(const Box *a, const Box *b);



#endif