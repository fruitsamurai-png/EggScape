//---------------------------------------------------------
// file:	platform_global.c
// author:	Chng Nai Wei Keith,Chen Yen Hsun
// email:	c.yenhsun@digipen.edu
//			n.chng@digipen.edu
//
// brief:	functions for the platform generator
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "../Header/main.h"
#include "../Header/platform_global.h"
#include "../Header/platform_moving.h"
#include "../Header/platform_break.h"
#include "../Header/platform_spring.h"
#include "../Header/platform.h"
#include "../Header/character.h"
#include "../Header/Score.h"
void spring_generator(int f)//function to generate the spring
{
	springtimer++;
	if (springtimer % 3000 ==0)//if the timer hits the requirement, the spring will generate
	{
		springs[f].dimy = -egg.h / 2;
		springs[f].dimx = (float)(CP_Random_RangeInt(dimw / 2, (windowx - dimw)));
		springtimer = 0;
	}
	
}
void platform_generator1(int f)
{
	switch (variation)//switch function to generate the type of platforms
	{
	case 0:  //level 1
		count++;
		if (plats[f].dimy > windowy)
		{
			plats[f].dimy = -egg.h;
			plats[f].dimx = (float)(CP_Random_RangeInt(dimw / 2, (windowx - dimw)));
		}
		break;

	case 1: //level 2
		count++;//count that helps the spawning of different types of platform without colliding with each other
		if (plats[f].dimy > windowy)
		{
			if (plats_moving[f].dimy > windowy && count % 5 == 0 && plats[f].dimx != plats_moving[f].dimx)
			{
				plats_moving[f].dimy = -egg.h/2;
				plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
			}
			else if (count % 5 != 0)
			{
				plats[f].dimy = -egg.h;
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
				plats[f].dimy = -egg.h;
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
				plats[f].dimy = -egg.h;
				plats[f].dimx = (float)(CP_Random_RangeInt(dimw / 2, (windowx - dimw)));
			}
		}
		break;

	case 4://level 4

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
				plats[f].dimy = -egg.h;
				plats[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
			}
		}
		break;

	case 5: //Lv5
		count++;
		if (plats[f].dimy > windowy)
		{
			if (plats_break[f].dimy > windowy && count % 10 != 0)
			{
				plats_break[f].dimy = 0;
				plats_break[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
				plats_break[f].isbroken = 1;
				plats_break[f].alpha = 255;
			}
			if (plats_moving[f].dimy > windowy && count % 10 == 0)
			{
				plats_moving[f].dimy = -egg.h;
				plats_moving[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw + plats_moving->speed)));
			}
			else if (count % 100 == 0)
			{
				plats[f].dimy = -egg.h;
				plats[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
			}
		}
		break;
	case 6://level 6
		count++;
		if (plats_break[f].dimy > windowy)
		{
			if (plats_break[f].dimy > windowy && count % 100 == 0 && plats[f].dimy != plats_break[f].dimy)
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
				plats[f].dimy = -egg.h;
				plats[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
			}
		}
		break;
	default:
		if (plats[f].dimy > windowy)
		{
			if (plats_break[f].dimy > windowy && count % 100 == 0 && plats[f].dimy != plats_break[f].dimy)
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
			if (count % 10 != 0)
			{
				plats[f].dimy = -egg.h;
				plats[f].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
			}
		}
		break;
	}
}
void platform_global_init(void)//initialise the platform functions
{
	for (int i = 0; i < 10; ++i)
	{
		platform_init(i);
		platform_moving_init();
		platform_break_init(i);
		springs_init(i);
	}
	variation = 0;
	count = 0;
	isout = 0;
	springtimer = 0;
}
void platform_global_update(void)
{
	if (score > 500)variation = 1;//if the score hits the requirement, the variation of the platform and enemie will change
	if (score > 1000)variation = 2;
	if (score > 2000)variation = 3;
	if (score > 3000)variation = 4;
	if (score > 4000)variation = 5;
	if (score > 5000)variation = 6;

		for (int i = 0; i < 10; ++i)//drawing of the platforms
		{
			platform_update(i);
			platform_moving_update(i);
			platform_break_update(i);
			springs_update(i);
		}
	if (egg.y < (windowy / 2))//if the egg is at the center of the screen
	{
		for (int f = 0; f < 10; f++)
		{
			egg.y = windowy / 2;//the position will be cap there
			plats[f].dimy = plats[f].dimy - egg.h * 1.1f;//offset for platforms
			plats_moving[f].dimy = plats_moving[f].dimy - egg.h * 1.1f;
			plats_break[f].dimy = plats_break[f].dimy - egg.h * 1.1f;
			springs[f].dimy = springs[f].dimy - egg.h * 1.1f;
			platform_generator1(f);
			spring_generator(f);
			isout = 1;//boolean that determine if the levels are moving down
		}

	}
	else isout = 0;
}
void platform_global_exit(void)
{
	platform_exit();
	platform_moving_exit();
	platform_break_exit();
	springs_exit();
	variation = 0;
	count = 0;
}