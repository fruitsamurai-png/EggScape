#include "cprocessing.h"
#include "../Header/platform_global.h"
#include "../Header/collision.h"
#include "../Header/main.h"
#include "../Header/platform_moving.h"
#include "../Header/platform.h"
#include "../Header/character.h"
int count=0;
void platform_generator(int f)
{
		if (plats[f].dimy > windowy && count<=15 )//once a platform leave the screen,new platform will spawn
		{
			plats[f].dimy = 0;
			plats[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
			count++;	
		}
		if (count >= 15 && plats[f].dimy>windowy)
		{
			plats_moving[f].dimy = 0;
			plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
			count = 0;
		}
		if (plats_moving[f].dimy > windowy)
		{
			if (count >= 30)
			{
				plats_moving[f].dimy = 0;
				plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
				count = 0;
			}

		}
}
void platform_global_init(void)
{
	for (int i = 0; i < 10; ++i)
	{
		platform_init(i);
		platform_moving_init();
	}
}
void platform_global_update(void)
{
	for (int i = 0; i < 10; ++i)//drawing of the platforms
	{
		platform_update(i);
		platform_moving_update(i);
	}
	if (egg.y < (windowy / 2))
	{
		for (int f = 0; f < 10; f++)
		{
			egg.y = windowy / 2;
			plats[f].dimy = plats[f].dimy - egg.h;//offset for platform
			plats_moving[f].dimy = plats_moving[f].dimy - egg.h;
			platform_generator(f);
		}
	}
}
void platform_global_exit(void)
{
	platform_exit();
	platform_moving_exit();
}