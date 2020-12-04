#include "Cprocessing.h"
#include "../Header/mainmenu.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/howtoplay.h" 
#include "../Header/sound.h"

CP_Image title=NULL;

void howtoplay_init(void)
{
	sound_init();
	WINDOW_HEIGHT = (float)CP_System_GetWindowHeight();		//since the WINDOW_HEIGHT and WINDOW_WIDTH is a float, there is a need to put the CP_System_GetWindow for both lengths in float
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();
	title = CP_Image_Load("./Assets/Backgrounds/tutorial.jpg");
	init_button2();
}
void howtoplay_update(void)
{
	sound_update();
	static int loc = 0;
	CP_Image_Draw(title, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT, 255);

	if (CP_Input_KeyTriggered(KEY_RIGHT) ||
		CP_Input_KeyTriggered(KEY_D))
	{
		playButton.mc = 0;
		menuButton.mc = 0;
		sound.select = 1;
		loc += 1;
		if (loc > 1)
			loc = 0;
	}
	if (CP_Input_KeyTriggered(KEY_LEFT)||
		CP_Input_KeyTriggered(KEY_A)
		)
	{
		playButton.mc = 0;
		menuButton.mc = 0;
		sound.select = 1;
		loc -= 1;
		if (loc < 0)
			loc = 1;
	}
	switch (loc)
	{
	case 0:
		playButton.locx = playButton.positionX;
		menuButton.locx++;
		break;
	case 1:
		menuButton.locx = menuButton.positionX;
		playButton.locx++;
		break;
	default:
		break;
	}
	CP_Image_Draw(playButton.image, playButton.positionX, playButton.positionY, playButton.sizeX, playButton.sizeY, 255);
	CP_Image_Draw(menuButton.image, menuButton.positionX, menuButton.positionY, menuButton.sizeX, menuButton.sizeY, 255);

	menu(menuButton);
	play(playButton);	//calling the button that is in button.c and button.h
}
void howtoplay_exit(void)
{
	CP_Image_Free(&title);
	playButton.mc = 0;
	menuButton.mc = 0;
}