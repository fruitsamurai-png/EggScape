//---------------------------------------------------------
// file:	platform.c
// author:	Chng Nai Wei Keith
// email:	n.chng@digipen.edu
//			
//
// brief:	functions for the basic platform
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/platform_global.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/Score.h"
#include "../Header/sound.h"

CP_Image table=NULL;

void platform_init(int i)
{
		if (i == 0)//intial coordinates of the platform
		{
			plats[i].dimy = (float)(CP_Random_RangeInt(50, 150));
			plats[i].dimx = (float)(CP_Random_RangeInt(0, (windowx - dimw)));
		}
		else//subsequant platforms with the offset of the previous platforms coordinates
		{
			plats[i].dimy = (float)(CP_Random_RangeInt(50, 150)) + plats[i - 1].dimy;
			plats[i].dimx = (float)(CP_Random_RangeInt(dimw / 2, (windowx - dimw)));
		}
		table = CP_Image_Load("./Assets/Platforms/plat_norm.png");
}
void platform_update(int i)
{
	
	if (egg.x < (plats[i].dimx + dimw-10) &&
		(egg.x + blocksize-5) > plats[i].dimx &&
		(egg.y + blocksize+10) > plats[i].dimy &&
		egg.y < (plats[i].dimy) &&
		egg.h > 0)//collision with the platform
	{
		egg.isjump = 1;
		sound.jump = 1;//sound effect to play when the character hit the platform
		egg.isgrounded = 1;
		egg.ro = 0;//rotation will reset when the character hit the platform
		egg.springjump = 0;
	}

	CP_Image_Draw(table, (plats[i].dimx), (plats[i].dimy), dimw, dimh,255);
}
void platform_exit(void)
{
	CP_Image_Free(&table);
}