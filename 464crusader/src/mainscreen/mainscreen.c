#include "mainscreen.h"
#include "sprites/logo_crusader.h"
#include "sprites/play.h"
#include "sprites/help.h"
#include "sprites/credits.h"
#include "../hud/sprites/numbers.h"
#include "../common.h"
#include "../game.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN SCREEN
///////////////////////////////////////////////////////////////////////////////////////////////////////
#define LOGO_VMEM			cpctm_screenPtr(_screenMem, 0, 10)
#define ONE_VMEM 			cpctm_screenPtr(_screenMem, 25, 70)
#define PLAY_VMEM			cpctm_screenPtr(_screenMem, 31, 70)
#define TWO_VMEM 			cpctm_screenPtr(_screenMem, 25, 100)
#define HELP_VMEM			cpctm_screenPtr(_screenMem, 31, 100)
#define THREE_VMEM 			cpctm_screenPtr(_screenMem, 25, 130)
#define CREDITS_VMEM		cpctm_screenPtr(_screenMem, 31, 130)
///////////////////////////////////////////////////////////////////////////////////////////////////////
// HELP SCREEN
///////////////////////////////////////////////////////////////////////////////////////////////////////
#define TEXT_CONTROLS_VMEM0		cpctm_screenPtr(_screenMem, 23, 70)
#define TEXT_CONTROLS_VMEM1		cpctm_screenPtr(_screenMem, 12, 100)
#define TEXT_CONTROLS_VMEM2		cpctm_screenPtr(_screenMem, 12, 110)
#define TEXT_CONTROLS_VMEM3		cpctm_screenPtr(_screenMem, 12, 120)
#define TEXT_CONTROLS_VMEM4		cpctm_screenPtr(_screenMem, 12, 130)
///////////////////////////////////////////////////////////////////////////////////////////////////////
// CREDITS SCREEN
///////////////////////////////////////////////////////////////////////////////////////////////////////
#define TEXT_CREDITS_VMEM0		cpctm_screenPtr(_screenMem, 3, 40)
#define TEXT_CREDITS_VMEM1		cpctm_screenPtr(_screenMem, 6, 52)
#define TEXT_CREDITS_VMEM2		cpctm_screenPtr(_screenMem, 3, 70)
#define TEXT_CREDITS_VMEM3		cpctm_screenPtr(_screenMem, 6, 82)
#define TEXT_CREDITS_VMEM4		cpctm_screenPtr(_screenMem, 3, 100)
#define TEXT_CREDITS_VMEM5		cpctm_screenPtr(_screenMem, 6, 112)
#define TEXT_CREDITS_VMEM6		cpctm_screenPtr(_screenMem, 22, 160)
///////////////////////////////////////////////////////////////////////////////////////////////////////
#define TEXT_BOTTOM_VMEM 		cpctm_screenPtr(_screenMem, 14, 190)
///////////////////////////////////////////////////////////////////////////////////////////////////////
void mainScreen();
void helpScreen();
void creditsScreen();

void
mainScreen()
{
	cpct_memset(_screenMem, 0, 0x4000);
	// draw everything
	cpct_drawSprite(sprite_logo_crusader,(u8*)LOGO_VMEM, SPRITE_LOGO_CRUSADER_W, SPRITE_LOGO_CRUSADER_H);
	cpct_drawSprite(sprite_numbers_01, (u8*)ONE_VMEM, SPRITE_NUMBERS_01_W, SPRITE_NUMBERS_01_H);
	cpct_drawSprite(sprite_play,(u8*)PLAY_VMEM, SPRITE_PLAY_W, SPRITE_PLAY_H);
	cpct_drawSprite(sprite_numbers_02, (u8*)TWO_VMEM, SPRITE_NUMBERS_02_W, SPRITE_NUMBERS_02_H);
	cpct_drawSprite(sprite_help,(u8*)HELP_VMEM, SPRITE_HELP_W, SPRITE_HELP_H);
	cpct_drawSprite(sprite_numbers_03, (u8*)THREE_VMEM, SPRITE_NUMBERS_03_W, SPRITE_NUMBERS_03_H);
	cpct_drawSprite(sprite_credits,(u8*)CREDITS_VMEM, SPRITE_CREDITS_W, SPRITE_CREDITS_H);
	cpct_drawStringM0("Press num key", (u8*)TEXT_BOTTOM_VMEM, 3, 0);
	while(1)
	{
		cpct_scanKeyboard_f();
		if(cpct_isAnyKeyPressed_f())
		{
			if(cpct_isKeyPressed(Key_1))
				game();
			else if(cpct_isKeyPressed(Key_2))
				helpScreen();
			else if(cpct_isKeyPressed(Key_3))
				creditsScreen();
		}

	};
}

void
helpScreen()
{
	cpct_memset(_screenMem, 0, 0x4000);
	// Controls
	cpct_drawStringM0("CONTROLS", 		(u8*)TEXT_CONTROLS_VMEM0, 	9, 0);
	cpct_drawStringM0("A : Move left", 	(u8*)TEXT_CONTROLS_VMEM1, 	2, 0);
	cpct_drawStringM0("D : Move right",	(u8*)TEXT_CONTROLS_VMEM2, 	2, 0);
	cpct_drawStringM0("O : Jump", 		(u8*)TEXT_CONTROLS_VMEM3, 	2, 0);
	cpct_drawStringM0("P : Attack", 	(u8*)TEXT_CONTROLS_VMEM4, 	2, 0);
	// footer
	cpct_drawStringM0("Press any key", 	(u8*)TEXT_BOTTOM_VMEM, 14, 0);
	cpct_scanKeyboard_f();
	while(!cpct_isAnyKeyPressed_f())
		cpct_scanKeyboard_f();

	mainScreen();
}

void
creditsScreen()
{
	cpct_memset(_screenMem, 0, 0x4000);

	cpct_drawStringM0("Special thanks:", 	(u8*)TEXT_CREDITS_VMEM0, 9, 0);
	cpct_drawStringM0("Francisco Gallego", 	(u8*)TEXT_CREDITS_VMEM1, 2, 0);
	cpct_drawStringM0("Made by:", 			(u8*)TEXT_CREDITS_VMEM2, 9, 0);
	cpct_drawStringM0("Ismael PR",			(u8*)TEXT_CREDITS_VMEM3, 2, 0);
	cpct_drawStringM0("Made with:",			(u8*)TEXT_CREDITS_VMEM4, 9, 0);
	cpct_drawStringM0("CPCtelera",			(u8*)TEXT_CREDITS_VMEM5, 2, 0);
	cpct_drawStringM0("Oct. 2016",			(u8*)TEXT_CREDITS_VMEM6, 9, 0);
	// footer
	cpct_drawStringM0("Press any key", (u8*)TEXT_BOTTOM_VMEM, 14, 0);
	cpct_scanKeyboard_f();
	while(!cpct_isAnyKeyPressed_f())
		cpct_scanKeyboard_f();

	mainScreen();
}