#include "cprocessing.h"
#include <stdlib.h>
#include "../Header/platform.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/Score.h"
#include "../Header/platform_break.h"
#include "../Header/sound.h"
CP_Image table_break = NULL;
void platform_break_init(int i)
{
	table_break = CP_Image_Load("./Assets/plat_break.png");
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
			sound.breakjump = 1;
		}
	}

	CP_Image_Draw(table_break, (plats_break[i].dimx), (plats_break[i].dimy), dimw, dimh, plats_break[i].alpha);
}
void platform_break_exit(void)
{
	CP_Image_Free(&table_break);
}