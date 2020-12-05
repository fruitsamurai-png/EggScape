#pragma once
struct sound
{
	int jump;
	int Djump;
	int breakjump;
	int fisthit;
	int rathit;
	int intro;
	int alpha;
	int select;
	int spring;
	int ending;
	int endmusic;
}sound;
void sound_init(void);
void sound_update(void);
void sound_exit(void);