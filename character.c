#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/collision.h"

CP_Image eggy1=NULL;
int check=0;
float maxspeed = 0;
void eggjump(void)
{
	//mode1(normal Jump)
	float G = 10 * .2f;//gravity for the egg

	if (egg.isdrop) {
		if (egg.h == 0)
			egg.h = 8;
		egg.h += 1.f * G;//velocity of the egg
		egg.y += .5f * egg.h;
		egg.drop = egg.y + egg.h;
	}

	if (egg.isjump)
	{
		if (!egg.count)
		{
			egg.h = -60;
			egg.count = 1;
		}
		else
			egg.h = -40;
		//if (egg.y > windowy)
		egg.isjump = 0;
		//egg.isdrop = 1;
	}
	//Mode2(power up)
	/*int G = 10;
	egg.h += 0.2f;
	egg.y += 0.5f*egg.h*G;
	if (egg.y > windowy)
		egg.h = -10;
		*/
	CP_Vector_Set(egg.x, egg.y);
}

void eggs_init(void)
{
	egg.x = (float)(windowy * 0.50);
	egg.y = (windowy * 0.50);
	egg.maxaccel = 30;
	egg.isdrop = 1;
	egg.isjump = 0;
	egg.h = 0;
	egg.x = plats[7].dimx+(0.5f*dimw);
	egg.y = windowy / 2;
	egg.start = 0;
	egg.count = 0;
	maxspeed = 30;
}
void eggs_update(void)
{
	eggy1= CP_Image_Load("./Assets/eggy_RRUN.png");
	if (egg.start)
	{
		if ((CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT)))
		{
			if (check == 0)
				egg.movement = 0;
			egg.movement += (egg.maxaccel * CP_System_GetDt());
			check = 1;
		}
		if ((CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT)))
		{
			if (check == 1)
				egg.movement = 0;
			egg.movement -= (egg.maxaccel * CP_System_GetDt());
			check = 0;
		}
		if (check == 1)
		{
			eggy1 = CP_Image_Load("./Assets/eggy_RRUN.png");
			/*if (check == 0)
			{
				egg.movement = 0;
			}*/
		}
		else if (check == 0)
		{
			eggy1 = CP_Image_Load("./Assets/eggy_LRUN.png");
			/*if (check == 1)
			{
				egg.movement = 0;
			}*/
		}
	}
	if (egg.start == 2)
	{
		if (CP_Input_KeyDown(KEY_SPACE))
		{
			if (egg.jjump == 0)
			{
				egg.isjump = 1;
				++egg.jjump;
			}
		}
	}
	egg.x += egg.movement;
	if (egg.movement >= maxspeed)
	{
		egg.movement = maxspeed;
	}
	if (egg.movement <= -maxspeed)
	{
		egg.movement = -maxspeed;
	}
	eggjump();// egg jumping 
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Image_Draw(eggy1, (float)egg.x, (float)egg.y, 100, 100, 255);
}
void eggs_exit(void)
{
	egg.x = 0;
	egg.y = 0;
	egg.maxaccel = 0;
	egg.isjump = 0;
	egg.h = 0;
	egg.movement = 0;
	egg.start = 0;
	egg.count = 0;
	CP_Image_Free(&eggy1);
}