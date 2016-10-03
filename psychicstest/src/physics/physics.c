#include "physics.h"

/*
 * AABB Collision for boxes
 * return 0 if no collision
 *        1 overlapping
 */
u8 checkCollision(const Body *a, const Body *b)
{
  if((a->pos.x + a->size.x) < b->pos.x || a->pos.x > (b->pos.x + b->size.x))
    return 0;
  if((a->pos.y + a->size.y) < b->pos.y || a->pos.y > (b->pos.y + b->size.y))
    return 0;
  return 1;
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

//void
//blockCollisions()
//{
//  AABB* platform = &_platform;
//  TCharacter* character = &_character;
//  if(AABB_BoxCollision(&character->body.box, platform))
//    {
//      switch(checkCollisionSide(platform, &character->body.box))
//        {
//        case COLLISION_SIDE_BOTTOM:
//          character->status = cs_idle;
//          character->body.velocity.y = 0;
//          character->body.box.max.y = platform->min.y;
//          character->body.box.min.y = platform->min.y - character->body.box.size.y;
//          break;
//        case COLLISION_SIDE_TOP:
//          character->body.velocity.y = 0;
//          character->body.box.min.y = platform->max.y + 1;
//          character->body.box.max.y = character->body.box.min.y + character->body.box.size.y;
//          break;
//        case COLLISION_SIDE_RIGHT:
//          character->body.box.max.x = platform->min.x;
//          character->body.box.min.x = platform->min.x - character->body.box.size.x;
//          character->body.velocity.x = 0;
//          break;
//        case COLLISION_SIDE_LEFT:
//          character->body.box.min.x = platform->max.x;
//          character->body.box.max.x = platform->max.x + character->body.box.size.x;
//          character->body.velocity.x = 0;
//          break;
//        }
//    }
//}