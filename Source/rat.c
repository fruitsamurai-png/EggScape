//---------------------------------------------------------
// file:	rat.c
// author:	Chen Yen Hsun
// email:	c.yenhsun@digipen.edu
//			
//
// brief:	function for the rat enemy
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/gameover.h"
#include "../Header/character.h"
#include "../Header/platform_global.h"
#include "../Header/sound.h"
#include "../Header/rat.h"
#include "../Header/enemies_global.h"

CP_Image rat = NULL;
void mouse_init(size_t count1)
{
	mtimer = 0;//ensuring that the timer is at zero
	for (size_t n = 0; n < count1; n++)
	{
		mouses[n].x= (float)(CP_Random_RangeInt(blocksize,windowx));
		mouses[n].y = -blocksize;
		mouses[n].speed = 30;//how fast the mouse should be
		if (n==1)mouses[n].speed *= -1;
		rat = CP_Image_Load("./Assets/Enemy/rat.png");//the image of the rat
		warnings = CP_Image_Load("./Assets/Enemy/warn.png");//the warning image
	}
}
void mouse_update(size_t count2)
{
	for (size_t n = 0; n < count2; ++n)
	{
		++mtimer;
		mouses[n].x += mouses[n].speed;
		if (mouses[n].x > (windowx) || mouses[n].x < 0)
		{
			mouses[n].speed *= -1;//direction toggle when the rat hit the right or left screen
		}
		if (mtimer > 100&&mtimer<120)
		{
			CP_Image_Draw(warnings, mouses[n].x, mouses[n].y + (blocksize * 2), blocksize, blocksize, 255);//ensuring that the warning comes before the mouse comes out
		}
		if (mtimer >120)//if the timer is hit, the rat will come down
		{
			mouses[n].speed = 0;
			mouses[n].y += 20;
		}
		if (n==0 && mouses[n].y > windowy+50)//if the rat is out of the screen, it will reset at the top
		{
			mtimer = 0;
			mouses[n].y = -blocksize;
			mouses[n].x = (float)CP_Random_RangeInt(blocksize, windowx);
			mouses[n].speed = 20;
			mtimer = 0;
		}
		else if (n == 1 && mouses[0].y && mouses[1].y > windowy + 50)//if the second rat is out of the screen,it will reset at the top with a different speed
		{
			mtimer = 0;
			mouses[n].y = -blocksize;
			mouses[n].x = (float)CP_Random_RangeInt(blocksize, windowx);
			if (n==1)mouses[n].speed *= -1;
		}
		if (mouses[n].x + blocksize > egg.x &&
			mouses[n].x <egg.x + blocksize &&
			mouses[n].y + blocksize>egg.y &&
			mouses[n].y < egg.y + blocksize)//collision with character
		{
			mtimer = 0;
			sound.rathit = 1;
			egg.isdead = 1;
		}
		CP_Image_Draw(rat, mouses[n].x, mouses[n].y, blocksize, blocksize, 255);
	}
}
void mouse_exit(size_t count3)
{
	for (size_t n = 0; n < count3; n++)
	{
		mouses[n].x = 0;
		mouses[n].y = 0;
		mouses[n].speed = 10;
	}
	mtimer = 0;
	CP_Image_Free(&rat);
	CP_Image_Free(&warnings);
}