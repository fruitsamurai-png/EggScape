//---------------------------------------------------------
// file:	enemies_global.c
// author:	Chen Yen Hsun,Chng Nai Wei Keith
// email:	c.yenhsun@digipen.edu
//			n.chng@digipen.edu
//
// brief:	system for the enemies to appear 
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "../Header/character.h"
#include "../Header/rat.h"
#include "../Header/hand.h"
#include "../Header/main.h"
#include "../Header/enemies_global.h"
#include "../Header/platform_global.h"
void enemies_init(void)//initialise the individual enemie functions
{
	mouse_init(2);
	hand_init();
	ratnum = 0;//number of rats
	handnum = 0;//boolean to determine the hand is active
}
void enemies_update(void)
{
	switch (variation)//switch to spawn the type and amount of enemies that can appear
	{
		case 0:
		{
			ratnum = 0;
			handnum = 0;
			break;
		}
		case 1:
		{
			ratnum = 1;
			handnum = 0;
			break;
		}
		case 2:
		{
			ratnum = 1;
			handnum = 1;
			break;
		}
		case 3:
		{
			ratnum = 2;
			handnum = 1;
			break;
		}
		default:
		{
			ratnum = 2;
			handnum = 1;
			break;
		}
	}
	mouse_update(ratnum);//update functions for the rat and hand
	hand_update(handnum);
}
void enemies_exit(void)//exit function for the enemies
{
	mouse_exit(handnum);
	hand_exit();
	ratnum = 0;
	handnum = 0;
}