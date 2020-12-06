//---------------------------------------------------------
// file:	main.c
// author:	Chng Nai Wei Keith,Chen Yen Hsun,Siti Nursafinah Binte Sumsuri
// email:	n.chng@digipen.edu
//			c.yenhsun@digipen.edu
//			sitinursafinah.b@digipen.edu
//
// brief:	main game scene
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "../Header/digipen.h"
#include "../Header/button.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/collision.h"
#include "../Header/mainmenu.h"
#include "../Header/Score.h"
#include "../Header/platform_global.h"
#include "../Header/sound.h"
#include "../Header/enemies_global.h"
#include "stdbool.h"
CP_Image background = NULL;
CP_Image pauseimg = NULL;
bool pause = 0;
// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program

void game_init(void)
{
	background = CP_Image_Load("./Assets/Backgrounds/background.png");//load the background for the game
	pauseimg = CP_Image_Load("./Assets/Backgrounds/pause.png");//pause image
	platform_global_init();//initialises the platform generators
	enemies_init();//initialises the enemies
	eggs_init();//character
	score_init();//score
	sound_init();//sound
	// initialize variables and CProcessing settings for this gamestate
}
// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void game_update(void)
{
	if (CP_Input_KeyTriggered(KEY_P) || CP_Input_KeyTriggered(KEY_ESCAPE))//if these buttons are pressed, the game will pause 
	{
		if (pause)
		{
			pause = 0;
		}
		else
		{
			pause = 1;
			CP_Image_Draw(pauseimg, windowx * 0.50, windowy * 0.5, 100, 100, 255);//the image will appear at the center of the screen
		}
	}
	if (!pause)
	{
		CP_Image_Draw(background, windowx/2, windowy/2, windowx, windowy, 255);
		platform_global_update();
		eggs_update();
		enemies_update();
		collide();
		score_update();
		sound_update();
		
	}
	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void game_exit(void)
{
	platform_global_exit();
	enemies_exit();
	eggs_exit();
	score_exit();
	CP_Image_Free(&background);//free any memory
	CP_Image_Free(&pauseimg);
	// shut down the gamestate and cleanup any dynamic memory
}

// main() the starting point for the program
// CP_Engine_SetNextGameState() tells CProcessing which functions to use for init, update and exit
// CP_Engine_Run() is the core function that starts the simulation
int main(void)
{
	CP_System_SetWindowTitle("EggScape");// set the window title to be the game name
	CP_Engine_SetNextGameState(intro_init, intro_update, intro_exit);
	CP_System_SetWindowSize(windowx, windowy);//window size
	CP_Engine_Run();
	return 0;
}
