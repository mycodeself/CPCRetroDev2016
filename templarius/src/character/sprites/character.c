#include "character.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2015
// Tile sprite_character_00: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_00[8 * 20] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x50, 0x3c, 0x28, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xb4, 0x3c, 0x3c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xb4, 0x3c, 0x3c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x00,
	0x11, 0x33, 0x22, 0xb4, 0x28, 0x3c, 0x00, 0x00,
	0x33, 0x33, 0x33, 0xb4, 0x3c, 0x3c, 0x00, 0x00,
	0x33, 0x0f, 0x33, 0x8c, 0x1d, 0x0c, 0xf0, 0xa0,
	0x27, 0xcc, 0x1b, 0xb7, 0x3f, 0x3f, 0xf0, 0xf0,
	0x27, 0xcc, 0x1b, 0x8c, 0x1d, 0x0c, 0x00, 0xcc,
	0x33, 0x0f, 0x33, 0x8c, 0x1d, 0x0c, 0x00, 0x3c,
	0x33, 0x33, 0x33, 0xf3, 0xf3, 0xf3, 0x00, 0x3c,
	0x11, 0x33, 0x22, 0xa4, 0x59, 0x1c, 0x00, 0x63,
	0x00, 0x00, 0x00, 0xb4, 0x00, 0xb4, 0x00, 0x63,
	0x00, 0x00, 0x00, 0xb4, 0x00, 0xb4, 0x00, 0x63,
	0x00, 0x00, 0x00, 0xb4, 0x00, 0xb4, 0x00, 0x63,
	0x00, 0x00, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x63,
	0x00, 0x00, 0x00, 0xb4, 0x00, 0xb4, 0x00, 0x63,
	0x00, 0x00, 0x00, 0xf0, 0x28, 0xf0, 0x28, 0x82
};

// Tile sprite_character_01: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_01[8 * 20] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x3c, 0x28, 0x00, 0x41, 0x00,
	0x00, 0x00, 0xf0, 0x3c, 0x3c, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x3c, 0x3c, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x11, 0x82,
	0x11, 0x33, 0x72, 0x3c, 0x14, 0x00, 0x11, 0x82,
	0x33, 0x33, 0x33, 0x3c, 0x3c, 0x00, 0x11, 0x82,
	0x33, 0x0f, 0x33, 0x8c, 0x2e, 0x00, 0x11, 0x82,
	0x27, 0xcc, 0x1b, 0xb7, 0x3f, 0xf0, 0x9c, 0x28,
	0x27, 0xcc, 0x1b, 0x8c, 0x2e, 0xf0, 0x9c, 0x28,
	0x33, 0x0f, 0x33, 0x8c, 0x2e, 0x00, 0x00, 0x00,
	0x33, 0x33, 0x33, 0xf3, 0xf3, 0x00, 0x00, 0x00,
	0x11, 0x33, 0x72, 0x0c, 0xa6, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x28, 0xb4, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x28, 0xb4, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xb4, 0x00, 0xb4, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xb4, 0x00, 0xb4, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0x28, 0xf0, 0x28, 0x00, 0x00
};

// Tile sprite_character_02: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_02[8 * 20] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x00,
	0x00, 0x00, 0x50, 0x3c, 0x28, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x3c, 0x3c, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x3c, 0x3c, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x11, 0x82,
	0x00, 0x33, 0x33, 0x3c, 0x14, 0x00, 0x11, 0x82,
	0x11, 0x33, 0x33, 0x36, 0x3c, 0x00, 0x11, 0x82,
	0x11, 0x27, 0x1b, 0x66, 0x2e, 0xf0, 0x9c, 0x28,
	0x11, 0x4e, 0x8d, 0x73, 0x3f, 0xf0, 0x9c, 0x28,
	0x11, 0x4e, 0x8d, 0x66, 0x2e, 0x00, 0x00, 0x00,
	0x11, 0x27, 0x1b, 0x66, 0x2e, 0x00, 0x00, 0x00,
	0x11, 0x33, 0x33, 0x73, 0xf3, 0x00, 0x00, 0x00,
	0x00, 0x33, 0x33, 0x8c, 0xa6, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x78, 0x28, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x78, 0x28, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x44, 0xd8, 0x28, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x6c, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0xf0, 0x28, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x50, 0xb4, 0x00, 0x00, 0x00
};

// Tile sprite_character_03: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_03[8 * 20] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x00,
	0x00, 0x00, 0x50, 0x3c, 0x28, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x3c, 0x3c, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x3c, 0x3c, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x11, 0x82,
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x11, 0x82,
	0x00, 0x33, 0x33, 0x3c, 0x14, 0x00, 0x11, 0x82,
	0x11, 0x33, 0x33, 0x36, 0x3c, 0x00, 0x11, 0x82,
	0x11, 0x27, 0x1b, 0x66, 0x2e, 0xf0, 0x9c, 0x28,
	0x11, 0x4e, 0x8d, 0x73, 0x3f, 0xf0, 0x9c, 0x28,
	0x11, 0x4e, 0x8d, 0x66, 0x2e, 0x00, 0x00, 0x00,
	0x11, 0x27, 0x1b, 0x66, 0x2e, 0x00, 0x00, 0x00,
	0x11, 0x33, 0x33, 0x73, 0xf3, 0x00, 0x00, 0x00,
	0x00, 0x33, 0x33, 0x8c, 0xa6, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x78, 0x28, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x78, 0x28, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x6c, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x44, 0xd8, 0x28, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x78, 0xb4, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0xb4, 0x00, 0x00, 0x00, 0x00
};

// Tile sprite_character_04: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_04[8 * 20] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63,
	0x00, 0x00, 0x00, 0xb4, 0x3c, 0x00, 0x00, 0x63,
	0x00, 0x00, 0x50, 0xb4, 0x3c, 0x28, 0x00, 0x63,
	0x11, 0x33, 0x72, 0xb4, 0x3c, 0x28, 0x00, 0x63,
	0x33, 0x33, 0x33, 0xa0, 0x00, 0x00, 0x00, 0x63,
	0x33, 0x0f, 0x33, 0xa0, 0x00, 0x00, 0x00, 0x63,
	0x27, 0xcc, 0x1b, 0xb4, 0x28, 0x28, 0x00, 0x63,
	0x27, 0xcc, 0x1b, 0xb4, 0x3c, 0x78, 0xe4, 0x3c,
	0x33, 0x0f, 0x33, 0xcc, 0x1d, 0x58, 0xe4, 0x3c,
	0x33, 0x33, 0x33, 0xf3, 0x3f, 0x2a, 0x00, 0x00,
	0x11, 0x33, 0x66, 0x8c, 0x1d, 0x08, 0x00, 0x00,
	0x00, 0x00, 0x44, 0x8c, 0x1d, 0x08, 0x00, 0x00,
	0x00, 0x00, 0x51, 0xf3, 0xf3, 0xb6, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x0c, 0x59, 0x58, 0x28, 0x00,
	0x00, 0x00, 0x50, 0x28, 0x00, 0x50, 0x28, 0x00,
	0x00, 0x00, 0x50, 0x28, 0x00, 0x44, 0x88, 0x00,
	0x00, 0x00, 0xf0, 0x28, 0x00, 0x50, 0x28, 0x00,
	0x00, 0x50, 0x9c, 0x00, 0x00, 0x50, 0xb4, 0x00,
	0x00, 0x50, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Tile sprite_character_05: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_05[8 * 20] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xc3, 0xc3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x41, 0xc3, 0xc3, 0x82, 0x00, 0x08,
	0x00, 0x00, 0x41, 0xc3, 0xc3, 0x82, 0x00, 0x86,
	0x00, 0x00, 0x41, 0x86, 0x0c, 0x08, 0x00, 0x86,
	0x00, 0x00, 0x41, 0x86, 0x0c, 0x08, 0x00, 0x86,
	0x00, 0x00, 0x41, 0xc3, 0x86, 0x82, 0x00, 0x86,
	0x41, 0xc3, 0xc3, 0xc3, 0xc3, 0x82, 0x00, 0x86,
	0xc3, 0xc3, 0xc3, 0xc3, 0x86, 0xc3, 0x00, 0x86,
	0xc3, 0x0c, 0xc3, 0x0c, 0x0c, 0x0c, 0x00, 0x86,
	0x86, 0xc3, 0x49, 0xc3, 0x86, 0xc3, 0xc3, 0xc3,
	0x86, 0xc3, 0x49, 0xc3, 0x86, 0xc3, 0xc3, 0xc3,
	0xc3, 0x0c, 0xc3, 0xc3, 0x86, 0xc3, 0x00, 0x00,
	0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x00, 0x00,
	0x41, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x00, 0x00,
	0x00, 0x00, 0x41, 0x82, 0x00, 0x41, 0x82, 0x00,
	0x00, 0x00, 0xc3, 0x00, 0x00, 0x41, 0x82, 0x00,
	0x00, 0x00, 0xc3, 0x00, 0x00, 0x41, 0x82, 0x00,
	0x00, 0x41, 0x82, 0x00, 0x00, 0x41, 0x82, 0x00,
	0x00, 0x41, 0xc3, 0x00, 0x00, 0x41, 0xc3, 0x00
};

// Tile sprite_character_06: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_06[8 * 20] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x14, 0x3c, 0xa0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x3c, 0x3c, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x3c, 0x3c, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x3c, 0x14, 0x78, 0x11, 0x33, 0x22,
	0x00, 0x00, 0x3c, 0x3c, 0x78, 0x33, 0x33, 0x33,
	0x50, 0xf0, 0x0c, 0x2e, 0x4c, 0x33, 0x0f, 0x33,
	0xf0, 0xf0, 0x3f, 0x3f, 0x7b, 0x27, 0xcc, 0x1b,
	0xcc, 0x00, 0x0c, 0x2e, 0x4c, 0x27, 0xcc, 0x1b,
	0x3c, 0x00, 0x0c, 0x2e, 0x4c, 0x33, 0x0f, 0x33,
	0x3c, 0x00, 0xf3, 0xf3, 0xe6, 0x33, 0x33, 0x33,
	0x93, 0x00, 0x2c, 0xa6, 0x58, 0x11, 0x33, 0x22,
	0x93, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00, 0x00,
	0x93, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00, 0x00,
	0x93, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00, 0x00,
	0x93, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x00, 0x00,
	0x93, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00, 0x00,
	0x41, 0x14, 0xf0, 0x14, 0xf0, 0x00, 0x00, 0x00
};

// Tile sprite_character_07: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_07[8 * 20] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x82, 0x00, 0x14, 0x3c, 0xa0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x3c, 0x3c, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x3c, 0x3c, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x28, 0x3c, 0xb1, 0x33, 0x22,
	0x41, 0x22, 0x00, 0x3c, 0x3c, 0x33, 0x33, 0x33,
	0x41, 0x22, 0x00, 0x1d, 0x4c, 0x33, 0x0f, 0x33,
	0x14, 0x6c, 0xf0, 0x3f, 0x7b, 0x27, 0xcc, 0x1b,
	0x14, 0x6c, 0xf0, 0x1d, 0x4c, 0x27, 0xcc, 0x1b,
	0x00, 0x00, 0x00, 0x1d, 0x4c, 0x33, 0x0f, 0x33,
	0x00, 0x00, 0x00, 0xf3, 0xf3, 0x33, 0x33, 0x33,
	0x00, 0x00, 0x00, 0x59, 0x0c, 0xb1, 0x33, 0x22,
	0x00, 0x00, 0x00, 0x78, 0x14, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x78, 0x14, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00,
	0x00, 0x00, 0x14, 0xf0, 0x14, 0xf0, 0x00, 0x00
};

// Tile sprite_character_08: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_08[8 * 20] = {
	0x00, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x14, 0x3c, 0xa0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x3c, 0x3c, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x3c, 0x3c, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x28, 0x3c, 0x33, 0x33, 0x00,
	0x41, 0x22, 0x00, 0x3c, 0x39, 0x33, 0x33, 0x22,
	0x14, 0x6c, 0xf0, 0x1d, 0x99, 0x27, 0x1b, 0x22,
	0x14, 0x6c, 0xf0, 0x3f, 0xb3, 0x4e, 0x8d, 0x22,
	0x00, 0x00, 0x00, 0x1d, 0x99, 0x4e, 0x8d, 0x22,
	0x00, 0x00, 0x00, 0x1d, 0x99, 0x27, 0x1b, 0x22,
	0x00, 0x00, 0x00, 0xf3, 0xb3, 0x33, 0x33, 0x22,
	0x00, 0x00, 0x00, 0x59, 0x4c, 0x33, 0x33, 0x00,
	0x00, 0x00, 0x00, 0x14, 0xb4, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x14, 0xb4, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x14, 0xe4, 0x88, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x44, 0x9c, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x14, 0xf0, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x78, 0xa0, 0x00, 0x00, 0x00
};

// Tile sprite_character_09: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_09[8 * 20] = {
	0x00, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x14, 0x3c, 0xa0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x3c, 0x3c, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x3c, 0x3c, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
	0x41, 0x22, 0x00, 0x28, 0x3c, 0x33, 0x33, 0x00,
	0x41, 0x22, 0x00, 0x3c, 0x39, 0x33, 0x33, 0x22,
	0x14, 0x6c, 0xf0, 0x1d, 0x99, 0x27, 0x1b, 0x22,
	0x14, 0x6c, 0xf0, 0x3f, 0xb3, 0x4e, 0x8d, 0x22,
	0x00, 0x00, 0x00, 0x1d, 0x99, 0x4e, 0x8d, 0x22,
	0x00, 0x00, 0x00, 0x1d, 0x99, 0x27, 0x1b, 0x22,
	0x00, 0x00, 0x00, 0xf3, 0xb3, 0x33, 0x33, 0x22,
	0x00, 0x00, 0x00, 0x59, 0x4c, 0x33, 0x33, 0x00,
	0x00, 0x00, 0x00, 0x14, 0xb4, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x14, 0xb4, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x44, 0x9c, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x14, 0xe4, 0x88, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x78, 0xb4, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x78, 0xa0, 0x00, 0x00
};

// Tile sprite_character_10: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_10[8 * 20] = {
	0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x93, 0x00, 0x00, 0x3c, 0x78, 0x00, 0x00, 0x00,
	0x93, 0x00, 0x14, 0x3c, 0x78, 0xa0, 0x00, 0x00,
	0x93, 0x00, 0x14, 0x3c, 0x78, 0xb1, 0x33, 0x22,
	0x93, 0x00, 0x00, 0x00, 0x50, 0x33, 0x33, 0x33,
	0x93, 0x00, 0x00, 0x00, 0x50, 0x33, 0x0f, 0x33,
	0x93, 0x00, 0x14, 0x14, 0x78, 0x27, 0xcc, 0x1b,
	0x3c, 0xd8, 0xb4, 0x3c, 0x78, 0x27, 0xcc, 0x1b,
	0x3c, 0xd8, 0xa4, 0x2e, 0xcc, 0x33, 0x0f, 0x33,
	0x00, 0x00, 0x15, 0x3f, 0xf3, 0x33, 0x33, 0x33,
	0x00, 0x00, 0x04, 0x2e, 0x4c, 0x99, 0x33, 0x22,
	0x00, 0x00, 0x04, 0x2e, 0x4c, 0x88, 0x00, 0x00,
	0x00, 0x00, 0x79, 0xf3, 0xf3, 0xa2, 0x00, 0x00,
	0x00, 0x14, 0xa4, 0xa6, 0x0c, 0xa0, 0x00, 0x00,
	0x00, 0x14, 0xa0, 0x00, 0x14, 0xa0, 0x00, 0x00,
	0x00, 0x44, 0x88, 0x00, 0x14, 0xa0, 0x00, 0x00,
	0x00, 0x14, 0xa0, 0x00, 0x14, 0xf0, 0x00, 0x00,
	0x00, 0x78, 0xa0, 0x00, 0x00, 0x6c, 0xa0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa0, 0x00
};

// Tile sprite_character_11: 16x20 pixels, 8x20 bytes.
const u8 sprite_character_11[8 * 20] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xc3, 0xc3, 0x00, 0x00, 0x00,
	0x04, 0x00, 0x41, 0xc3, 0xc3, 0x82, 0x00, 0x00,
	0x49, 0x00, 0x41, 0xc3, 0xc3, 0x82, 0x00, 0x00,
	0x49, 0x00, 0x04, 0x0c, 0x49, 0x82, 0x00, 0x00,
	0x49, 0x00, 0x04, 0x0c, 0x49, 0x82, 0x00, 0x00,
	0x49, 0x00, 0x41, 0x49, 0xc3, 0x82, 0x00, 0x00,
	0x49, 0x00, 0x41, 0xc3, 0xc3, 0xc3, 0xc3, 0x82,
	0x49, 0x00, 0xc3, 0x49, 0xc3, 0xc3, 0xc3, 0xc3,
	0x49, 0x00, 0x0c, 0x0c, 0x0c, 0xc3, 0x0c, 0xc3,
	0xc3, 0xc3, 0xc3, 0x49, 0xc3, 0x86, 0xc3, 0x49,
	0xc3, 0xc3, 0xc3, 0x49, 0xc3, 0x86, 0xc3, 0x49,
	0x00, 0x00, 0xc3, 0x49, 0xc3, 0xc3, 0x0c, 0xc3,
	0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
	0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x82,
	0x00, 0x41, 0x82, 0x00, 0x41, 0x82, 0x00, 0x00,
	0x00, 0x41, 0x82, 0x00, 0x00, 0xc3, 0x00, 0x00,
	0x00, 0x41, 0x82, 0x00, 0x00, 0xc3, 0x00, 0x00,
	0x00, 0x41, 0x82, 0x00, 0x00, 0x41, 0x82, 0x00,
	0x00, 0xc3, 0x82, 0x00, 0x00, 0xc3, 0x82, 0x00
};

