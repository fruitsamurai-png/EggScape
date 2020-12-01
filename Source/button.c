#include "../Header/button.h"
#include "Cprocessing.h"
#include "../Header/mainmenu.h" 
#include "../Header/howtoplay.h"
#include "../Header/main.h"
#include "../Header/gameover.h"
#include "../Header/credit.h"
#include "../Header/enemies_global.h"
#include "../Header/platform_global.h"
#include "../Header/character.h"

void play(Button button)
{
	//button.locx = button.positionX;
	if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
		CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
		CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
		CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2
		||
		button.locx == button.positionX
		)
	{
		playButton.image = CP_Image_Load("./Assets/Buttons/RUN.png");
		if (CP_Input_MouseClicked() || CP_Input_KeyTriggered(KEY_SPACE)||CP_Input_KeyTriggered(KEY_ENTER))
		{
			timer3 = 5.5f;
			check = 1;
		}
	}
	else
	{
		playButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_RUN.png");
	}
	if (CP_System_GetFrameCount() % 20 == 10)
	{
		eggy = CP_Image_Load("./Assets/eggy_RSTAND.png");
	}

	else if (CP_System_GetFrameCount() % 20 == 0)
	{
		eggy = CP_Image_Load("./Assets/eggy_RRUN.png");
	}
	x = 80;
	if (timer3 > 0)
	{
		dt = CP_System_GetDt();

		if (speed < WINDOW_WIDTH)
		{
			speed += 20;
		}
		else if (check == 1)
		{
			CP_Engine_SetNextGameState(game_init, game_update, game_exit);
			check = 0;
		}
		timer3 -= dt;
	}
	CP_Image_Draw(eggy, x + speed, WINDOW_HEIGHT - 85, 200, 200, 255);
}

void howtoplay(Button button)
{
	//button.locx = button.positionX;
	if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
		CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
		CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
		CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2
		||
		button.locx == button.positionX
		)	//where the collision takes place when mouse is clicked on the how to play button (font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		howtoplayButton.image = CP_Image_Load("./Assets/Buttons/instructions_r.png");
		if (CP_Input_MouseClicked() || CP_Input_KeyTriggered(KEY_SPACE)||CP_Input_KeyTriggered(KEY_ENTER))
		{
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
		||
		button.locx == button.positionX
		)
	{
		exitButton.image = CP_Image_Load("./Assets/Buttons/Exit_r.png");
		if (CP_Input_MouseClicked() || CP_Input_KeyTriggered(KEY_SPACE)||CP_Input_KeyTriggered(KEY_ENTER))
		{

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
		||
		button.locx == button.positionX
		) // where the collision takes place when mouse is clicked on the menu button(font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		menuButton.image = CP_Image_Load("./Assets/Buttons/menu_r.png");
		if (CP_Input_MouseClicked() || CP_Input_KeyTriggered(KEY_SPACE)||CP_Input_KeyTriggered(KEY_ENTER))
		{
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
		||
		button.locx == button.positionX
		)	// where the collision takes place when mouse is clicked on the restart button(font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		restartButton.image = CP_Image_Load("./Assets/Buttons/restart_r.png");

		if (CP_Input_MouseClicked() || CP_Input_KeyTriggered(KEY_SPACE)||CP_Input_KeyTriggered(KEY_ENTER))
		{
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
		||
		button.locx == button.positionX
		)	// where the collision takes place when mouse is clicked on the restart button(font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		creditButton.image = CP_Image_Load("./Assets/Buttons/credit_r.png");

		if (CP_Input_MouseClicked() || CP_Input_KeyTriggered(KEY_SPACE)||CP_Input_KeyTriggered(KEY_ENTER))
		{
			CP_Engine_SetNextGameState(credit_init, credit_update, credit_exit);	//if the mouse is clicked, it will proceed to the main screen
		}
	}
	else
	{
		creditButton.image = CP_Image_Load("./Assets/Buttons/credit.png");
	}
}

void init_button(void)
{

	playButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_RUN.png");
	playButton.positionX = WINDOW_WIDTH * 1 / 11;
	playButton.positionY = WINDOW_HEIGHT * 3 / 4;
	playButton.sizeX = 100;
	playButton.sizeY = 50;

	howtoplayButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_INSTRUCTIONS.png");
	howtoplayButton.positionX = WINDOW_WIDTH / 2;
	howtoplayButton.positionY = WINDOW_HEIGHT * 3 / 4;
	howtoplayButton.sizeX = 250;
	howtoplayButton.sizeY = 50;

	exitButton.image = CP_Image_Load("./Assets/Buttons/mainmenu_EXIT.png");
	exitButton.positionX = WINDOW_WIDTH * 10 / 11;
	exitButton.positionY = WINDOW_HEIGHT * 3 / 4;
	exitButton.sizeX = 80;
	exitButton.sizeY = 50;
	check = 0;
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
	playButton.positionX = WINDOW_WIDTH * 10 / 11;
	playButton.positionY = WINDOW_HEIGHT * 8 / 9;
	playButton.sizeX = 100;
	playButton.sizeY = 50;

	menuButton.image = CP_Image_Load("./Assets/Buttons/menu.png");
	menuButton.positionX = WINDOW_WIDTH * 8 / 11;
	menuButton.positionY = WINDOW_HEIGHT * 8 / 9;
	menuButton.sizeX = 150;
	menuButton.sizeY = 50;
}

void init_button3(void)  //gameover screen buttons positioning
{
	restartButton.image = CP_Image_Load("./Assets/Buttons/gameover_RESTART.png");
	restartButton.positionX = WINDOW_WIDTH / 2;
	restartButton.positionY = WINDOW_HEIGHT * 4 / 5;
	restartButton.sizeX = 200;
	restartButton.sizeY = 50;

	menuButton.image = CP_Image_Load("./Assets/Buttons/gameover_MAINMENU.png");
	menuButton.positionX = WINDOW_WIDTH / 2;
	menuButton.positionY = WINDOW_HEIGHT * 6 / 7;
	menuButton.sizeX = 100;
	menuButton.sizeY = 40;
}

void init_button4(void)
{
	menuButton.image = CP_Image_Load("./Assets/Buttons/gameover_MAINMENU.png");
	menuButton.positionX = WINDOW_WIDTH / 2;
	menuButton.positionY = WINDOW_HEIGHT * 6 / 7;
	menuButton.sizeX = 100;
	menuButton.sizeY = 40;
}

void exit_button(void)
{
	check = 0;
	x = 80;
	speed = 0;
	CP_Image_Free(&menuButton.image);
	CP_Image_Free(&restartButton.image);
	CP_Image_Free(&playButton.image);
	CP_Image_Free(&exitButton.image);
	CP_Image_Free(&creditButton.image);
}