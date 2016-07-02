#include "psychics.h"

f32 EuclideanDistance(const Vector2D *a, const Vector2D *b)
{
	return sqrtf(powf(a->x - b->x, 2)+powf(a->y - b->y, 2));
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

/*
 * 
 *
 */
u8 checkBodyCollisionSide(const Body *a, const Body *b)
{
	u8 ax_center 	= a->box.max.x - (a->size.x / 2);
	u8 ay_center 	= a->box.max.y - (a->size.y / 2);
	u8 bx_center 	= b->box.max.x - (b->size.x / 2);
	u8 by_center 	= b->box.max.y - (b->size.y / 2);
	u8 w 			= 0.5 * (a->size.x + b->size.x);
	u8 h 			= 0.5 * (a->size.y + b->size.y);
	u8 wy			= w * (ay_center - by_center);
	u8 hx 			= h * (ax_center - bx_center);
	/*if(wy > hx)
		if(wy > -hx)
			return COLLISION_SIDE_BOTTOM; // bottom collision
		else
			return COLLISION_SIDE_LEFT; // left collision
	else
		if(wy > -hx)
			return COLLISION_SIDE_RIGHT; // right
		else
			return COLLISION_SIDE_TOP; // top
			*/
		

}