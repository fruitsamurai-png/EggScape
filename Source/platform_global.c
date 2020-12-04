#include "cprocessing.h"
#include "../Header/main.h"
#include "../Header/platform_global.h"
#include "../Header/platform_moving.h"
#include "../Header/platform_break.h"
#include "../Header/platform.h"
#include "../Header/character.h"
#include "../Header/Score.h"

void platform_generator1(int f)
{
	if (score > 500)variation = 1;
	if (score > 1000)variation = 2;
	if (score > 2000)variation = 3;
	if (score > 3000)variation = 4;
	if (score > 4000)variation = 5;
	if (score > 5000)variation = 6;
	if (score > 6000)variation = 7;

	switch (variation)
	{
	case 0:  //level 1
		count++;
		if (plats[f].dimy > windowy)
		{
			plats[f].dimy = 0;
			plats[f].dimx = (float)(CP_Random_RangeInt(dimw / 2, (windowx - dimw)));
		}
		break;

	case 1: //level 3
		count++;
		if (plats[f].dimy > windowy)
		{
			if (plats_moving[f].dimy > windowy && count % 5 == 0 && plats[f].dimx != plats_moving[f].dimx)
			{
				plats_moving[f].dimy = 0;
				plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
			}
			else if (count % 5 != 0)
			{
				plats[f].dimy = 0;
				plats[f].dimx = (float)(CP_Random_RangeInt(dimw / 2, (windowx - dimw)));
			}
		}
		break;

	case 2:
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
				plats[f].dimx = (float)(CP_Random_RangeInt(dimw / 2, (windowx - dimw)));
			}
		}
		break;

	case 3:

		count++;
		if (plats[f].dimy > windowy)
		{
			if (plats_break[f].dimy > windowy && count % 5 == 0 && plats[f].dimy != plats_break[f].dimy)
			{
				plats_break[f].dimy = 0;
				plats_break[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
				plats_break[f].isbroken = 1;
				plats_break[f].alpha = 255;
			}
			else if (count % 5 != 0)
			{
				plats[f].dimy = 0;
				plats[f].dimx = (float)(CP_Random_RangeInt(dimw / 2, (windowx - dimw)));
			}
		}
		break;

	case 4://lv5

		count++;
		if (plats[f].dimy > windowy)
		{
			if (plats_break[f].dimy > windowy && count % 5 == 0 && plats[f].dimy != plats_break[f].dimy)
			{
				plats_break[f].dimy = 0;
				plats_break[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
				plats_break[f].isbroken = 1;
				plats_break[f].alpha = 255;
			}
			if (plats_moving[f].dimy > windowy && count % 10 == 0 && plats[f].dimy != plats_moving[f].dimy)
			{
				plats_moving[f].dimy = 0;
				plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
			}
			else if (count % 10 != 0)
			{
				plats[f].dimy = 0;
				plats[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
			}
		}
		break;

	case 5: //Lv4
		count++;
		if (plats_break[f].dimy > windowy && count % 10 != 0 && plats[f].dimy != plats_break[f].dimy)
		{
			plats_break[f].dimy = 0;
			plats_break[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
			plats_break[f].isbroken = 1;
			plats_break[f].alpha = 255;
		}
		if (plats_moving[f].dimy > windowy && count % 10 == 0 && plats[f].dimy != plats_moving[f].dimy)
		{
			plats_moving[f].dimy = 0;
			plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
		}
		break;
	case 6://level 2

		if (plats[f].dimy > windowy)
		{
			if (plats_break[f].dimy > windowy && count % 2 == 0 && plats[f].dimy != plats_break[f].dimy)
			{
				plats_break[f].dimy = 0;
				plats_break[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
				plats_break[f].isbroken = 1;
				plats_break[f].alpha = 255;
			}
			if (plats_moving[f].dimy > windowy && count % 5 == 0 && plats[f].dimy != plats_moving[f].dimy)
			{
				plats_moving[f].dimy = 0;
				plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
			}
			else if (count % 10 != 0)
			{
				plats[f].dimy = 0;
				plats[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
			}
		}
		break;

	case 7:
		if (plats[f].dimy > windowy)
		{
			if (plats_break[f].dimy > windowy && count % 1 == 0 && plats[f].dimy != plats_break[f].dimy)
			{
				plats_break[f].dimy = 0;
				plats_break[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
				plats_break[f].isbroken = 1;
				plats_break[f].alpha = 255;
			}
			if (plats_moving[f].dimy > windowy && count % 2 == 0 && plats[f].dimy != plats_moving[f].dimy)
			{
				plats_moving[f].dimy = 0;
				plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
			}
			else if (count % 10 != 0)
			{
				plats[f].dimy = 0;
				plats[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
			}
		}
		break;
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
	variation = 0;
	count = 0;
	isout = 0;
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
			plats[f].dimy = plats[f].dimy - egg.h * 1.1f;//offset for platform
			plats_moving[f].dimy = plats_moving[f].dimy - egg.h * 1.1f;
			plats_break[f].dimy = plats_break[f].dimy - egg.h * 1.1f;
			platform_generator1(f);
			isout = 1;

		}

	}
	else isout = 0;
}
void platform_global_exit(void)
{
	platform_exit();
	platform_moving_exit();
	platform_break_exit();
	variation = 0;
	count = 0;
}