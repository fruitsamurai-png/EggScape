#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/gameover.h"
#include "../Header/character.h"
#include "../Header/platform_global.h"
#include "../Header/sound.h"
#include "cprocessing.h"
#include <time.h>


int htimer = 0;
CP_Image hand = NULL;
CP_Image handout = NULL;
CP_Image handgrab = NULL;
CP_Image handattack = NULL;
void hand_Collision(void)
{
	if (
		egg.x + blocksize > (hand_full.positionX - (blocksize / 2 * .5f)) &&
		egg.x< (hand_full.positionX - (blocksize / 2 * .5f) + blocksize * .75f) &&
		egg.y + blocksize>hand_full.positionY &&
		egg.y < hand_full.positionY + blocksize
		)
	{
		htimer = 0;
		sound.fisthit = 1;
		CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
		platform_global_init();
	}
	//CP_Graphics_DrawRect(hand_full.positionX-(blocksize/2*.5f), hand_full.positionY, hand_full.sizeX, hand_full.sizeY);
}

void hands_movement(void)
{
	if (hand_full.positionY > WINDOW_HEIGHT * 0.99 && htimer <= attackinter)
	{
		hand = handout;
		hand_full.positionX += hand_full.speed * CP_System_GetDt();
		if (hand_full.positionX > (windowx - 100) && hand_full.speed > 0)
		{
			hand_full.speed *= -1;
		}
		else if (hand_full.positionX < 50 && hand_full.speed < 0)
		{
			hand_full.speed *= -1;
		}
	}
	
	//attaCKKKKKKKKKKKKKKKKKKKKKKK
	if(hand_full.positionY > WINDOW_HEIGHT * 0.99)//timer++
	htimer++;
	if (htimer >= attackinter && hand_full.positionY > WINDOW_HEIGHT / 2)//attack
	{
		hand = handgrab;
		if(htimer >= attackinter+50)
		{
			hand = handattack;
			hand_full.positionY += -50;
		}
	}
	if (hand_full.positionY < WINDOW_HEIGHT / 2)//reset timer, stop attack
	{
		htimer = 0;
	}
	if (hand_full.positionY < WINDOW_HEIGHT)//drop
	{
		hand_full.positionY += 5;
	}
}

void hand_init(void)
{
	handgrab = CP_Image_Load("./Assets/Enemy/hand_closed.png");
	handout = CP_Image_Load("./Assets/Enemy/hand_open.png");
	handattack = CP_Image_Load("./Assets/Enemy/hand_attack.png");

	hand_full.increment = -4;
	hand_full.speed = 40;
	hand_full.positionY = WINDOW_HEIGHT;
	hand_full.positionX = (float)CP_Random_RangeInt(10,windowx);
	hand_full.sizeX = 200;
	hand_full.sizeY = 200;
}

int hand_update(int yes)
{	
	if (yes)
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
	hand_full.positionY = WINDOW_HEIGHT;
}


