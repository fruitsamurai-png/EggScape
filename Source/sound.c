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

void sound_init(void)
{
	Djump = CP_Sound_Load("./Assets/DJump.wav");
	jump = CP_Sound_Load("./Assets/jump.wav");
	breakjump = CP_Sound_Load("./Assets/Breakjump.wav");
	fisthit = CP_Sound_Load("./Assets/handhit.wav");
	rathit = CP_Sound_Load("./Assets/rat.wav");
	sound.jump = 0;
}
void sound_update(void)
{
	static float volume = .5f;
	if (CP_Input_KeyTriggered(KEY_M))
	{
		static int i=0;
			if (!i)
			{
				CP_Sound_PauseAll();
					i=1;
			}
	
			else if (i)
			{
				CP_Sound_ResumeAll();
				i = 0;
			}
	}
	if (CP_Input_KeyDown(KEY_Q))
	{
		volume -= .02f;
		if (volume <= 0)
			volume = 0;
	}
	if (CP_Input_KeyDown(KEY_E))
	{
		volume += .02f;
		if (volume >= 1)
			volume = 1;
	}
		if (sound.jump)
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
		
}
void sound_exit(void)
{
	CP_Sound_Free(jump);
	CP_Sound_Free(Djump);
	CP_Sound_Free(breakjump);
	sound.jump = 0;
}