#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/platform_moving.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/Score.h"
#include "../Header/sound.h"
CP_Image table_moving = NULL;
void platform_moving_init(void)
{
		
		table_moving = CP_Image_Load("./Assets/plat_move.png");
		plats_moving->speed = 40;
		plats_moving->time = 0;

}
void platform_moving_update(int f)
{

	if (egg.x < (plats_moving[f].dimx + dimw) &&
		(egg.x + blocksize) > plats_moving[f].dimx &&
		(egg.y + blocksize) > plats_moving[f].dimy &&
		egg.y < (plats_moving[f].dimy + dimh) &&
		egg.h > 0)
	{
		egg.isjump = 1;
		sound.jump = 1;
	}
	//equation for moving platform below
		plats_moving->time += 1;
		plats_moving[f].dimx += plats_moving->speed * CP_System_GetDt();
		if (plats_moving->time == 1000 && plats_moving->speed > 0)
		{
			plats_moving->speed *= -1;
			plats_moving->time = 0;
		}
		else if (plats_moving->time == 1000 && plats_moving->speed < 0)
		{
			plats_moving->speed *= -1;
			plats_moving->time = 0;
		}
		CP_Settings_Fill(CP_Color_Create(66, 224, 245, 255));
		CP_Image_Draw(table_moving, (plats_moving[f].dimx), (plats_moving[f].dimy), dimw , dimh, 255);
}
void platform_moving_exit(void)
{
	plats_moving->time = 0;
	plats_moving->speed = 0;
	CP_Image_Free(&table_moving);
}