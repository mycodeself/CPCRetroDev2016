#ifndef _BAT_H_
#define _BAT_H_

#include "sprites/bat0.h"
#include "sprites/bat1.h"
#include "sprites/bat2.h"
#include "../physics/physics.h"
#include "../animations/animations.h"

typedef enum {bs_alive, bs_dead} BatStatus;

typedef struct Bat {
  DynamicBody db;
  Animation* anim;
  BatStatus status;
} Bat;

extern const Bat _bat;

void updateBat(Bat* bat);

#endif