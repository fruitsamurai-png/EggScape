//---------------------------------------------------------
// file:	sound.c
// author:	Chen Yen Hsun
// email:	c.yenhsun@digipen.edu
//			
//
// brief:	System for the sound effects and music
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright ?2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "../Header/main.h"
#include "../Header/platform.h"
#include "../Header/character.h"
#include "../Header/collision.h"
#include "../Header/mainmenu.h"
#include "../Header/Score.h"
#include "../Header/platform_global.h"
#include "../Header/hand.h"
#include "../Header/howtoplay.h"
#include "../Header/sound.h"
#include "stdbool.h"

CP_Sound jump = NULL;
CP_Sound Djump = NULL;
CP_Sound breakjump = NULL;
CP_Sound fisthit = NULL;
CP_Sound rathit = NULL;
CP_Sound intro = NULL;
CP_Sound select = NULL;
CP_Sound spring = NULL;
CP_Sound ending = NULL;
CP_Sound endmusic = NULL;

CP_Image icons = NULL;
int i = 0;
void sound_init(void)
{
	Djump = CP_Sound_Load("./Assets/Sound/DJump.wav");
	jump = CP_Sound_Load("./Assets/Sound/jump.wav");
	breakjump = CP_Sound_Load("./Assets/Sound/Breakjump.wav");
	fisthit = CP_Sound_Load("./Assets/Sound/handhit.wav");
	rathit = CP_Sound_Load("./Assets/Sound/rat.wav");
	intro = CP_Sound_Load("./Assets/Sound/intro.wav");
	select = CP_Sound_Load("./Assets/Sound/selection.wav");
	spring = CP_Sound_Load("./Assets/Sound/spring.wav");
	ending = CP_Sound_Load("./Assets/Sound/eggdie.wav");
	endmusic = CP_Sound_Load("./Assets/Sound/endingmusic.wav");

	icons = CP_Image_Load("./Assets/Character/Icons.png");//load the mute and unmute buttons


	sound.jump = 0;
	sound.alpha = 0;
}
void sound_update(void)
{
	static float volume = .5f;
	if (CP_Input_KeyTriggered(KEY_M))//M to mute and unmute the sound in the game
	{
		if (!i)
		{
			CP_Sound_PauseAll();
			i = 1;
			sound.alpha = 255;
		}
		else if (i)
		{
			CP_Sound_ResumeAll();
			i = 0;
			sound.alpha = 255;
		}
	}
	if (i == 1)
	{
		CP_Image_DrawSubImage(icons, 700, 100, 50, 50, 0,0,128,128,sound.alpha);
		sound.alpha -= 4;// the alpha of the image will decrease over time
	}
	if (i == 0)
	{
		CP_Image_DrawSubImage(icons, 700, 100, 50, 50, 128, 0, 256, 128, sound.alpha);
		sound.alpha -= 4;
	}
	if (CP_Input_KeyTriggered(KEY_Q))//debug feature to reduce the volume
	{
		volume -= .02f;
		if (volume <= 0)
			volume = 0;
	}
	if (CP_Input_KeyTriggered(KEY_E))//debug feature to increasethe volume
	{
		volume += .02f;
		if (volume >= 1)
			volume = 1;
	}
		if (sound.jump)//whatever is below are the booleans that activate the sounds
		{
			CP_Sound_PlayAdvanced(jump, volume, 1, 0, CP_SOUND_GROUP_0);
			sound.jump = 0;
		}
		if (sound.Djump)
		{
			CP_Sound_PlayAdvanced(Djump, volume, 1, 0, CP_SOUND_GROUP_0);
			sound.Djump = 0;
		}
		if (sound.breakjump)
		{
			CP_Sound_PlayAdvanced(breakjump, volume, 1, 0, CP_SOUND_GROUP_0);
			sound.breakjump = 0;
		}
		if (sound.fisthit)
		{
			CP_Sound_PlayAdvanced(fisthit, volume, 1, 0, CP_SOUND_GROUP_0);
			sound.fisthit = 0;
		}
		if (sound.rathit)
		{
			CP_Sound_PlayAdvanced(rathit, volume, 1, 0, CP_SOUND_GROUP_0);
			sound.rathit = 0;
		}
		if (sound.select)
		{
			CP_Sound_PlayAdvanced(select, volume, 1, 0, CP_SOUND_GROUP_0);
			sound.select = 0;
		}
		if (sound.spring)
		{
			CP_Sound_PlayAdvanced(spring, volume-0.3f, 1, 0, CP_SOUND_GROUP_0);
			sound.spring = 0;
		}
		if (sound.ending)
		{
			CP_Sound_PlayAdvanced(ending, volume, 1, 0, CP_SOUND_GROUP_0);
			sound.ending = 0;
		}
		if (sound.endmusic)
		{
			CP_Sound_PlayAdvanced(endmusic, volume, 1, 1, CP_SOUND_GROUP_0);
			sound.endmusic = 0;
		}
		if (sound.intro)
		{

			CP_Sound_PlayAdvanced(intro, volume, 1, 1, CP_SOUND_GROUP_0);
			sound.intro = 0;
		}
}
void sound_exit(void)
{
	CP_Sound_Free(jump);
	CP_Sound_Free(Djump);
	CP_Sound_Free(breakjump);
	CP_Sound_Free(intro);
	CP_Sound_Free(select);
	CP_Sound_Free(fisthit);
	CP_Sound_Free(rathit);
	CP_Sound_Free(select);
	CP_Sound_Free(ending);
	CP_Sound_Free(endmusic);
	CP_Image_Free(&icons);
	sound.jump = 0;
}