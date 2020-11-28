//---------------------------------------------------------
// file:	main.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/collision.h"
#include "../Header/mainmenu.h"
#include "../Header/Score.h"
#include "../Header/platform_global.h"
#include "../Header/hand.h"
#include "../Header/howtoplay.h"
#include "../Header/gameover.h"
#include "../Header/sound.h"
#include "../Header/rat.h"
#include "stdbool.h"
CP_Image background=NULL;
CP_Image pauseimg = NULL;
float WINDOW_WIDTH;
bool pause = 0;
// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program

void game_init(void)
{
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();
	background = CP_Image_Load("./Assets/background_new.jpg");
	pauseimg = CP_Image_Load("./Assets/pause.png");
	CP_System_SetWindowTitle("EggScape");
	sound_init();
	platform_global_init();
	eggs_init();
	score_init();
	hand_init();
	mouse_init();
	// initialize variables and CProcessing settings for this gamestate
}
// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void game_update(void)
{
	if (CP_Input_KeyTriggered(KEY_P) || CP_Input_KeyTriggered(KEY_ESCAPE)) {
		if (pause)
		{
			pause = 0;
		}
		else
		{
			pause = 1;
			CP_Image_Draw(pauseimg, windowx * 0.50, windowy * 0.5, 100, 100, 255);
		}
	}
	if (!pause)
	{
		CP_Image_Draw(background, WINDOW_WIDTH / 2, windowy / 2, windowx, windowy, 255);
		platform_global_update();
		eggs_update();
		score_update();
		collide();
		hand_update();
		//sound_update();
		mouse_update();
	}
	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void game_exit(void)
{
	mainmenu_exit();
	howtoplay_exit();
	eggs_exit();
	score_exit();
	platform_global_exit();
	sound_exit();
	mouse_exit();
	CP_Image_Free(&background);
	CP_Image_Free(&pauseimg);
	// shut down the gamestate and cleanup any dynamic memory
}

// main() the starting point for the program
// CP_Engine_SetNextGameState() tells CProcessing which functions to use for init, update and exit
// CP_Engine_Run() is the core function that starts the simulation
int main(void)
{
	CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	CP_System_SetWindowSize(windowx, windowy);
	CP_Engine_Run();
	return 0;
}
