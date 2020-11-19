#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/gameover.h"
#include "../Header/character.h"
#include "cprocessing.h"

struct hands hand_full;
//struct hand_bottom hands_bottom;
CP_Image hand=NULL;

int increment = -3;
static void raise_hands(void)
{
	if ((hand_full.positionY - 100) < (WINDOW_HEIGHT * 1.0f / 4.0f))
	{
		increment = 4;
	}

	else if ((hand_full.positionY + 100) > WINDOW_HEIGHT)
	{
		increment = -5;
	}

	hand_full.positionY += increment;
}
void hand_Collision(void)
{
	if (CP_Math_Square(hand_full.positionX - egg.x) < CP_Math_Square((hand_full.sizeX / 2 + 50)) && CP_Math_Square((hand_full.positionY - egg.y)) < CP_Math_Square((hand_full.sizeY / 2 + 50)))
	{
		CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
	}
}
void hands_movement(void)
{
	hand_full.positionX += hand_full.speed * CP_System_GetDt();
	if (hand_full.positionX> (windowx-100) && hand_full.speed > 0)
	{
		hand_full.speed *= -1;
	}
	else if (hand_full.positionX<50 && hand_full.speed < 0)
	{
		hand_full.speed *= -1;
	}
}
//CP_Image hand_bottom;
void hand_init(void)
{
	hand = CP_Image_Load("./Assets/game_HAND.png");
	hand_full.speed = 40;
	hand_full.positionY = WINDOW_HEIGHT;
	hand_full.positionX = (float)CP_Random_RangeInt(10,windowx);
}

void hand_update(void)
{
	hands_movement();
	//if (timer3 > 0)//whats this???
	//{
	//	dt = CP_System_GetDt();

	//	if (speed < WINDOW_WIDTH)
	//	{
	//		speed += 20;
	//	}
	//	else
	//	{

	//	}
	//	timer3 -= dt;
	//}
	if (CP_System_GetFrameCount() % 30 == 10)
	{
		hand = CP_Image_Load("./Assets/hand_OUT.png");
	}

	else if (CP_System_GetFrameCount() % 30 == 0)
	{
		hand = CP_Image_Load("./Assets/hand_GRAB.png");
	}
	hand_Collision();
	raise_hands();
	CP_Image_Draw(hand, (float)(hand_full.positionX) , (float)hand_full.positionY, 200, 200, 255);
}

void hand_exit(void)
{
	CP_Image_Free(&hand);
}


