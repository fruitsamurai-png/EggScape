#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/platform_moving.h"
#include "../Header/main.h"
#include "../Header/collision.h"
#include "../Header/character.h"
#include "../Header/Score.h"
#include "../Header/platform_break.h"

void platform_break_init(int i)
{
	plats_break[i].isbroken = 1;
	plats_break[i].alpha = 255;
}
void platform_break_update(int i)
{
	if (egg.x < (plats_break[i].dimx + dimw) &&
		(egg.x + blocksize) > plats_break[i].dimx &&
		(egg.y + blocksize) > plats_break[i].dimy &&
		egg.y < (plats_break[i].dimy + dimh) &&
		egg.h > 0)
	{
		if (plats_break[i].isbroken)
		{
			egg.isjump = 1;
			plats_break[i].isbroken = 0;
			plats_break[i].alpha = 0;
		}
	}
	CP_Settings_Fill(CP_Color_Create(66, 224, 245, plats_break[i].alpha));
	CP_Graphics_DrawRect(plats_break[i].dimx, plats_break[i].dimy, dimw, dimh);
}
void platform_break_exit(void)
{
	for (int i = 0; i < 10; i++)
	{
		plats_break[i].dimy = 0;
		plats_break[i].dimx = 0;
		plats_break[i].alpha = 0;
	}
}