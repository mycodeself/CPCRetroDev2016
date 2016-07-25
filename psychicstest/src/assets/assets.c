#include "assets.h"

/*
 * 0 Cyan (Mask)
 * 1 Bright White
 * 2 White
 * 3 Birght Red
 * 4 Red
 * 5 Green
 * 6 Yellow
 * 7 Blue
 * 8 Bright Blue
 * 9 Sky Blue
 * 10 Black
 * 11 Orange
 * 12 Green
 * 13 Sea Green
 * 14 Pink
 * 15 Pastel Yellow
 * 
 * {10 26 13 6 3 9 12 1 2 11 0 18 19 16 25}
 */
const u8 _palette[16] = {
	0x06, // MASK
	0x0B, 0x00, 0x0C, 0x1C, 0x16, 0x1E, 0x04,
	0x15, 0x17, 0x14, 0x0E, 0x12, 0x02, 0x07, 0x03
};


// Tile border: 10x5 pixels, 5x5 bytes.
const u8 _border[5 * 5] = {
	0xfc, 0xfc, 0xfc, 0xad, 0x5e,
	0x03, 0x03, 0x03, 0x0f, 0x03,
	0x03, 0x03, 0x56, 0x0f, 0x03,
	0x03, 0x07, 0x0f, 0x03, 0x03,
	0xfc, 0x0f, 0xfc, 0xfc, 0xfc
};

// Tile character_idle_templar_idle_0: 16x32 pixels, 8x32 bytes.
const u8 _character_sprite_idle[2 * 8 * 32] = {
	0xff, 0x00, 0xff, 0x00, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x03, 0x00, 0x43, 0x00, 0xc3, 0x00, 0xc3, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x03, 0x00, 0x43, 0x00, 0xc3, 0x00, 0xc3, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x03, 0x00, 0xc3, 0x00, 0xc3, 0x00, 0xc3, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x03, 0x00, 0x87, 0x00, 0x0f, 0x00, 0x0f, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x03, 0x00, 0x87, 0x00, 0x0f, 0x00, 0x0f, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x03, 0x00, 0xc3, 0x00, 0xc3, 0x00, 0x4b, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x03, 0x00, 0x43, 0x00, 0xc3, 0x00, 0xc3, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x03, 0x00, 0x43, 0x00, 0xc3, 0x00, 0xc3, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x60, 0x00, 0x81, 0x00, 0x4b, 0x00, 0xc3, 0x00, 0x83, 0x55, 0x0a, 0xff, 0x00,
	0xaa, 0x10, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x85, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x90, 0xff, 0x00,
	0x00, 0x60, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x30, 0x00, 0x60, 0x00, 0xc0, 0x55, 0x20,
	0x00, 0x60, 0x00, 0xc0, 0x00, 0x81, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0xc8, 0x00, 0x60, 0x55, 0x20,
	0x00, 0x0b, 0x00, 0x03, 0x00, 0x46, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x21, 0x00, 0x12,
	0x00, 0x4b, 0x00, 0xc3, 0x00, 0x64, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x61, 0x00, 0x92,
	0x00, 0x4b, 0x00, 0xc3, 0x00, 0x64, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x21, 0x00, 0x07,
	0x00, 0x0b, 0x00, 0x03, 0x00, 0x60, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0xc8, 0x00, 0x61, 0x00, 0x87,
	0x00, 0x4b, 0x00, 0xc3, 0x00, 0x42, 0x00, 0xc0, 0x00, 0x30, 0x00, 0x60, 0x00, 0x43, 0x00, 0x87,
	0x00, 0x4b, 0x00, 0xc3, 0x00, 0x42, 0x00, 0x90, 0x00, 0x30, 0x00, 0x60, 0x00, 0x43, 0x00, 0x87,
	0x00, 0x4b, 0x00, 0xc3, 0x00, 0x12, 0x00, 0x64, 0x00, 0xcc, 0x00, 0x98, 0x00, 0x43, 0x00, 0x87,
	0x00, 0x4b, 0x00, 0x83, 0x00, 0x30, 0x00, 0x64, 0x00, 0xcc, 0x00, 0x98, 0x00, 0x25, 0x55, 0x0a,
	0xaa, 0x05, 0x00, 0x1a, 0x00, 0xc0, 0x00, 0x30, 0x00, 0xcc, 0x00, 0xc8, 0x55, 0x20, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x10, 0x00, 0xc0, 0x00, 0x90, 0x00, 0x30, 0x00, 0xc0, 0x55, 0x20, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x03, 0x00, 0x43, 0x00, 0x43, 0x00, 0x03, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0xc3, 0x00, 0x43, 0x00, 0x43, 0x00, 0x43, 0x00, 0x87, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x01, 0x00, 0xc3, 0x00, 0x43, 0x00, 0x4b, 0x00, 0x43, 0x00, 0x87, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x0b, 0x00, 0x03, 0x00, 0x43, 0x00, 0x4b, 0x00, 0x03, 0x00, 0x07, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x0b, 0x00, 0x03, 0x00, 0x07, 0xaa, 0x05, 0x00, 0x03, 0x00, 0x07, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x0b, 0x00, 0x03, 0x00, 0x07, 0xaa, 0x05, 0x00, 0x03, 0x00, 0x03, 0x00, 0x0f,
	0xaa, 0x05, 0x00, 0xc3, 0x00, 0xc3, 0x00, 0x07, 0xaa, 0x05, 0x00, 0x03, 0x00, 0xc3, 0x00, 0x87,
	0xaa, 0x05, 0x00, 0xc3, 0x00, 0xc3, 0x00, 0x07, 0xaa, 0x05, 0x00, 0x03, 0x00, 0xc3, 0x00, 0x87,
	0xaa, 0x05, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0xaa, 0x05, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f
};

// Tile character_idle_templar_walk_0: 20x32 pixels, 10x32 bytes.
const u8 _character_walk_0[2 * 10 * 32] = {
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0xc0, 0x00, 0x90, 0x00, 0x24, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0x00, 0x0f, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x30, 0x00, 0x30, 0x00, 0x25, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x0f, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc4, 0x00, 0xcc, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xaa, 0x05, 0x00, 0x0c, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x4a, 0x00, 0xcc, 0x00, 0xc8, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00,
	0x00, 0x0e, 0x00, 0x0c, 0x00, 0x48, 0x00, 0x85, 0x00, 0x4a, 0x00, 0xcc, 0x00, 0xc0, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00,
	0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0f, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0x85, 0x00, 0x85, 0xff, 0x00, 0xff, 0x00,
	0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x4e, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x8d, 0x00, 0x85, 0xff, 0x00, 0xff, 0x00,
	0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x8d, 0x00, 0xc0, 0x00, 0x0f, 0xff, 0x00,
	0xaa, 0x05, 0x00, 0x0f, 0x00, 0x4a, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0x4a, 0x00, 0x84, 0x00, 0x0d, 0x55, 0x0a,
	0xaa, 0x05, 0x00, 0x3f, 0x00, 0x2f, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0x85, 0x00, 0x0c, 0x00, 0x1f, 0x00, 0x2f,
	0xaa, 0x05, 0x00, 0x3f, 0x00, 0x2f, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0x85, 0x00, 0x0d, 0x00, 0x3f, 0x00, 0x2f,
	0xaa, 0x05, 0x00, 0x3f, 0x00, 0x1a, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x0f, 0x00, 0x1f, 0x00, 0x2f,
	0xaa, 0x05, 0x00, 0x0f, 0x00, 0x1a, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x60, 0x55, 0x0a, 0x00, 0x0f, 0x55, 0x0a,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x4a, 0x00, 0x25, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0xc0, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x85, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x4a, 0x00, 0x0d, 0x00, 0x0e, 0x00, 0x85, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0d, 0x00, 0x0e, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0d, 0x00, 0x0f, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0e, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0e, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x84, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x84, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00
};

// Tile g_tile_templar_walk_1: 22x32 pixels, 11x32 bytes.
const u8 _character_walk_1[2 * 11 * 32] = {
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x0f, 0x00, 0xc0, 0x00, 0x90, 0x00, 0x24, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x4a, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x30, 0x00, 0x30, 0x00, 0x25, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x4a, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc4, 0x00, 0xcc, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xaa, 0x05, 0x00, 0x0c, 0x00, 0xc0, 0x00, 0x85, 0x00, 0x4a, 0x00, 0xcc, 0x00, 0xc8, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0x00, 0x0e, 0x00, 0x0c, 0x00, 0x48, 0x00, 0x4a, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0xc0, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0x85, 0x00, 0x85, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x8d, 0x00, 0x85, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0x00, 0x0e, 0x00, 0x0d, 0x00, 0x0f, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0x8d, 0x00, 0xc0, 0x00, 0x0f, 0xaa, 0x05, 0x55, 0x0a,
	0x00, 0x0f, 0x00, 0x0f, 0x00, 0x4a, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0x4a, 0x00, 0xc0, 0x00, 0x0c, 0x00, 0x1f, 0x00, 0x2f,
	0x00, 0x1f, 0x00, 0x3f, 0x00, 0x4a, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0x85, 0x00, 0x84, 0x00, 0x0c, 0x00, 0x1f, 0x00, 0x2f,
	0x00, 0x1f, 0x00, 0x3f, 0x00, 0x4a, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xcc, 0x00, 0x85, 0x00, 0x84, 0x00, 0x0c, 0x00, 0x1f, 0x00, 0x2f,
	0xaa, 0x05, 0x00, 0x0f, 0x00, 0x1a, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x0f, 0x00, 0x0f, 0xaa, 0x05, 0x55, 0x0a,
	0xff, 0x00, 0xff, 0x00, 0x00, 0x1a, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x60, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x4a, 0x00, 0x60, 0x00, 0x85, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0xc0, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x85, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0xff, 0x00, 0xaa, 0x05, 0x00, 0x84, 0x00, 0x0c, 0x00, 0x0f, 0x00, 0x0e, 0x00, 0x85, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x0f, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x55, 0x0a, 0x00, 0x0e, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0f, 0x55, 0x0a, 0x00, 0x0e, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
	0xaa, 0x05, 0x00, 0x0c, 0x00, 0x0c, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0d, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x55, 0x0a, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x55, 0x0a, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00,
	0xff, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00, 0xff, 0x00, 0x00, 0x4a, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0d, 0xff, 0x00,
	0xff, 0x00, 0xaa, 0x05, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x00, 0xff, 0x00, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x00
};