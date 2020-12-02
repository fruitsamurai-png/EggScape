#pragma once

#include "cprocessing.h"

//Implementing the button structure
typedef struct Button
{
	CP_Image image;
	char* text;
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	float locx;

}Button;

// Making button functions for each requires buttons needed in all screens
Button playButton;
Button howtoplayButton;
Button exitButton;
Button menuButton;
Button restartButton;
Button creditButton;

//indicating where the functions should be placed within the area in all three screens
float WINDOW_HEIGHT;
float WINDOW_WIDTH;
float timer3;
float timer2;
float speed;
float x;
float i;
float dt;
int check;

CP_Image eggy;
CP_Image hand;

//prototypes of mainmenu, how to play and gameover screens

void play(Button button);
void howtoplay(Button button);
void menu(Button button);
void restart(Button button);
void menu(Button button);
void credit(Button button);
void exitgame(Button button);

//void start_Game(void);

void init_button(void);

void init_button2(void);

void init_button3(void);

void init_button4(void);

void exit_button(void);