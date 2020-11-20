#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/Score.h"

CP_Image table=NULL;
void platform_init(int i)
{
		if (i == 0)
		{
			plats[i].dimy = (float)(CP_Random_RangeInt(50, 150));
			plats[i].dimx = (float)(CP_Random_RangeInt(dimw, (windowx - dimw)));
		}
		else
		{
			plats[i].dimy = (float)(CP_Random_RangeInt(50, 150)) + plats[i - 1].dimy;
			plats[i].dimx = (float)(CP_Random_RangeInt(dimw, (windowx - dimw)));
		}
		table = CP_Image_Load("./Assets/platform.png");
}
void platform_update(int i)
{
		CP_Settings_Fill(CP_Color_Create(66, 224, 245, 255));
		CP_Image_Draw(table, (plats[i].dimx+(dimw*0.5f)), (plats[i].dimy), dimw*1.25, (dimh*1.25f),255);
}
void platform_exit(void)
{
	for (int i = 0; i < 10; i++)
	{
		plats[i].dimy = 0;
		plats[i].dimx = 0;
	}
}