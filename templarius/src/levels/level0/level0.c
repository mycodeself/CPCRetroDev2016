#include "level0.h"

// const Body _level0_1_emeralds[10] = {
//   {15, 85, 4, 8},
//   {15, 100, 4, 8},
//   {20, 100, 4, 8},
//   {25, 100, 4, 8},
//   {30, 100, 4, 8},
//   {35, 100, 4, 8},
//   {40, 100, 4, 8},
//   {45, 100, 4, 8},
//   {50, 100, 4, 8},
//   {55, 100, 4, 8},
// };

const Bat _level0_1_bats[2] = {
  {  
    {
      {
        30, 100,                        // position
        SPRITE_BAT0_W, SPRITE_BAT0_H    // size
      },                                // Body
      30, 100,                          // last position
      { 0, 0 },                         // velocity
    },                                  // DynamicBody
    &_bat_animation,
    bs_alive
  },
  {  
    {
      {
        60, 110,                        // position
        SPRITE_BAT0_W, SPRITE_BAT0_H    // size
      },                                // Body
      60, 110,                          // last position
      { 0, 0 },                         // velocity
    },                                  // DynamicBody
    &_bat_animation,
    bs_alive
  }
};

// Level 0 maps
const LevelMap _level0_maps[2] = { { LEVEL0_1, NULL, _level0_1_bats }, { LEVEL0_2, NULL, NULL } };

// Level 0
const Level _level0 = { _level0_maps, 0, 1 };


