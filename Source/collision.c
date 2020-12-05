#include "cprocessing.h"
#include "../Header/main.h"
#include "../Header/collision.h"
#include "../Header/character.h"
#include "../Header/gameover.h"
#include "../Header/platform_global.h"
#include "../Header/enemies_global.h"
#include "../Header/Sound.h"

void collide(void)
{
	if (egg.x+blocksize/2 + egg.movement > (windowx - blocksize) || egg.x+blocksize/2 + egg.movement < 0)//teleport to the other side of the wall.
	{
		if (egg.x + egg.movement >= (windowx))
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
		egg.isdead = 1;
	}
}