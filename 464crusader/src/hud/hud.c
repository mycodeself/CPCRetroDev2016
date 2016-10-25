#include "hud.h"
#include "sprites/numbers.h"
#include "sprites/heart.h"
#include "sprites/gameover.h"
#include "../character/character.h"

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
	u8* pvm = cpct_getScreenPtr((u8*)0xC000, 60, 2);
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
		pvm = cpct_getScreenPtr((u8*)0x8000, 60, 2);
	}
}

void 
initLife()
{
	u8* pvm = cpct_getScreenPtr((u8*)0xC000, 2, 2);
	u8 i=3;
	while(--i)
	{
		cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
		pvm += SPRITE_HEART_0_W + 1;
		cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
		pvm += SPRITE_HEART_0_W + 1;
		cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);		
		pvm = cpct_getScreenPtr((u8*)0x8000, 2, 2);
	}
}

void
initHUD()
{
	initScore();
	initLife();
}

void incrementScore()
{
	u8* s 		= score+5;
	u8* pvm 	= cpct_getScreenPtr((u8*)0xC000, 76, 2);
	u8* pvm_ 	= cpct_getScreenPtr((u8*)0x8000, 76, 2);	
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

void 
decrementLifeHUD()
{
	u8* pvm;
	switch(_character.hp)
	{
		case 3:
			pvm = cpct_getScreenPtr((u8*)0xC000, 18, 2);
			cpct_drawSprite(sprite_heart_1, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
			pvm = cpct_getScreenPtr((u8*)0x8000, 18, 2);
			cpct_drawSprite(sprite_heart_1, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
			break;
		case 2:
			pvm = cpct_getScreenPtr((u8*)0xC000, 10, 2);
			cpct_drawSprite(sprite_heart_1, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
			pvm = cpct_getScreenPtr((u8*)0x8000, 10, 2);
			cpct_drawSprite(sprite_heart_1, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
			break;
		case 1:
			pvm = cpct_getScreenPtr((u8*)0xC000, 2, 2);
			cpct_drawSprite(sprite_heart_1, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
			pvm = cpct_getScreenPtr((u8*)0x8000, 2, 2);
			cpct_drawSprite(sprite_heart_1, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
	}
}

void 
incrementLifeHUD()
{
	u8* pvm;
	switch(_character.hp)
	{
		case 2:
			pvm = cpct_getScreenPtr((u8*)0xC000, 18, 2);
			cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
			pvm = cpct_getScreenPtr((u8*)0x8000, 18, 2);
			cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
			break;
		case 1:
			pvm = cpct_getScreenPtr((u8*)0xC000, 10, 2);
			cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
			pvm = cpct_getScreenPtr((u8*)0x8000, 10, 2);
			cpct_drawSprite(sprite_heart_0, pvm, SPRITE_HEART_0_W, SPRITE_HEART_0_H);
	}
}

#define GAMEOVER_PVM0 cpctm_screenPtr(0xC000, 20, 80)	
#define GAMEOVER_PVM1 cpctm_screenPtr(0x8000, 20, 80)
void drawGameover()
{
	cpct_drawSprite(sprite_gameover, GAMEOVER_PVM0, SPRITE_GAMEOVER_W, SPRITE_GAMEOVER_H);
	cpct_drawSprite(sprite_gameover, GAMEOVER_PVM1, SPRITE_GAMEOVER_W, SPRITE_GAMEOVER_H);
}