#include "cprocessing.h"
#include "../Header/platform.h"
#include "../Header/main.h"
#include "../Header/collision.h"
#include "../Header/character.h"
#include "../Header/platform_moving.h"
#include "../Header/Score.h"
#include "../Header/gameover.h"

void collide(void)
{
	if (egg.x + egg.movement > (windowx - blocksize) || egg.x + egg.movement < 0)//teleport to the other side of the wall.
	{
		if (egg.x + egg.movement >= (windowx - blocksize))
		{
			egg.x = 0;
		}
		else if (egg.x + egg.movement <= 0)
		{
			egg.x = (windowx - blocksize);
		}
	}    
	if (egg.y > windowy)//death
	{
		CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
	}
}