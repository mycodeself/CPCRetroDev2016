#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "../common.h"

typedef struct Vector2D
{
  u8 x, y;
} Vector2D;

typedef struct Body
{
  Vector2D pos;
  Vector2D size;
} Body;

typedef struct Velocity
{
  i8 x;
  i8 y;
} Velocity;

typedef struct DynamicBody
{
  Body body;
  Vector2D lastpos;   // last position
  Velocity vel;       // velocity
  u8 side;            // 1: right 0: left
} DynamicBody;

// Collision
u8 checkCollision(const Body* a, const Body* b);
u8 checkCollisionSide(const Body* a, const Body* b);
void blockCollisions();

#endif