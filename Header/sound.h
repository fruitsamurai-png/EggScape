#pragma once
struct sound
{
	int jump;
	int Djump;
	int breakjump;
	int fisthit;
	int rathit;
}sound;
void sound_init(void);
void sound_update(void);
void sound_exit(void);