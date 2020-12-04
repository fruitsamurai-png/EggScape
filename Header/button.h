#pragma once

#include "cprocessing.h"

//Implementing the button structure
typedef struct Button
{
	CP_Image image;
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	float locx;
	int mc;

}Button;

// Making button functions for each requires buttons needed in all screens
Button playButton;
Button howtoplayButton;
Button exitButton;
Button menuButton;
Button restartButton;
Button creditButton;

//indicating where the functions should be placed within the area in all three screens
float timer3;
float timer2;
float speed;
float x;
float dt;
int start;


//prototypes of mainmenu, how to play and gameover screens

void play(Button button);
void howtoplay(Button button);
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
void exit_button2(void);
void exit_button3(void);
void exit_button4(void);