#include "cprocessing.h"
#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/gameover.h"
#include "../Header/character.h"
#include "../Header/platform_global.h"
#include "../Header/sound.h"
#include "../Header/rat.h"
#include <time.h>
int mtimer = 0;
CP_Image rat = NULL;
CP_Image warnings = NULL;
void mouse_init(size_t count1)
{
	for (size_t n = 0; n < count1; n++)
	{
		mouses[n].x= (float)(CP_Random_RangeInt(blocksize,windowx));
		mouses[n].y = -blocksize;
		mouses[n].speed = 15;
		if (n / 2 == 0)mouses[n].speed *= -1;
		rat = CP_Image_Load("./Assets/Enemy/rat.png");
		warnings = CP_Image_Load("./Assets/Enemy/warn.png");
	}
}
void mouse_update(size_t count3)
{
	for (size_t n = 0; n < count3; n++)
	{
		++mtimer;
		mouses[n].x += mouses[n].speed;
		if (mouses[n].x > (windowx - 100) || mouses[n].x < 0)
		{
			mouses[n].speed *= -1;
		}
		if (mtimer <= 120 && mtimer >= 100)
		{
			CP_Image_Draw(warnings, mouses[n].x, mouses[n].y + (blocksize * 2), blocksize, blocksize, 255);
		}
		if (mtimer > 120)
		{
			mouses[n].speed = 0;
			mouses[n].y += 20;
		}
		if (mouses[n].y > windowy)
		{
			mouses[n].y = -blocksize;
			mouses[n].speed = 20;
			if (n / 2 == 0)mouses[n].speed *= -1;
			mtimer = 0;
		}
		if (mouses[n].x + blocksize > egg.x &&
			mouses[n].x <egg.x + blocksize &&
			mouses[n].y + blocksize>egg.y &&
			mouses[n].y < egg.y + blocksize)
		{
			mtimer = 0;
			sound.rathit = 1;
			CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
		}
		CP_Image_Draw(rat, mouses[n].x, mouses[n].y, blocksize, blocksize, 255);
	}
}
void mouse_exit(size_t count2)
{
	for (size_t n = 0; n < count2; n++)
	{
		mouses[n].x = 0;
		mouses[n].y = 0;
		mouses[n].speed = 10;
	}
	mtimer = 0;
	CP_Image_Free(&rat);
	CP_Image_Free(&warnings);
}