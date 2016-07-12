#include "physics.h"

f32 EuclideanDistance(const Vector2D *a, const Vector2D *b)
{
	return sqrtf(powf(a->x - b->x, 2)+powf(a->y - b->y, 2));
}

/*
 * AABB Collision for boxes
 * return 0 if no collision
 *        1 overlapping
 */
u8 AABB_BoxCollision(const AABB *a, const AABB *b)
{
	if(a->max.x < b->min.x || a->min.x > b->max.x)
		return 0;
	if(a->max.y < b->min.y || a->min.y > b->max.y)
		return 0;
	return 1;
}

u8 checkCollisionSide(const AABB *a, const AABB *b)
{
	u8 bottom		= b->max.y - a->min.y;
	u8 top	= a->max.y - b->min.y;
	u8 left	= a->max.x - b->min.x;
	u8 right		= b->max.x - a->min.x;
	if (top < bottom && top < left && top < right )
	{                           
		//Top collision
		return COLLISION_SIDE_TOP;
	}
	if (bottom < top && bottom < left && bottom < right)                        
	{
		//bottom collision
		return COLLISION_SIDE_BOTTOM;
	}
	if (left < right && left < top && left < bottom)
	{
		//Left collision
		return COLLISION_SIDE_LEFT;
	}
	if (right < left && right < top && right < bottom )
	{
		//Right collision
		return COLLISION_SIDE_RIGHT;
	}

}