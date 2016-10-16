#include "hud.h"
#include "sprites/numbers.h"
#include "sprites/heart.h"

u8* const _numbers[10] = {
	sprite_numbers_00, sprite_numbers_01, 
	sprite_numbers_02, sprite_numbers_03, 
	sprite_numbers_04, sprite_numbers_05,
	sprite_numbers_06, sprite_numbers_07,
	sprite_numbers_08, sprite_numbers_09
};

const u8 score[5] = {0,0,0,0,0};

void initScore()
{
	u8* pvm = cpct_getScreenPtr(0xC000, 60, 2);
	u8 i=3;
	while(--i)
	{
		cpct_drawSprite(sprite_numbers_00, pvm, SPRITE_NUMBERS_00_W, SPRITE_NUMBERS_00_H);
		pvm += SPRITE_NUMBERS_00_W;
		cpct_drawSprite(sprite_numbers_00, pvm, SPRITE_NUMBERS_00_W, SPRITE_NUMBERS_00_H);
		pvm += SPRITE_NUMBERS_00_W;
		cpct_drawSprite(sprite_numbers_00, pvm, SPRITE_NUMBERS_00_W, SPRITE_NUMBERS_00_H);
		pvm += SPRITE_NUMBERS_00_W;
		cpct_drawSprite(sprite_numbers_00, pvm, SPRITE_NUMBERS_00_W, SPRITE_NUMBERS_00_H);
		pvm += SPRITE_NUMBERS_00_W;
		cpct_drawSprite(sprite_numbers_00, pvm, SPRITE_NUMBERS_00_W, SPRITE_NUMBERS_00_H);
		pvm = cpct_getScreenPtr(0x8000, 60, 2);
	}
}

void 
initLife()
{
	u8* pvm = cpct_getScreenPtr(0xC000, 2, 2);
	u8 i=3;
	while(--i)
	{
		cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
		pvm += SPRITE_HEART_0_W + 1;
		cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
		pvm += SPRITE_HEART_0_W + 1;
		cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);		
		pvm = cpct_getScreenPtr(0x8000, 2, 2);
	}
}

void incrementScore()
{
	u8* s 		= score+5;
	u8* pvm 	= cpct_getScreenPtr(0xC000, 76, 2);
	u8* pvm_ 	= cpct_getScreenPtr(0x8000, 76, 2);	
	while(s != score)
	{
		--s;
		if((++(*s)) == 10)
		{
			*s = 0;
			cpct_drawSprite(_numbers[*s], pvm,  4, 12);
			cpct_drawSprite(_numbers[*s], pvm_, 4, 12);
			pvm 	-= 4;
			pvm_ 	-= 4;
		}
		else
		{
			cpct_drawSprite(_numbers[*s], pvm,  4, 12);
			cpct_drawSprite(_numbers[*s], pvm_, 4, 12);
			break;
		}
	}
}