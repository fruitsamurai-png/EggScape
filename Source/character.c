#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/collision.h"
#include "../Header/sound.h"
CP_Image eggy1=NULL;
CP_Image egg_r = NULL;
CP_Image egg_l = NULL;
int check=0;
float maxspeed = 0;
int timer = 0;
int alpha = 0;
static void doublejump(void)
{
	CP_Settings_Fill(CP_Color_Create(120, 255, 0, 255));
	CP_Graphics_DrawRect(windowx * 3 / 4, 0, (float)alpha, 40);
	CP_Settings_TextSize(20);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("Doublejump:", 470, 20);

	if (CP_Input_KeyTriggered(KEY_SPACE))
		{
			if (egg.cooldown == 0)
			{
				egg.isjump = 1;
				egg.cooldown = 1;
				egg.isgrounded = 0;
				alpha = 0;
				sound.Djump = 1;
			}
		}
	if (!egg.isgrounded)
	{
		egg.ro += 450*CP_System_GetDt();
	}
	if (egg.cooldown)
	{
		timer++;
		if(alpha!=200)alpha = (int)(timer+CP_System_GetDt());
		if (alpha >= 200)
		{
			egg.cooldown = 0;
			timer = 0;
		}
	}
}
static void eggjump(void)
{
	//mode1(normal Jump)
	float G = 10 * .2f;//gravity for the egg

		if (egg.h == 0)egg.h = 8;
		egg.h += 1.f * G;//velocity of the egg
		egg.y += .5f * egg.h;

	if (egg.isjump)
	{
		if (!egg.count)
		{
			egg.h = -60;
			egg.count = 1;
		}
		else egg.h = -40;
		egg.isjump = 0;
	}
	
	CP_Vector_Set(egg.x, egg.y);
}

void eggs_init(void)
{
	egg.x = (float)(windowy * 0.50);
	egg.y = (windowy * 0.50);
	egg.maxaccel = 30;
	egg.isjump = 0;
	egg.isgrounded = 1;
	egg.h = 0;
	egg.x = plats[7].dimx+(0.5f*dimw);
	egg.y = windowy / 2;
	egg.count = 0;
	maxspeed = 30;
	egg.cooldown = 0;
	alpha = 200;
	egg.ro=0;
	egg_r= CP_Image_Load("./Assets/egg_r.png");
	egg_l= CP_Image_Load("./Assets/egg_l.png");
}
void eggs_update(void)
{
	eggy1= egg_r;
	
		if ((CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT)))
		{
			if (check == 0)egg.movement = 0;
			egg.movement += (egg.maxaccel * CP_System_GetDt());
			check = 1;
		}
		if ((CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT)))
		{
			if (check == 1)egg.movement = 0;
			egg.movement -= (egg.maxaccel * CP_System_GetDt());
			check = 0;
		}
		if (check == 1)
		{
			eggy1 = egg_r;
	
		}
		else if (check == 0)
		{
			eggy1 = egg_l;
			
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
	doublejump();//double ability
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Image_DrawAdvanced(eggy1, (float)egg.x, (float)egg.y, blocksize, blocksize,255, egg.ro);
}
void eggs_exit(void)
{
	egg.x = 0;
	egg.y = 0;
	egg.maxaccel = 0;
	egg.isjump = 0;
	egg.h = 0;
	egg.movement = 0;
	egg.count = 0;
	timer = 0;
	alpha = 0;
	egg.ro = 0;
	CP_Image_Free(&eggy1);
	CP_Image_Free(&egg_l);
	CP_Image_Free(&egg_r);
}