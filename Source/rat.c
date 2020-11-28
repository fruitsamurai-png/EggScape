#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/button.h"
#include "../Header/gameover.h"
#include "../Header/character.h"
#include "../Header/rat.h"
#include "cprocessing.h"
#include <time.h>
int mtimer = 0;
CP_Image rat = NULL;
void mouse_init(void)
{
	mouse.x = 0;
	mouse.y = 0;
	mouse.speed = 10;
	rat = CP_Image_Load("./Assets/rat.png");
}
void mouse_update(void)
{
	++mtimer;
	mouse.x += mouse.speed;
	if (mouse.x > (windowx - 100) || mouse.x < 0)
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
	CP_Image_Draw(rat, mouse.x, mouse.y, blocksize, blocksize, 255);
}
void mouse_exit(void)
{
	mouse.x = 0;
	mouse.y = 0;
	mouse.speed = 10;
	mtimer = 0;
	CP_Image_Free(&rat);
}