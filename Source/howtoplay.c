#include "Cprocessing.h"
#include "../Header/mainmenu.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/howtoplay.h" 

CP_Image title=NULL;
CP_Image left_title = NULL;
CP_Image right_title = NULL;
CP_Image left_arrow = NULL;
CP_Image right_arrow = NULL;
CP_Image left_letter = NULL;
CP_Image right_letter = NULL;
CP_Image space_title = NULL;
CP_Image space = NULL;


void howtoplay_init(void)
{
	WINDOW_HEIGHT = (float)CP_System_GetWindowHeight();		//since the WINDOW_HEIGHT and WINDOW_WIDTH is a float, there is a need to put the CP_System_GetWindow for both lengths in float
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();

	title = CP_Image_Load("./Assets/howtoplay_TITLE.png");
	left_title = CP_Image_Load("./Assets/howtoplay_LTITLE.png");
	right_title = CP_Image_Load("./Assets/howtoplay_RTITLE.png");
	left_arrow = CP_Image_Load("./Assets/howtoplay_LARROW.png");
	right_arrow = CP_Image_Load("./Assets/howtoplay_RARROW.png");
	left_letter = CP_Image_Load("./Assets/howtoplay_A.png");
	right_letter = CP_Image_Load("./Assets/howtoplay_D.png");
	space_title = CP_Image_Load("./Assets/howtoplay_JTITLE.png");
	space = CP_Image_Load("./Assets/howtoplay_SPACE.png");

	init_button2();
}
void howtoplay_update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));	// background colour to ensure that is a opaque

	CP_Image_Draw(title, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 1 / 10, 700, 100, 255);
	CP_Image_Draw(left_title, WINDOW_WIDTH * 1 / 4, WINDOW_HEIGHT * 1 / 4, 100, 50, 255);
	CP_Image_Draw(right_title, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT * 1 / 4, 100, 50, 255);
	CP_Image_Draw(space_title, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 4 / 6, 150, 50, 255);
	CP_Image_Draw(left_arrow, WINDOW_WIDTH * 1 / 4, WINDOW_HEIGHT * 2 / 5, 100, 50, 255);
	CP_Image_Draw(right_arrow, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT * 2 / 5, 100, 50, 255);
	CP_Image_Draw(left_letter, WINDOW_WIDTH * 1 / 4, WINDOW_HEIGHT * 3 / 5, 50, 50, 255);
	CP_Image_Draw(right_letter, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT * 3 / 5, 50, 50, 255);
	CP_Image_Draw(space, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 7 / 9, 200, 50, 255);

	CP_Image_Draw(playButton.image, playButton.positionX, playButton.positionY, playButton.sizeX, playButton.sizeY, 255);
	CP_Image_Draw(menuButton.image, menuButton.positionX, menuButton.positionY, menuButton.sizeX, menuButton.sizeY, 255);

	play(playButton);	//calling the button that is in button.c and button.h
	menu(menuButton);
}
void howtoplay_exit(void)
{
	CP_Image_Free(&title);
	CP_Image_Free(&left_title);
	CP_Image_Free(&right_title);
	CP_Image_Free(&left_arrow);
	CP_Image_Free(&right_arrow);
	CP_Image_Free(&left_letter);
	CP_Image_Free(&right_letter);
}