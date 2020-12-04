#include "../Header/credit.h"
#include "../Header/button.h"
#include "cprocessing.h"
#include "../Header/main.h"
#include "../Header/sound.h"


CP_Image end=NULL;

void credit_init(void)
{
	sound_init();
	end = CP_Image_Load("./Assets/Backgrounds/credits.png");

	init_button4();
}
void credit_update(void)
{
	static int loc = 0;;
	sound_update();
	if (CP_Input_KeyTriggered(KEY_RIGHT)||
		CP_Input_KeyTriggered(KEY_D))
	{
		sound.select = 1;
		menuButton.mc = 0;
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
	CP_Image_Draw(end, windowx/ 2, windowy / 2, windowx, windowy, 255);
	CP_Image_Draw(menuButton.image, menuButton.positionX, menuButton.positionY, menuButton.sizeX, menuButton.sizeY, 255);
	menu(menuButton);
}
void credit_exit()
{
	CP_Image_Free(&end);
	exit_button4();
	sound_exit();
}