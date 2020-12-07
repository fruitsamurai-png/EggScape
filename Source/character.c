//---------------------------------------------------------
// file:	character.c
// author:	Chen Yen Hsun,Chng Nai Wei Keith
// email:	c.yenhsun@digipen.edu
//			n.chng@digipen.edu
//
// brief:	functions for the main egg character
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/collision.h"
#include "../Header/sound.h"
#include "../Header/gameover.h"
#include "../Header/platform_global.h"
#include "../Header/platform_spring.h"

CP_Image egg_r = NULL;
CP_Image egg_l = NULL;
CP_Image ready = NULL;
int check = 0;
float maxspeed = 0;
int timer = 0;
int alpha = 0;//it is the width of the bar of cooldown meter
int deadtimer = 0;

void dead(void)//function that plays the death animation for the character 
{
	if (egg.isdead)
	{
		if (egg.y < windowy + 50)//if the egg character is above the screen border, it will rotate and fall
		{
			egg.isjump = 0;
			egg.ro += 450 * CP_System_GetDt();
			egg.y += 20;
			egg.x -= 10;
		}
		else
		{
			deadtimer++;//timer for the character death so it can play the death sounds
			if (deadtimer > 10 || CP_Input_KeyTriggered(KEY_ANY))
			{
				sound.ending = 1;//boolean for the falling sound
				CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
				deadtimer=0;
			}
		}
	}
}
static void doublejump(void)//double jump feature
{
	CP_Settings_Fill(CP_Color_Create(120, 255, 0, 255));
	CP_Graphics_DrawRect(windowx * 3 / 4, 0, (float)alpha, 40);//this is for the implementation of double jump bar on the top right of the screen
	CP_Settings_TextSize(20);//how big the text size of Double jump to be
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));//the colour of the fill up bar to be (green)
	CP_Font_DrawText("Doublejump:", 470, 20);//the text to be for the bar of double jump

	if (CP_Input_KeyTriggered(KEY_SPACE))//if the user pressed the space bar
	{
		if (egg.cooldown == 0)//if the cooldown is at 0s, then the user can use the double jump by pressing the space bar
		{
			egg.isjump = 1;
			egg.cooldown = 1;
			egg.isgrounded = 0;
			alpha = 0;
			sound.Djump = 1;//once the press the space bar, there will be a jumping sound	
			egg.firstjump = 1;// the ready icon wont show up until the character use the double jump for the first time
			egg.alpha = 255; //this is to show the warning sign before an enemy it spawning
		}
	}
	if (!egg.isgrounded)//when the character isnt on the platform
	{
		egg.ro += 450 * CP_System_GetDt();//this is to rotate the character when using the double jump
	}
	if (egg.cooldown)//cooldown boolean for the double ability
	{
		timer++;
		if (alpha != 200)alpha = (int)(timer + CP_System_GetDt());
		if (alpha >= 200)//if the bar is filled,the cooldown is over
		{
			egg.cooldown = 0;
			timer = 0;
		}
	}
	if (egg.firstjump != 0 && egg.cooldown == 0 && CP_System_GetSeconds() != 100)//condition for the ready image to appear and disappear
	{
		CP_Image_DrawSubImage(ready, egg.x, egg.y - 75, 30, 30, 256, 0, 348, 128, egg.alpha);
		egg.alpha--;//the icon will reduce opacity over time
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
		egg.h = -46;//height of the egg when it jumps
		egg.isjump = 0;
	}
	if (springs->onspring == 1)//height of the egg when it is on the spring
	{
		egg.h = -70;
		springs->onspring = 0;
	}
	CP_Vector_Set(egg.x, egg.y);
}

void eggs_init(void)// the ready icon wont show up until the character use the double jump for the first time
{
	egg.maxaccel = 30;//max acceleration of the egg
	egg.isjump = 0;
	egg.isgrounded = 1;
	egg.h = 0;
	egg.x = plats[7].dimx + (0.5f * dimw);//x position of the egg
	egg.y = windowy / 2;//y position of the egg
	maxspeed = 30;
	egg.cooldown = 0;
	alpha = 200;
	egg.ro = 0;
	egg.firstjump = 0;
	egg.isdead = 0;
	egg_r = CP_Image_Load("./Assets/Character/egg_r.png");
	egg_l = CP_Image_Load("./Assets/Character/egg_l.png");
	ready = CP_Image_Load("./Assets/Character/Icons.png");
}
void eggs_update(void)
{
	eggy1 = egg_r;//initial position of the egg to facing right
	if (!egg.isdead)//boolean if the character isnt dead
	{
		if ((CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT)))//turn right
		{
			if (check == 0)egg.movement = 0;//if moving left and the player hits right,the movement speed will be 0 
			egg.movement += (egg.maxaccel * CP_System_GetDt());//movement speed of the egg
			check = 1;//if moving right , the check will be 1 
		}
		if ((CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT)))//turn left
		{
			if (check == 1)egg.movement = 0;//if moving right and the player hits left,the movement speed will be 0 
			egg.movement -= (egg.maxaccel * CP_System_GetDt());
			check = 0;//if moving left , the check will be 0 
		}

		eggy1 = check != 0 ? egg_r : egg_l;//ternary operator for the character to face left or right

		egg.x += egg.movement;//movement speed plus the position of the egg
		if (egg.movement >= maxspeed)//to cap the max speed of the egg
		{
			egg.movement = maxspeed;
		}
		if (egg.movement <= -maxspeed)
		{
			egg.movement = -maxspeed;
		}
		eggjump();// egg jumping 
		doublejump();//double ability
	}
	dead();//death function
	CP_Image_DrawAdvanced(eggy1, (float)egg.x, (float)egg.y, blocksize, blocksize, 255, egg.ro);//image of the egg
}
void eggs_exit(void)
{
	egg.x = 0;
	egg.y = 0;
	egg.maxaccel = 0;
	egg.isjump = 0;
	egg.h = 0;
	egg.movement = 0;
	timer = 0;
	alpha = 0;
	egg.ro = 0;
	egg.isdead = 0;
	CP_Image_Free(&eggy1);
	CP_Image_Free(&egg_l);
	CP_Image_Free(&egg_r);
	CP_Image_Free(&ready);
}