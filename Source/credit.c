#include "../Header/credit.h"
#include "../Header/button.h"
#include "cprocessing.h"
#include "../Header/main.h"

CP_Image end=NULL;

void credit_init(void)
{
	WINDOW_HEIGHT = (float)CP_System_GetWindowHeight();	//since the WINDOW_HEIGHT and WINDOW_WIDTH is a float, there is a need to put the CP_System_GetWindow for both lengths in float
	WINDOW_WIDTH = (float)CP_System_GetWindowWidth();
	end = CP_Image_Load("./Assets/Backgrounds/credits.jpg");

	init_button4();
}
void credit_update(void)
{
	CP_Image_Draw(end, WINDOW_WIDTH / 2, windowy / 2, windowx, windowy, 255);
	CP_Image_Draw(menuButton.image, menuButton.positionX, menuButton.positionY, menuButton.sizeX, menuButton.sizeY, 255);
	menu(menuButton);
}
void credit_exit()
{
	CP_Image_Free(&end);
}