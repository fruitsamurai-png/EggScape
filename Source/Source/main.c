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
#include "../Header/platform.h"
#include "../Header/character.h"
#include "../Header/collision.h"
#include "../Header/mainmenu.h"
#include "../Header/Score.h"
#include "../Header/platform_global.h"
#include "../Header/hand.h"
#include "../Header/howtoplay.h"
#include "stdbool.h"
CP_Image background=NULL;
float WINDOW_WIDTH;
bool pause = 0;
// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program


void game_init(void)
{
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();
	background = CP_Image_Load("./Assets/Background.jpg");
	CP_System_SetWindowTitle("EggScape");
	platform_global_init();
	eggs_init();
	score_init();
	hand_init();
	// initialize variables and CProcessing settings for this gamestate
}
// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void game_update(void)
{
	if (CP_Input_KeyTriggered(KEY_P)) {
		if (pause)
			pause = 0;
		else
			pause = 1;
	}
	if (!pause)
	{
		CP_Image_Draw(background, WINDOW_WIDTH / 2, windowy / 2, windowx, windowy, 255);
		platform_global_update();
		eggs_update();
		score_update();
		collide();
		hand_update();
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
	platform_exit();
	score_exit();
	platform_global_exit();
	CP_Image_Free(&background);
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
