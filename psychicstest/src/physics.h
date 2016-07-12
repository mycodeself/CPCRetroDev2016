#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "common.h"

f32 EuclideanDistance(const Vector2D *a, const Vector2D *b);

//Collision
u8 AABB_BoxCollision(const AABB *a, const AABB *b);

u8 checkCollisionSide(const AABB *a, const AABB *b);

#endif