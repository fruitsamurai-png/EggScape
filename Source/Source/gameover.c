#include "cprocessing.h"
#include "../Header/gameover.h"
#include "../Header/button.h"
#include "../Header/mainmenu.h"
#include "../Header/main.h"
#include <stdio.h>

//letting the program know that it is an image that is being called
CP_Image background_over=NULL;
CP_Image title_over=NULL;

void gameover_init(void)
{
	WINDOW_HEIGHT = (float)CP_System_GetWindowHeight();	//since the WINDOW_HEIGHT and WINDOW_WIDTH is a float, there is a need to put the CP_System_GetWindow for both lengths in float
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();
	background_over = CP_Image_Load("./Assets/gameover_BACKGROUND.png");
	title_over = CP_Image_Load("./Assets/gameover_TITLE.png");


	init_button3();												// init_button3() is called in button.c
}

void gameover_update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));		// background colour to ensure that is a opaque
	CP_Image_Draw(background_over, WINDOW_WIDTH / 2, windowy / 2, windowx, windowy, 255);
	CP_Image_Draw(title_over, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 1 / 10, 700, 100, 255);

	CP_Image_Draw(restartButton.image, restartButton.positionX, restartButton.positionY, restartButton.sizeX, restartButton.sizeY, 255);
	CP_Image_Draw(menuButton.image, menuButton.positionX, menuButton.positionY, menuButton.sizeX, menuButton.sizeY, 255);

	restart(restartButton);	//calling the button that is in button.c and button.h
	menu(menuButton);
}

void gameover_exit(void)
{
	CP_Image_Free(&background_over);
	CP_Image_Free(&title_over);

}