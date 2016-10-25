#include "physics.h"

const Collision _col = {
	{0, 0}, {0, 0},
	{0, 0}, {0, 0},
	0
};

void
checkCollision(Collision* c)
{
  if((c->x[0] + c->w[0]) < c->x[1] || c->x[0] > (c->x[1] + c->w[1]))
  	c->collision = 0;
  else if((c->y[0] + c->h[0]) < c->y[1] || c->y[0] > (c->y[1] + c->h[1]))
    c->collision = 0;
  else c->collision = 1;
}

//
//u8 checkCollisionSide(const AABB *a, const AABB *b)
//{
//	u8 bottom		= b->max.y - a->min.y;
//	u8 top	= a->max.y - b->min.y;
//	u8 left	= a->max.x - b->min.x;
//	u8 right		= b->max.x - a->min.x;
//	if (top < bottom && top < left && top < right )
//	{                           
//		//Top collision
//		return COLLISION_SIDE_TOP;
//	}
//	if (bottom < top && bottom < left && bottom < right)                        
//	{
//		//bottom collision
//		return COLLISION_SIDE_BOTTOM;
//	}
//	if (left < right && left < top && left < bottom)
//	{
//		//Left collision
//		return COLLISION_SIDE_LEFT;
//	}
//	if (right < left && right < top && right < bottom )
//	{
//		//Right collision
//		return COLLISION_SIDE_RIGHT;
//	}
//
//}

