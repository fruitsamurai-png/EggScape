#include "cprocessing.h"
#include "../Header/platform_global.h"
#include "../Header/main.h"
#include "../Header/platform_moving.h"
#include "../Header/platform.h"
#include "../Header/platform_break.h"
#include "../Header/character.h"
#include "../Header/Score.h"
int count=0;
int rand = 0;
void platform_generator1(int f)
{
	if(score>500)rand = 1;
	if (score > 1000)rand = 2;
	if (score > 2000)rand = 3;
	switch (rand)
	{
		case 0:
		{
			if (plats[f].dimy > windowy)
			{
				plats[f].dimy = 0;
				plats[f].dimx = (float)(CP_Random_RangeInt(dimw/2, (windowx - dimw)));
			}
			break;
		}
		case 1:
		{
			count++;
			if (plats[f].dimy > windowy)
			{
				if (plats_moving[f].dimy > windowy && count % 10 == 0 && plats[f].dimx != plats_moving[f].dimx)
				{
					plats_moving[f].dimy = 0;
					plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
				}
				else if (count % 10 != 0)
				{
					plats[f].dimy = 0;
					plats[f].dimx = (float)(CP_Random_RangeInt(dimw/2, (windowx - dimw)));
				}
			}
			break;
		}
		case 2:
		{
			count++;
			if (plats[f].dimy > windowy)
			{
				if (plats_break[f].dimy > windowy && count % 5 == 0 && plats[f].dimx != plats_break[f].dimx)
				{
					plats_break[f].dimy = 0;
					plats_break[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
					plats_break[f].isbroken = 1;
					plats_break[f].alpha = 255;
				}
				else if (count % 5 != 0)
				{
					plats[f].dimy = 0;
					plats[f].dimx = (float)(CP_Random_RangeInt(dimw/2, (windowx - dimw)));
				}
			}
			break;
		}
		case 3:
		{
			count++;
			if (plats[f].dimy > windowy)
			{
				if (plats_break[f].dimy > windowy && count % 5 == 0 && plats[f].dimx != plats_break[f].dimx)
				{
					plats_break[f].dimy = 0;
					plats_break[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
					plats_break[f].isbroken = 1;
					plats_break[f].alpha = 255;
				}
				if (plats_moving[f].dimy > windowy && count % 10 == 0 && plats[f].dimx != plats_moving[f].dimx)
				{
					plats_moving[f].dimy = 0;
					plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
				}
				else if (count % 100 != 0)
				{
					plats[f].dimy = 0;
					plats[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
				}
			}
		}
	}
}
void platform_global_init(void)
{
	for (int i = 0; i < 10; ++i)
	{
		platform_init(i);
		platform_moving_init();
		platform_break_init(i);
	}
}
void platform_global_update(void)
{
	for (int i = 0; i < 10; ++i)//drawing of the platforms
	{
		platform_update(i);
		platform_moving_update(i);
		platform_break_update(i);
	}
	if (egg.y < (windowy / 2))
	{
		for (int f = 0; f < 10; f++)
		{
			egg.y = windowy / 2;
			plats[f].dimy = plats[f].dimy - egg.h;//offset for platform
			plats_moving[f].dimy = plats_moving[f].dimy - egg.h;
			plats_break[f].dimy = plats_break[f].dimy - egg.h;
			platform_generator1(f);
		}
	
	}
}
void platform_global_exit(void)
{
	platform_exit();
	platform_moving_exit();
	platform_break_exit();
	rand = 0;
}