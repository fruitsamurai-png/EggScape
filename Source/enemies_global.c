#include "cprocessing.h"
#include "../Header/character.h"
#include "../Header/rat.h"
#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/enemies_global.h"
#include "../Header/platform_global.h"
#include "../Header/plate.h"
void enemies_init(void)
{
	mouse_init(2);
	plates_init(2);
	hand_init();
	ratnum = 0;
	handnum = 0;
	platenum = 0;
}
void enemies_update(void)
{
	switch (variation)
	{
		case 0:
		{
			ratnum = 0;
			handnum = 0;
			platenum = 1;
			break;
		}
		case 1:
		{
			ratnum = 0;
			handnum = 1;
			platenum = 1;
			break;
		}
		case 2:
		{
			ratnum = 1;
			handnum = 1;
			platenum = 1;
			break;
		}
		case 3:
		{
			ratnum = 1;
			handnum = 1;
			platenum = 1;
			break;
		}
		default:
		{
			ratnum = 2;
			handnum = 1;
			platenum = 2;
			break;
		}
	}
	mouse_update(ratnum);
	hand_update(handnum);
	plates_update(platenum);
}
void enemies_exit(void)
{
	mouse_exit(handnum);
	plates_exit(platenum);
	hand_exit();
	ratnum = 0;
	handnum = 0;
	platenum = 0;
}