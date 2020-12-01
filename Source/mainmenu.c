#include "../Header/button.h"
#include "../Header/howtoplay.h"
#include "../Header/main.h"
#include "../Header/sound.h"

CP_Image digipen_logo=NULL;
CP_Image play_title=NULL;
CP_Image howtoplay_title=NULL;
CP_Image eggy=NULL;
CP_Image background1=NULL;
extern CP_Sound intro;

void mainmenu_init(void)
{
	sound_init();
	CP_Sound_PlayAdvanced(intro, .5f, 1, 1, CP_SOUND_GROUP_0);
	CP_System_SetWindowTitle("EggScape");
	WINDOW_HEIGHT = (float)CP_System_GetWindowHeight();
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();
	background1 = CP_Image_Load("./Assets/Backgrounds/mainmenu_BACKGROUND.png");
	init_button();
}

void mainmenu_update(void)
{
		CP_Image_Draw(background1, WINDOW_WIDTH / 2, windowy / 2, windowx, windowy, 255);
		CP_Image_Draw(play_title, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 2 / 5, 200, 200, 255);

		CP_Image_Draw(playButton.image, playButton.positionX, playButton.positionY, playButton.sizeX, playButton.sizeY, 255);
		CP_Image_Draw(howtoplayButton.image, howtoplayButton.positionX, howtoplayButton.positionY, howtoplayButton.sizeX, howtoplayButton.sizeY, 255);
		CP_Image_Draw(exitButton.image, exitButton.positionX, exitButton.positionY, exitButton.sizeX, exitButton.sizeY, 255);
		CP_Image_Draw(creditButton.image, creditButton.positionX, creditButton.positionY, creditButton.sizeX, creditButton.sizeY, 255);

		credit(creditButton);
		play(playButton);
		howtoplay(howtoplayButton);
		exitgame(exitButton);
}
void mainmenu_exit(void)
{
	CP_Image_Free (&play_title);
	CP_Image_Free (&howtoplay_title);
	CP_Image_Free (&eggy);
	CP_Image_Free (&background1);
	CP_Sound_Free(intro);
	exit_button();
}