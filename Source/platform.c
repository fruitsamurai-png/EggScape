#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/Score.h"
#include "../Header/sound.h"
CP_Image table=NULL;
void platform_init(int i)
{
		if (i == 0)
		{
			plats[i].dimy = (float)(CP_Random_RangeInt(50, 150));
			plats[i].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
		}
		else
		{
			plats[i].dimy = (float)(CP_Random_RangeInt(50, 150)) + plats[i - 1].dimy;
			plats[i].dimx = (float)(CP_Random_RangeInt(dimw / 2, (windowx - dimw)));
		}
		table = CP_Image_Load("./Assets/plat_norm.png");
}
void platform_update(int i)
{
	
	if (egg.x < (plats[i].dimx + dimw) &&
		(egg.x + blocksize) > plats[i].dimx &&
		(egg.y + blocksize) > plats[i].dimy &&
		egg.y < (plats[i].dimy + dimh) &&
		egg.h > 0)
	{
		egg.isjump = 1;
		sound.jump = 1;
	}

	CP_Settings_Fill(CP_Color_Create(66, 224, 245, 255));
	CP_Image_Draw(table, (plats[i].dimx), (plats[i].dimy), dimw, dimh,255);
}
void platform_exit(void)
{
	CP_Image_Free(&table);
}