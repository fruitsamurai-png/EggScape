#pragma once
CP_Vector vector, eggvector;
struct egg {

	float movement, maxaccel;//movement is velocity, accel is acceleration
	float x, y, h, drop;//position of egg in terms of x and y. h is the jumping height
	int isjump, jjump, isdrop, start, count;// a boolean that determine when the egg is jumping it must come down
	int score;
}egg;
void eggjump(void);
void eggs_init(void);
void eggs_update(void);
void eggs_exit(void);