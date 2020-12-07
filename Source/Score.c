//---------------------------------------------------------
// file:	score.c
// author:	Chng Nai Wei Keith,
// email:	n.chng@digipen.edu
//			
//
// brief: Score system that goes up when the level is elevated
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include"../Header/Score.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/gameover.h"
#include "../Header/platform_global.h"
#include <stdio.h>
#include <stdlib.h>
void score_init(void)
{
	temp=0;
	score = 0;
	memset(charbuffer, 0, 100 * sizeof(char));//fill the block of memory with 100 bytes of char to be used in the score system
}
void score_update(void)
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 30));
	CP_Graphics_DrawRect(0,0,windowx,40);//for the top rectangle that have the double jump meter
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("Score:", 10, 20);
	if(!egg.isdead)temp = (int)-egg.h;//it will record the score if the character is alive
	if(egg.h<0 && isout==1)egg.score = (int)temp;//it will record the score if the level is elevated only
	score += egg.score/10;//reduce the score divided by 10
	if (score < 0)score = 0;//to prevent negative values 
	_itoa_s(score, charbuffer, 100, 10);//convert the int to string
	CP_Font_DrawText(charbuffer,60 ,20);//store and display the value
	if (egg.isdead)deathscore = score;
}
void score_exit(void) 
{
	score = 0;
	memset(charbuffer, 0, 100 * sizeof(char));//restore value back to 0
}