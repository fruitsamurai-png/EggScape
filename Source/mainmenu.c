#include "../Header/button.h"
#include "../Header/howtoplay.h"
#include "../Header/main.h"

CP_Image digipen_logo=NULL;
CP_Image play_title=NULL;
CP_Image howtoplay_title=NULL;
CP_Image eggy=NULL;
CP_Image background1=NULL;

float dt;
float timer1;

void mainmenu_init(void)
{
	CP_System_SetWindowTitle("EggScape");
	timer1 = 1.0f;
	WINDOW_HEIGHT = (float)CP_System_GetWindowHeight();
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();
	speed = 0;
	digipen_logo = CP_Image_Load("./Assets/digiPen_RED.png");
	background1 = CP_Image_Load("./Assets/mainmenu_BACKGROUND.png");
	init_button();
}

void mainmenu_update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	if (timer1 > 0)
	{
		dt = CP_System_GetDt();
		CP_Image_Draw(digipen_logo, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 300, 250, 255);
		timer1 -= dt;

	}
	else {
		CP_Image_Draw(background1, WINDOW_WIDTH / 2, windowy / 2, windowx, windowy, 255);
		CP_Image_Draw(play_title, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 2 / 5, 200, 200, 255);

		CP_Image_Draw(playButton.image, playButton.positionX, playButton.positionY, playButton.sizeX, playButton.sizeY, 255);
		CP_Image_Draw(howtoplayButton.image, howtoplayButton.positionX, howtoplayButton.positionY, howtoplayButton.sizeX, howtoplayButton.sizeY, 255);
		CP_Image_Draw(exitButton.image, exitButton.positionX, exitButton.positionY, exitButton.sizeX, exitButton.sizeY, 255);

		play(playButton);
		howtoplay(howtoplayButton);
		exitgame(exitButton);
		start_Game();
	}
}
void mainmenu_exit(void)
{
	CP_Image_Free(&digipen_logo);
	CP_Image_Free (&play_title);
	CP_Image_Free (&howtoplay_title);
	CP_Image_Free (&eggy);
	CP_Image_Free (&background1);

}