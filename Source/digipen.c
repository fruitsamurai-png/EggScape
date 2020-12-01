#include "cprocessing.h"
#include "../Header/main.h"
#include "../Header/mainmenu.h"

CP_Image digipen = NULL;
int opa;
float width, height;
void intro_init(void)
{
	CP_System_SetWindowTitle("EggScape");
	opa = 0;
	digipen = CP_Image_Load("./Assets/DigiPen_RED.png");
	width = (float)CP_Image_GetWidth(digipen);
	height = (float)CP_Image_GetHeight(digipen);
}
void intro_update(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(digipen,windowx/2,windowy/2,width/2,height/2,opa);
	opa+=2;
	if ((int)opa % 255 == 0 || CP_Input_KeyTriggered(KEY_ANY)  || CP_Input_MouseClicked())
	{
		CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	} 
}
void intro_exit(void)
{
	CP_Image_Free(&digipen);
	opa = 0;
}