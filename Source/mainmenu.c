#include "../Header/button.h"
#include "../Header/howtoplay.h"
#include "../Header/main.h"
#include "../Header/sound.h"

CP_Image background1 = NULL;

extern CP_Sound intro;
extern CP_Sound select;

void mainmenu_init(void)
{
	sound_init();
	sound.intro = 1;
	CP_System_SetWindowTitle("EggScape");

	background1 = CP_Image_Load("./Assets/Backgrounds/mainmenu_BACKGROUND.png");
	init_button();
}

void mainmenu_update(void)
{
	sound_update();
	static int loc = 1;
	CP_Image_Draw(background1, windowx / 2, windowy / 2, windowx, windowy, 255);

	CP_Image_Draw(playButton.image, playButton.positionX, playButton.positionY, playButton.sizeX, playButton.sizeY, 255);
	CP_Image_Draw(howtoplayButton.image, howtoplayButton.positionX, howtoplayButton.positionY, howtoplayButton.sizeX, howtoplayButton.sizeY, 255);
	CP_Image_Draw(exitButton.image, exitButton.positionX, exitButton.positionY, exitButton.sizeX, exitButton.sizeY, 255);
	CP_Image_Draw(creditButton.image, creditButton.positionX, creditButton.positionY, creditButton.sizeX, creditButton.sizeY, 255);
	if (CP_Input_KeyTriggered(KEY_RIGHT)||
		CP_Input_KeyTriggered(KEY_D))
	{
		playButton.mc = 0;
		howtoplayButton.mc = 0;
		creditButton.mc = 0;
		exitButton.mc = 0;
		sound.select = 1;
		loc += 1;
		if (loc > 4)
			loc = 1;
	}
	if (CP_Input_KeyTriggered(KEY_LEFT) ||
		CP_Input_KeyTriggered(KEY_A))
	{
		playButton.mc = 0;
		howtoplayButton.mc = 0;
		creditButton.mc = 0;
		exitButton.mc = 0;
		sound.select = 1;
		loc -= 1;
		if (loc < 1)
			loc = 4;
	}

	switch (loc)
	{
	case 1:
		playButton.locx = playButton.positionX;
		creditButton.locx++;
		howtoplayButton.locx++;
		break;
	case 2:
		howtoplayButton.locx = howtoplayButton.positionX;
		playButton.locx++;
		exitButton.locx++;
		break;
	case 3:
		exitButton.locx = exitButton.positionX;
		howtoplayButton.locx++;
		creditButton.locx++;
		break;
	case 4:
		creditButton.locx = creditButton.positionX;
		exitButton.locx++;
		playButton.locx++;
		break;
	
	}
	credit(creditButton);
	play(playButton);
	howtoplay(howtoplayButton);
	exitgame(exitButton);
}
void mainmenu_exit(void)
{
	CP_Image_Free(&background1);
	CP_Sound_Free(intro);
	CP_Sound_Free(select);
	sound_exit();
	exit_button();
	playButton.mc = 0;
	howtoplayButton.mc = 0;
	creditButton.mc = 0;
	exitButton.mc = 0;
}