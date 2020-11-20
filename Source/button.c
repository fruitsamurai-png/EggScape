#include "../Header/button.h"
#include "Cprocessing.h"
#include "../Header/mainmenu.h" 
#include "../Header/howtoplay.h"
#include "../Header/main.h"
#include "../Header/gameover.h"

void play(Button button)
{
	//timer2 = 4.0f;


	if (CP_Input_MouseClicked())
	{
		if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
			CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
			CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
			CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2)
		{
			timer3 = 5.5f;
			check = 1;

		}
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
		else if (check==1)
		{
			CP_Engine_SetNextGameState(game_init, game_update, game_exit);
			check = 0;
		}
		timer3 -= dt;
	}
	CP_Image_Draw(eggy, x + speed, WINDOW_HEIGHT - 85, 200, 200, 255);
}

//void start_Game(void)
//{
//	x = 80;
//	if (timer3 > 0)
//	{
//		dt = CP_System_GetDt();
//
//		if (speed < WINDOW_WIDTH)
//		{
//			speed += 20;
//		}
//		else
//		{
//			CP_Engine_SetNextGameState(game_init, game_update, game_exit);
//		}
//		timer3 -= dt;
//	}
//	CP_Image_Draw(eggy, x + speed, WINDOW_HEIGHT - 85, 200, 200, 255);
//}

void howtoplay(Button button)
{
	if (CP_Input_MouseClicked())	//where the collision takes place when mouse is clicked on the how to play button (font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
			CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
			CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
			CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2)
		{
			CP_Engine_SetNextGameState(howtoplay_init, howtoplay_update, howtoplay_exit);	//if the mouse is clicked, it will proceed to the howtoplay screen
		}
	}
}

void exitgame(Button button) //making a exit button to proceeed to terminate the game
{
	if (CP_Input_MouseClicked())
	{
		if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
			CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
			CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
			CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2)
		{

			CP_Engine_Terminate();	//if the mouse is clicked, it will terminate the screen
		}
	}
}

void menu(Button button)	//making a menu button to proceeed to the main menu screen when the user died
{
	if (CP_Input_MouseClicked()) // where the collision takes place when mouse is clicked on the menu button(font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
			CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
			CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
			CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2)
		{
			CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);	//if the mouse is clicked, it will proceed to the main menu screen
		}
	}
}

void restart(Button button)	//making a restart button to proceeed to the main screen when the user died
{
	if (CP_Input_MouseClicked())	// where the collision takes place when mouse is clicked on the restart button(font) and if it is not in the boundary of the mouse clicked, it won't proceed anywhere
	{
		if (CP_Input_GetMouseX() >= button.positionX - button.sizeX / 2 &&
			CP_Input_GetMouseX() <= button.positionX + button.sizeX / 2 &&
			CP_Input_GetMouseY() >= button.positionY - button.sizeY / 2 &&
			CP_Input_GetMouseY() <= button.positionY + button.sizeY / 2)
		{
			CP_Engine_SetNextGameState(game_init, game_update, game_exit);	//if the mouse is clicked, it will proceed to the main screen
		}
	}
}

void init_button(void)
{
	playButton.image = CP_Image_Load("./Assets/mainmenu_RUN.png");
	playButton.positionX = WINDOW_WIDTH * 1 / 11;
	playButton.positionY = WINDOW_HEIGHT * 3 / 4;
	playButton.sizeX = 100;
	playButton.sizeY = 50;

	howtoplayButton.image = CP_Image_Load("./Assets/mainmenu_INSTRUCTIONS.png");
	howtoplayButton.positionX = WINDOW_WIDTH / 2;
	howtoplayButton.positionY = WINDOW_HEIGHT * 3 / 4;
	howtoplayButton.sizeX = 250;
	howtoplayButton.sizeY = 50;

	exitButton.image = CP_Image_Load("./Assets/mainmenu_EXIT.png");
	exitButton.positionX = WINDOW_WIDTH * 10 / 11;
	exitButton.positionY = WINDOW_HEIGHT * 3 / 4;
	exitButton.sizeX = 80;
	exitButton.sizeY = 50;
	check = 0;
	timer3 = 0;
	speed = 0;
	x = 80;
}

void init_button2(void)  //howtoplay screen buttons positioning
{
	playButton.image = CP_Image_Load("./Assets/mainmenu_RUN.png");
	playButton.positionX = WINDOW_WIDTH * 10 / 11;
	playButton.positionY = WINDOW_HEIGHT * 8 / 9;
	playButton.sizeX = 100;
	playButton.sizeY = 50;

	menuButton.image = CP_Image_Load("./Assets//Snake_MAINMENU.png");
	menuButton.positionX = WINDOW_WIDTH / 2;
	menuButton.positionY = WINDOW_HEIGHT / 2;
	menuButton.sizeX = 5;
	menuButton.sizeY = 50;
}

void init_button3(void)  //gameover screen buttons positioning
{
	restartButton.image = CP_Image_Load("./Assets/gameover_RESTART.png");
	restartButton.positionX = WINDOW_WIDTH / 2;
	restartButton.positionY = WINDOW_HEIGHT * 4 / 5;
	restartButton.sizeX = 200;
	restartButton.sizeY = 50;

	menuButton.image = CP_Image_Load("./Assets/gameover_MAINMENU.png");
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
}