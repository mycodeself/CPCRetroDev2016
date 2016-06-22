#include "psychics.h"

f32 EuclideanDistance(const Vector2D *a, const Vector2D *b)
{
	return sqrtf(powf(a->x - b->x, 2)+powf(a->y - b->y, 2));;
}

/*
 * AABB Collision for boxes
 * return 0 if no collision
 *        1 overlapping
 */
u8 AABB_BoxCollision(const Box *a, const Box *b)
{
	if(a->max.x < b->min.x || a->min.x > b->max.x)
		return 0;
	if(a->max.y < b->min.y || a->min.y > b->max.y)
		return 0;
	return 1;
}