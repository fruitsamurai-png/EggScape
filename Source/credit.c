//---------------------------------------------------------
// file:	credit.c
// author:	Siti Nursafinah Binte Sumsuri
// email:	sitinursafinah.b@digipen.edu
//			
//
// brief:	functions for the credit scene
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "../Header/credit.h"
#include "../Header/button.h"
#include "cprocessing.h"
#include "../Header/main.h"
#include "../Header/sound.h"


CP_Image end=NULL;
CP_Image credit1 = NULL;
CP_Image credit2 = NULL;
int mousecheck = 0;//if any key or mouse input is detected,the credits will change pictures
void credit_init(void)
{
	sound_init();
	credit1 = CP_Image_Load("./Assets/Backgrounds/credit1.png");
	credit2 = CP_Image_Load("./Assets/Backgrounds/credit2.png");
	init_button4();
	mousecheck = 0;
}
void credit_update(void)
{
	static int loc = 0;;
	sound_update();
	if (CP_Input_KeyTriggered(KEY_RIGHT)||
		CP_Input_KeyTriggered(KEY_D))//press left or right switch button location
	{
		sound.select = 1;
		menuButton.mc = 0;//if there is no mouse input, the keyboard movement will be the dominant type of input
		loc += 1;
		if (loc > 0)
			loc = 0;
	}
	if (CP_Input_KeyTriggered(KEY_LEFT)||
		CP_Input_KeyTriggered(KEY_A))
	{
		sound.select = 1;
		menuButton.mc = 0;
		loc += 1;
		if (loc > 0)
			loc = 0;
	}
	switch (loc)
	{
	case 0:
		menuButton.locx = menuButton.positionX;
		break;
	default:
		break;
	}
	if (CP_Input_KeyTriggered(KEY_ANY) || CP_Input_MouseClicked())//if the player click anywhere on the screen,the next picture in the credits will start
	{
		if (!mousecheck)
		{
			mousecheck = 1;
		}
		else if (mousecheck)
		{
			mousecheck = 0;
		}
	}
	end = mousecheck == 0 ? credit1 : credit2;
	CP_Image_Draw(end, windowx/ 2, windowy / 2, windowx, windowy, 255);
	CP_Image_Draw(menuButton.image, menuButton.positionX, menuButton.positionY, menuButton.sizeX, menuButton.sizeY, 255);
	menu(menuButton);
}
void credit_exit()
{
	CP_Image_Free(&end);
	CP_Image_Free(&credit1);
	CP_Image_Free(&credit2);
	exit_button4();
	sound_exit();
	mousecheck = 0;
}