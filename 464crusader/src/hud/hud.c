/*	
 *
 *  This file is part of 464 Crusader, game for Amstrad CPC 464.
 *
 *  464 Crusader is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  464 Crusader is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 464 Crusader.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "hud.h"
#include "sprites/numbers.h"
#include "sprites/heart.h"
#include "sprites/you.h"
#include "sprites/died.h"
#include "../game.h"
#include "../character/character.h"
#include "../mainscreen/mainscreen.h"

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
	u8* s = score;
	*s = 0;	++s; *s = 0; ++s; *s = 0; ++s; *s = 0; ++s; *s = 0;
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

#define GAMEOVER_VMEM0 		cpctm_screenPtr(_screenMem, 27, 80)
#define GAMEOVER_VMEM1 		cpctm_screenPtr(_screenMem, 26, 110)
#define GAMEOVER_BG_VMEM	cpctm_screenPtr(_screenMem, 10, 80)
#define TEXT_BOTTOM_VMEM0	cpctm_screenPtr(_screenMem, 17, 145)
#define TEXT_BOTTOM_VMEM1	cpctm_screenPtr(_screenMem, 15, 160)
void drawGameover()
{
	cpct_drawSolidBox((u8*)GAMEOVER_BG_VMEM, 0, 60, 100);
	cpct_drawSprite(sprite_you, 	GAMEOVER_VMEM0, SPRITE_YOU_W, 	SPRITE_YOU_H);
	cpct_drawSprite(sprite_died,	GAMEOVER_VMEM1, SPRITE_DIED_W, 	SPRITE_DIED_H);
	cpct_drawStringM0("1:Play again", (u8*)TEXT_BOTTOM_VMEM0, 2, 0);
	cpct_drawStringM0("ESC:Main menu", (u8*)TEXT_BOTTOM_VMEM1, 2, 0);
	cpct_scanKeyboard_f();
	while(1)
	{
		cpct_scanKeyboard_f();
		if(cpct_isKeyPressed(Key_1))
			game();
		else if(cpct_isKeyPressed(Key_Esc))
			mainScreen();
	}
    
}