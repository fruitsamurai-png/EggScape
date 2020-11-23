#include "cprocessing.h"
#include"../Header/Score.h"
#include "../Header/main.h"
#include "../Header/character.h"
#include "../Header/collision.h"
#include "../Header/platform.h"
#include "../Header/platform_moving.h"
#include <stdio.h>
#include <stdlib.h>
char charbuffer[100];
int temp;
void score_init(void)
{
	temp=0;
	score = 0;
	memset(charbuffer, 0, 100 * sizeof(char));
}
void score_update(void)
{
	
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 30));
	CP_Graphics_DrawRect(0,0,windowx,40);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("Score:", 10, 20);
	temp = (int)-egg.h;
	if(egg.h<0 )egg.score = (int)temp;
	score += egg.score/10;
	if (score < 0)score = 0;
	_itoa_s(score, charbuffer, 100, 10);
	CP_Font_DrawText(charbuffer,50 ,20);

}
void score_exit(void) 
{
	score = 0;
	memset(charbuffer, 0, 100 * sizeof(char));
}