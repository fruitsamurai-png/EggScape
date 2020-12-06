//---------------------------------------------------------
// file:	button.c
// author:	Siti Nursafinah Binte Sumsuri
// email:	sitinursafinah.b@digipen.edu
//			
//
// brief:	functions for the individual buttons
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "Cprocessing.h"
#include "../Header/button.h"
#include "../Header/mainmenu.h" 
#include "../Header/howtoplay.h"
#include "../Header/main.h"
#include "../Header/gameover.h"
#include "../Header/credit.h"
#include "../Header/enemies_global.h"
#include "../Header/platform_global.h"
#include "../Header/character.h"
#include "../Header/sound.h"

CP_Image eggy = NULL;
void play(Button button)
{
	if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
		CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
		CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
		CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2
		)//collision of the play button
	{
		playButton.mc = 1;//mouse input boolean
		
		playButton.image = CP_Image_Load("./Assets/Buttons/RUN.png");//the play button image to show (RUN)
		if (CP_Input_MouseClicked()||
			CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER))
		{
			sound.select = 1;
			timer3 = 5.5f;
			start = 1;
		}
	}
	else if (button.locx == button.positionX && !howtoplayButton.mc  && !exitButton.mc && !creditButton.mc && !menuButton.mc)
	{
		playButton.image = CP_Image_Load("./Assets/Buttons/RUN.png");
		if (CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER)
			)
		{
			sound.select = 1;
			timer3 = 5.5f;
			start = 1;
		}

	}
	else
	{
		playButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_RUN.png");
		playButton.mc = 0;
	}
	if (CP_System_GetFrameCount() % 20 == 10)
	{
		eggy = CP_Image_Load("./Assets/Backgrounds/eggy_RSTAND.png");
	}

	else if (CP_System_GetFrameCount() % 20 == 0)
	{
		eggy = CP_Image_Load("./Assets/Backgrounds/eggy_RRUN.png");
	}
	x = 80;
	if (timer3 > 0)
	{
		dt = CP_System_GetDt();

		if (speed < windowx)
		{
			speed += 20;
		}
		else if (start)//go to next game state
		{
			CP_Engine_SetNextGameState(game_init, game_update, game_exit);
			start = 0;
		}
		timer3 -= dt;
	}
	CP_Image_Draw(eggy, x + speed, windowy - 85, 200, 200, 255);
}

void howtoplay(Button button)
{
	if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
		CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
		CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
		CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2
		)	//where the collision takes place when mouse is clicked on the how to play button (font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		howtoplayButton.mc = 1;
		howtoplayButton.image = CP_Image_Load("./Assets/Buttons/instructions_r.png");
		if (CP_Input_MouseClicked()||
			CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER)
			)
		{
			sound.select = 1;
			CP_Engine_SetNextGameState(howtoplay_init, howtoplay_update, howtoplay_exit);	//if the mouse is clicked, it will proceed to the howtoplay screen
		}
	}
	 else if (button.locx == button.positionX && !playButton.mc && !exitButton.mc && !creditButton.mc)
	{
		howtoplayButton.image = CP_Image_Load("./Assets/Buttons/instructions_r.png");
		if (CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER)
			)
		{
			sound.select = 1;
			CP_Engine_SetNextGameState(howtoplay_init, howtoplay_update, howtoplay_exit);	//if the mouse is clicked, it will proceed to the howtoplay screen
		}
	}
	else
	{
		howtoplayButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_INSTRUCTIONS.png");

	}
}

void exitgame(Button button) //making a exit button to proceeed to terminate the game
{
	if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
		CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
		CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
		CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2

		)
	{
		exitButton.mc = 1;
		exitButton.image = CP_Image_Load("./Assets/Buttons/Exit_r.png");
		if (CP_Input_MouseClicked()||
			CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER))
		{
			sound.select = 1;
			CP_Engine_Terminate();	//if the mouse is clicked, it will terminate the screen
		}
	}
	else if (button.locx == button.positionX && !playButton.mc && !howtoplayButton.mc && !creditButton.mc)
	{
		exitButton.image = CP_Image_Load("./Assets/Buttons/Exit_r.png");
		if (CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER)
			)
		{
			sound.select = 1;
			CP_Engine_Terminate();	//if the mouse is clicked, it will terminate the screen
		}
	}
	else
	{
		exitButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_EXIT.png");
	}
}

void menu(Button button)	//making a menu button to proceeed to the main menu screen when the user died
{
	if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
		CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
		CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
		CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2

		) // where the collision takes place when mouse is clicked on the menu button(font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		menuButton.mc = 1;
		menuButton.image = CP_Image_Load("./Assets/Buttons/menu_r.png");
		if (CP_Input_MouseClicked()||
			CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER)||
			CP_Input_KeyTriggered(KEY_ESCAPE)
			)
		{
			sound.select = 1;
			CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);	//if the mouse is clicked, it will proceed to the main menu screen
		}
	}
	else if (button.locx == button.positionX && !playButton.mc && !restartButton.mc)
	{
		menuButton.image = CP_Image_Load("./Assets/Buttons/menu_r.png");
		if (CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER) ||
			CP_Input_KeyTriggered(KEY_ESCAPE)
			)
		{
			sound.select = 1;
			CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);	//if the mouse is clicked, it will proceed to the main menu screen
		}
	}
	else
	{
		menuButton.image = CP_Image_Load("./Assets/Buttons/menu.png");
	}
}

void restart(Button button)	//making a restart button to proceeed to the main screen when the user died
{
	if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
		CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
		CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
		CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2

		)	// where the collision takes place when mouse is clicked on the restart button(font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		restartButton.mc = 1;
		restartButton.image = CP_Image_Load("./Assets/Buttons/restart_r.png");

		if (CP_Input_MouseClicked()||
			CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER)
			) 
		{
			sound.select = 1;
			CP_Engine_SetNextGameState(game_init, game_update, game_exit);//if the mouse is clicked, it will proceed to the main screen
		}
	}
	else if (button.locx == button.positionX && !menuButton.mc && !exitButton.mc)
	{
		restartButton.image = CP_Image_Load("./Assets/Buttons/restart_r.png");
		if (CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER)
			)
		{
			sound.select = 1;
			CP_Engine_SetNextGameState(game_init, game_update, game_exit);//if the mouse is clicked, it will proceed to the main screen
		}
	}
	else
	{
		restartButton.image = CP_Image_Load("./Assets/Buttons/restart.png");
	}
}

void credit(Button button)
{
	if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
		CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
		CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
		CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2

		)	// where the collision takes place when mouse is clicked on the restart button(font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		creditButton.image = CP_Image_Load("./Assets/Buttons/credit_r.png");
		creditButton.mc = 1;

		if (CP_Input_MouseClicked()||
			CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER)
			)
		{
			sound.select = 1;
			CP_Engine_SetNextGameState(credit_init, credit_update, credit_exit);	//if the mouse is clicked, it will proceed to the main screen
		}
	}
	else if (button.locx == button.positionX && !playButton.mc && !howtoplayButton.mc && !exitButton.mc)
	{
		creditButton.image = CP_Image_Load("./Assets/Buttons/credit_r.png");
		if (CP_Input_KeyTriggered(KEY_SPACE) ||
			CP_Input_KeyTriggered(KEY_ENTER)
			)
		{
			sound.select = 1;
			CP_Engine_SetNextGameState(credit_init, credit_update, credit_exit);	//if the mouse is clicked, it will proceed to the main screen
		}
	}
	else
	{
		creditButton.image = CP_Image_Load("./Assets/Buttons/credit.png");
		creditButton.mc = 0;
	}
}

void init_button(void)//intialise the coordinates for the buttons for each scene
{

	playButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_RUN.png");
	playButton.positionX = windowx * 1 / 11;
	playButton.positionY = windowy * 3 / 4;
	playButton.sizeX = 100;
	playButton.sizeY = 50;

	howtoplayButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_INSTRUCTIONS.png");
	howtoplayButton.positionX = windowx / 2;
	howtoplayButton.positionY = windowy * 3 / 4;
	howtoplayButton.sizeX = 250;
	howtoplayButton.sizeY = 50;

	exitButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_EXIT.png");
	exitButton.positionX = windowx * 10 / 11;
	exitButton.positionY = windowy * 3 / 4;
	exitButton.sizeX = 80;
	exitButton.sizeY = 50;
	start = 0;
	timer3 = 0;
	speed = 0;
	x = 80;

	creditButton.image = CP_Image_Load("./Assets/Buttons/credit.png");
	creditButton.positionX = 50;
	creditButton.positionY = 25;
	creditButton.sizeX = 75;
	creditButton.sizeY = 30;

}

void init_button2(void)  //howtoplay screen buttons positioning
{
	playButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_RUN.png");
	playButton.positionX = windowx * 10 / 11;
	playButton.positionY = windowy * 8 / 9;
	playButton.sizeX = 100;
	playButton.sizeY = 50;

	menuButton.image = CP_Image_Load("./Assets/Buttons/menu.png");
	menuButton.positionX = windowx * 8 / 11;
	menuButton.positionY = windowy * 8 / 9;
	menuButton.sizeX = 150;
	menuButton.sizeY = 50;
}

void init_button3(void)  //gameover screen buttons positioning
{
	restartButton.image = CP_Image_Load("./Assets/Buttons/gameover_RESTART.png");
	restartButton.positionX = windowx / 2;
	restartButton.positionY = windowy * 4 / 5;
	restartButton.sizeX = 200;
	restartButton.sizeY = 50;

	menuButton.image = CP_Image_Load("./Assets/Buttons/gameover_MAINMENU.png");
	menuButton.positionX = windowx / 2;
	menuButton.positionY = windowy * 6 / 7;
	menuButton.sizeX = 100;
	menuButton.sizeY = 40;
}

void init_button4(void)
{
	menuButton.image = CP_Image_Load("./Assets/Buttons/gameover_MAINMENU.png");
	menuButton.positionX = windowx / 2;
	menuButton.positionY = windowy * 0.85f;
	menuButton.sizeX = 100;
	menuButton.sizeY = 40;
}

void exit_button(void)
{
	start = 0;
	x = 80;
	speed = 0;
	CP_Image_Free(&howtoplayButton.image);
	CP_Image_Free(&playButton.image);
	CP_Image_Free(&exitButton.image);
	CP_Image_Free(&creditButton.image);
	CP_Image_Free(&eggy);
}
void exit_button2(void)
{
	CP_Image_Free(&playButton.image);
	CP_Image_Free(&menuButton.image);
}
void exit_button3(void)
{
	CP_Image_Free(&menuButton.image);
	CP_Image_Free(&restartButton.image);
}
void exit_button4(void)
{
	CP_Image_Free(&menuButton.image);
}