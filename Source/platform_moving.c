//---------------------------------------------------------
// file:	platform_moving.c
// author:	Chng Nai Wei Keith
// email:	n.chng@digipen.edu
//			
//
// brief:	functions for the moving platform
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "../Header/platform_global.h"
#include "../Header/platform_moving.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/Score.h"
#include "../Header/sound.h"
CP_Image table_moving = NULL;
void platform_moving_init(void)
{
		table_moving = CP_Image_Load("./Assets/Platforms/plat_move.png");
		plats_moving->speed = 40;//the speed of the moving platforms
		plats_moving->time = 0;//timer for the moving platform to change direction
}
void platform_moving_update(int f)
{
		if (egg.x < (plats_moving[f].dimx + dimw - 10) &&
			(egg.x + blocksize - 5) > plats_moving[f].dimx &&
			(egg.y + blocksize + 10) > plats_moving[f].dimy &&
			egg.y < (plats_moving[f].dimy) &&
			egg.h > 0)//collision with the egg so it will jump
		{
			egg.isjump = 1;
			sound.jump = 1;
			egg.isgrounded = 1;
			egg.ro = 0;
			egg.springjump = 0;
		}
	//equation for moving platform below
		plats_moving->time += 1;
		plats_moving[f].dimx += plats_moving->speed * CP_System_GetDt();
		if (plats_moving->time == 1200 && plats_moving->speed > 0 || plats_moving[f].dimx>windowx)// if the timer hits, toggle direction
		{
			plats_moving->speed *= -1;
			plats_moving->time = 0;
		}
		else if (plats_moving->time == 1200 && plats_moving->speed < 0 || plats_moving[f].dimx<0)
		{
			plats_moving->speed *= -1;
			plats_moving->time = 0;
		}
		CP_Image_Draw(table_moving, (plats_moving[f].dimx), (plats_moving[f].dimy), dimw , dimh, 255);
}
void platform_moving_exit(void)
{
	plats_moving->time = 0;
	CP_Image_Free(&table_moving);
}