#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/Score.h"

CP_Image table=NULL;
CP_Sound jump = NULL;
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
		jump = CP_Sound_Load("./Assets/jump.wav");
}
void platform_update(int i)
{
	static float volume = .5f;
	if (CP_Input_KeyTriggered(KEY_Q))
	{
		volume -= .01f;
		if (volume <= 0)
			volume =0;
	}
	if (CP_Input_KeyTriggered(KEY_E))
	{
		volume += .01f;
		if (volume >= 1)
			volume = 1;
	}
	if (egg.x < (plats[i].dimx + dimw) &&
		(egg.x + blocksize) > plats[i].dimx &&
		(egg.y + blocksize) > plats[i].dimy &&
		egg.y < (plats[i].dimy + dimh) &&
		egg.h > 0)
	{
		egg.isjump = 1;
		CP_Sound_PlayAdvanced(jump, volume, 1, 0, CP_SOUND_GROUP_0);
		//CP_Sound_Play(jump);
	}

	CP_Settings_Fill(CP_Color_Create(66, 224, 245, 255));
	CP_Image_Draw(table, (plats[i].dimx), (plats[i].dimy), dimw, dimh,255);
}
void platform_exit(void)
{
	for (int i = 0; i < 10; i++)
	{
		plats[i].dimy = 0;
		plats[i].dimx = 0;
	}
	CP_Sound_Free(jump);
}