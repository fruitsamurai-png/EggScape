//---------------------------------------------------------
// file:	platform_break.c
// author:	Chng Nai Wei Keith
// email:	n.chng@digipen.edu
//			
//
// brief:	functions for the breaking platform
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include <stdlib.h>
#include "../Header/platform_global.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/platform_break.h"
#include "../Header/sound.h"
CP_Image table_break = NULL;
void platform_break_init(int i)
{
	table_break = CP_Image_Load("./Assets/Platforms/plat_break.png");
	plats_break[i].isbroken = 1;//boolean that determines the platform is broken
	plats_break[i].alpha = 255;//opacity of the platform
}
void platform_break_update(int i)
{
		if (egg.x < (plats_break[i].dimx + dimw - 10) &&
			(egg.x + blocksize - 5) > plats_break[i].dimx &&
			(egg.y + blocksize + 10) > plats_break[i].dimy &&
			egg.y < (plats_break[i].dimy) &&
			egg.h > 0)
		{
			if (plats_break[i].isbroken)//if the characters hit the platform once
			{
				egg.isjump = 1;
				plats_break[i].isbroken = 0;//boolean is now false,thus cannot collide with the platform anymoree
				plats_break[i].alpha = 0;//the platform will turn invisble
				sound.breakjump = 1;//sound for the breaking platform
				egg.isgrounded = 1;
				egg.ro = 0;
			}
		}
	CP_Image_Draw(table_break, (plats_break[i].dimx), (plats_break[i].dimy), dimw, dimh, plats_break[i].alpha);
}
void platform_break_exit(void)
{
	CP_Image_Free(&table_break);
}