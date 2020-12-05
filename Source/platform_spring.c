#include "cprocessing.h"
#include "../Header/platform_spring.h"
#include "../Header/platform_global.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/Score.h"
#include "../Header/sound.h"

CP_Image springes = NULL;
void springs_init(int i)
{
	springes = CP_Image_Load("./Assets/Platforms/spring.png");
	springs->onspring = 0;
}
void springs_update(int i)
{
	if (!egg.isjump)
	{
		if (egg.x < (springs[i].dimx + dimw - 10) &&
			(egg.x + blocksize - 5) > springs[i].dimx &&
			(egg.y + blocksize + 10) > springs[i].dimy &&
			egg.y < (springs[i].dimy) &&
			egg.h > 0)
		{
			sound.jump = 1;
			springs->onspring = 1;
			egg.isgrounded = 1;
			egg.ro = 0;
		}
	}
	CP_Image_Draw(springes, (springs[i].dimx), (springs[i].dimy), dimw, dimh, 255);
}
void springs_exit(void) 
{
	CP_Image_Free(&springes);
	springs->onspring = 0;
}