#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/gameover.h"
#include "../Header/character.h"
#include "cprocessing.h"
#include <time.h>


int htimer = 0, mtimer= 0;
CP_Image hand = NULL;
void hand_Collision(void)
{
	if (CP_Math_Square(hand_full.positionX - egg.x) < CP_Math_Square((hand_full.sizeX / 2 + 50)) && CP_Math_Square((hand_full.positionY - egg.y)) < CP_Math_Square((hand_full.sizeY / 2 + 50))
		||
		egg.x + blocksize > (hand_full.positionX - (blocksize / 2 * .5f)) &&
		egg.x< (hand_full.positionX - (blocksize / 2 * .5f) + blocksize * .75f) &&
		egg.y + blocksize>hand_full.positionY &&
		egg.y < hand_full.positionY + blocksize
		)
	{
		htimer = 0;
		CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);

	}
	//CP_Graphics_DrawRect(hand_full.positionX-(blocksize/2*.5f), hand_full.positionY, blocksize*.75, blocksize);
}

void hands_movement(void)
{
	if (hand_full.positionY > WINDOW_HEIGHT * 0.99 && htimer <= attackinter)
	{
		hand = CP_Image_Load("./Assets/hand_OUT.png");
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
		hand = CP_Image_Load("./Assets/hand_GRAB.png");
		if(htimer >= attackinter+50)
		{
			hand_full.positionY += -50;
		}
	}
	if (hand_full.positionY < WINDOW_HEIGHT / 2)//reset timer, stop attack
	{
		htimer = 0;
	}
	if(hand_full.positionY<WINDOW_HEIGHT)//drop
	hand_full.positionY += 5;
	//CP_Graphics_DrawRect(0, WINDOW_HEIGHT * 0.9f, windowx, 5);
	//CP_Graphics_DrawRect(0, hand_full.positionY-5, windowx, 5);


}

void mouse_body(void)
{
	++mtimer;
	mouse.x += mouse.speed;
	if (mouse.x > (windowx - 100) || mouse.x<0)
	{
		mouse.speed *= -1;	
	}
	if (mtimer > 120)
	{
		mouse.speed = 0;
		mouse.y += 20;
	}
	if (mouse.y > windowy)
	{
		mouse.y = 0;
		mouse.speed = 5;
		mtimer = 0;
	}
	if (mouse.x + blocksize > egg.x &&
		mouse.x <egg.x + blocksize &&
		mouse.y + blocksize>egg.y &&
		mouse.y < egg.y + blocksize)
	{
		mtimer = 0;
		CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
	}
	CP_Graphics_DrawRect(mouse.x, mouse.y, blocksize, blocksize);
}

void mouse_init(void)
{
	mouse.x = 0;
	mouse.y=0;	
	mouse.speed = 10;

}
//CP_Image hand_bottom;
void hand_init(void)
{
	hand = CP_Image_Load("./Assets/game_HAND.png");
	hand_full.increment = -4;
	hand_full.speed = 40;
	hand_full.positionY = WINDOW_HEIGHT;
	hand_full.positionX = (float)CP_Random_RangeInt(10,windowx);
	mouse_init();

}

void hand_update(void)
{	
	//raise_hands();
	hands_movement();
	//hand = CP_Image_Load("./Assets/hand_OUT.png");
	//if (CP_System_GetFrameCount() % 30 == 10)
	//{
	//	//hand = CP_Image_Load("./Assets/hand_OUT.png");
	//}

	//else if (CP_System_GetFrameCount() % 30 == 0)
	//{
	//	//hand = CP_Image_Load("./Assets/hand_GRAB.png");
	//}
	hand_Collision();
	mouse_body();
	

	CP_Image_Draw(hand, (float)(hand_full.positionX) , (float)hand_full.positionY, 200, 200, 255);
}

void hand_exit(void)
{
	CP_Image_Free(&hand);
}


