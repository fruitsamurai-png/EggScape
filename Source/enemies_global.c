#include "cprocessing.h"
#include "../Header/character.h"
#include "../Header/rat.h"
#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/enemies_global.h"
#include "../Header/platform_global.h"

void enemies_init(void)
{
	mouse_init();
	hand_init();
}
void enemies_update(void)
{
	if (rand == 1)
	{
		mouse_update();
	}
	if (rand == 2)
	{
		hand_update();
	}
	if (rand == 3)
	{

	}
}
void enemies_exit(void)
{
	mouse_exit();
	hand_exit();
}