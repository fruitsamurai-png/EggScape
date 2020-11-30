#include "cprocessing.h"
#include "../Header/character.h"
#include "../Header/rat.h"
#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/enemies_global.h"
#include "../Header/platform_global.h"

void enemies_init(void)
{
	mouse_init(10);
	hand_init();
	ratnum = 0;
	handnum = 0;
}
void enemies_update(void)
{
	if (rand == 0)
	{
		ratnum = 0;
	}
	if (rand == 1)
	{
		ratnum = 1;
		handnum = 1;
	}
	if (rand == 2)
	{
		ratnum = 2;
		handnum=1;
	}
	if (rand >= 3)
	{
		ratnum = 3;
		handnum = 1;
	}
	mouse_update(ratnum);
	hand_update(handnum);
}
void enemies_exit(void)
{
	mouse_exit(handnum);
	hand_exit();
	ratnum = 0;
	handnum = 0;
}