#include "cprocessing.h"
#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/gameover.h"
#include "../Header/character.h"
#include "../Header/platform_global.h"
#include "../Header/sound.h"
#include "../Header/plate.h"
#include "../Header/enemies_global.h"

CP_Image dish;
void plates_init(size_t count1)
{
	ptimer = 0;
	for (size_t n = 0; n < count1; n++)
	{
		plates[n].x = -blocksize;
		plates[n].y = (float)(CP_Random_RangeInt(blocksize, windowx));
		plates[n] .speed = 40;
		dish = CP_Image_Load("./Assets/Enemy/plate.png");
		warnings = CP_Image_Load("./Assets/Enemy/warn.png");
	}
}
void plates_update(size_t count2)
{
	for (size_t n = 0; n < count2; ++n)
	{
		++ptimer;
		plates[n].y += plates[n].speed;
		if (plates[n].y > (windowy) || plates[n].y < 0)
		{
			plates[n].speed *= -1;
		}
		if (ptimer > 100 && ptimer < 120)
		{
			CP_Image_Draw(warnings, plates[n].x + (blocksize * 2), plates[n].y , blocksize, blocksize, 255);
		}
		if (ptimer > 120)
		{
			plates[n].speed = 0;
			plates[n].x += 40*0.5f;
			if(egg.y < (windowy / 2))plates[n].y -=egg.h*0.5f*0.5f;
			plates[n].ro += 500 * CP_System_GetDt();
		}
		if (plates[n].x > windowx + 50)
		{
			ptimer = 0;
			plates[n].x = -blocksize;
			plates[n].y = (float)CP_Random_RangeInt(blocksize, windowx);
			plates[n].speed = 20;
			plates[n].ro = 0;
		}
		
		if (plates[n].x + blocksize > egg.x &&
			plates[n].x <egg.x + blocksize &&
			plates[n].y + blocksize>egg.y &&
			plates[n].y < egg.y + blocksize)
		{
			ptimer = 0;
			CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
		}
		CP_Image_DrawAdvanced(dish, plates[n].x, plates[n].y, blocksize, blocksize, 255,plates[n].ro);
	}
}
void plates_exit(size_t count3)
{
	for (size_t n = 0; n < count3; n++)
	{
		plates[n].x = 0;
		plates[n].y = 0;
		plates[n].speed = 0;
		plates[n].ro = 0;
	}
	ptimer = 0;
	CP_Image_Free(&dish);
	CP_Image_Free(&warnings);
}