//---------------------------------------------------------
// file:	hand.c
// author:	Chen Yen Hsun,Siti Nursafinah Binte Sumsuri
// email:	c.yenhsun@digipen.edu
//			sitinursafinah.b@digipen.edu
//			
//
// brief:function for the hand enemy
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/gameover.h"
#include "../Header/character.h"
#include "../Header/platform_global.h"
#include "../Header/sound.h"
#include "cprocessing.h"
#include <time.h>


CP_Image hand = NULL;
CP_Image handout = NULL;
CP_Image handgrab = NULL;
CP_Image handattack = NULL;
void hand_Collision(void)// hand collision with the character
{
	if (
		egg.x + blocksize > (hand_full.positionX - (blocksize / 2 * .5f)) &&
		egg.x< (hand_full.positionX - (blocksize / 2 * .5f) + blocksize * .75f) &&
		egg.y + blocksize>hand_full.positionY &&
		egg.y < hand_full.positionY + blocksize
		)
	{
		htimer = 0;//timing interval for the hand attack is reset 
		sound.fisthit = 1;//sound effect for the hand
		egg.isdead = 1;//boolean that the character is dead
	}
}

void hands_movement(void)//calling the function to move the hand and its within the window's set
{
	if (hand_full.positionY > windowy * 0.99 && htimer <= attackinter)
	{
		hand = handout;//hand animation
		hand_full.positionX += hand_full.speed * CP_System_GetDt();//movement speed of the hand
		if (hand_full.positionX > (windowx - 100) && hand_full.speed > 0)
		{
			hand_full.speed *= -1;//direction toggle when the hand hit the right screen
		}
		else if (hand_full.positionX < 50 && hand_full.speed < 0)
		{
			hand_full.speed *= -1;//direction toggle when the hand hit the left screen
		}
	}
	
	if(hand_full.positionY > windowy * 0.99)//attack motion of the hand
	htimer++;//timer increase
	if (htimer >= attackinter && hand_full.positionY > windowy / 2)//attack
	{
		hand = handgrab;
		if (htimer >=attackinter+40)hand = handattack;//if the timer is near its time to attack, the animation will change to red

		if(htimer >= attackinter+50)
		{
			hand_full.positionY += -50;//the hand will go up
		}
	}
	if (hand_full.positionY < windowy / 2)//reset timer, stop attack
	{
		htimer = 0;
	}
	if (hand_full.positionY < windowy)//drop
	{
		hand_full.positionY += 5;
	}
}

void hand_init(void)
{
	handgrab = CP_Image_Load("./Assets/Enemy/hand_closed.png");
	handout = CP_Image_Load("./Assets/Enemy/hand_open.png");
	handattack = CP_Image_Load("./Assets/Enemy/hand_attack.png");
	htimer = 0;
	hand_full.increment = -4;
	hand_full.speed = 40;
	hand_full.positionY = windowy;
	hand_full.positionX = (float)CP_Random_RangeInt(10,windowx);
	hand_full.sizeX = 200;
	hand_full.sizeY = 200;
}

int hand_update(int yes)
{	
	if (yes)//boolean that determine the hand is active
	{
		hands_movement();
		hand_Collision();
		CP_Image_Draw(hand, (float)(hand_full.positionX), (float)hand_full.positionY, hand_full.sizeX, hand_full.sizeY, 255);
	}
	return yes;
}

void hand_exit(void)
{
	CP_Image_Free(&hand);
	CP_Image_Free(&handgrab);
	CP_Image_Free(&handout);
	CP_Image_Free(&handattack);
	htimer = 0;
	hand_full.positionY = windowy;
}


