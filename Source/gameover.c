#include "cprocessing.h"
#include "../Header/character.h"
#include "../Header/platform_global.h"
#include "../Header/enemies_global.h"
#include "../Header/gameover.h"
#include "../Header/button.h"
#include "../Header/mainmenu.h"
#include "../Header/main.h"
#include "../Header/Score.h"
#include "../Header/sound.h"
#include <stdio.h>
#include <stdlib.h>
extern CP_Sound fisthit;
extern CP_Sound rathit;

//letting the program know that it is an image that is being called
CP_Image background_over=NULL;
CP_Image title_over=NULL;
static void display_score(void)
{
	CP_Settings_TextSize(30);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText("Score:", windowx*0.40, windowy*0.7);
	CP_Font_DrawText(charbuffer, windowx * 0.50, windowy * 0.7);
	_itoa_s(deathscore, charbuffer, 100, 10);
}
void gameover_init(void)
{
	sound_init();
	background_over = CP_Image_Load("./Assets/Backgrounds/gameover_BACKGROUND.png");
	title_over = CP_Image_Load("./Assets/Backgrounds/gameover_TITLE.png");
	init_button3();												// init_button3() is called in button.c
}

void gameover_update(void)
{
	static int loc = 0;
	sound_update();
	CP_Image_Draw(background_over, windowx/ 2, windowy / 2, windowx, windowy, 255);
	CP_Image_Draw(title_over, windowx / 2, windowy * 1 / 10, 700, 100, 255);
	if (CP_Input_KeyTriggered(KEY_RIGHT)||
		CP_Input_KeyTriggered(KEY_D)
		)
	{
		sound.select = 1;
		restartButton.mc = 0;
		menuButton.mc = 0;
		loc += 1;
		if (loc > 1)
			loc = 0;
	}
	if (CP_Input_KeyTriggered(KEY_LEFT)||
		CP_Input_KeyTriggered(KEY_A))
	{
		sound.select = 1;
		restartButton.mc = 0;
		menuButton.mc = 0;
		loc -= 1;
		if (loc < 0)
			loc = 1;
	}
	switch (loc)
	{
	case 0:
		restartButton.locx = restartButton.positionX;
		menuButton.locx++;
		break;
	case 1:
		menuButton.locx = menuButton.positionX;
		restartButton.locx++;
		break;
	default:
		break;
	}

	CP_Image_Draw(restartButton.image, restartButton.positionX, restartButton.positionY, restartButton.sizeX, restartButton.sizeY, 255);
	CP_Image_Draw(menuButton.image, menuButton.positionX, menuButton.positionY, menuButton.sizeX, menuButton.sizeY, 255);

	display_score();

	restart(restartButton);	//calling the button that is in button.c and button.h
	menu(menuButton);
}

void gameover_exit(void)
{
	CP_Image_Free(&background_over);
	CP_Image_Free(&title_over);
	memset(charbuffer, 0, 100 * sizeof(char));
	deathscore = 0;
	restartButton.mc = 0;
	menuButton.mc = 0;
	sound_exit();
	exit_button3();
}