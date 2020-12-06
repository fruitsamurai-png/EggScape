#pragma once
CP_Vector vector, eggvector;
struct egg {

	float movement, maxaccel;//movement is velocity, accel is acceleration
	float x, y, h,ro;//position of egg in terms of x and y. h is the jumping height.ro is the rotation of the egg
	int isjump;// a boolean that determine when the egg is jumping it must come down
	int cooldown;//cooldown for the double abilities
	int isgrounded;//a boolean when the character is on the platform
	int firstjump;// the ready icon wont show up until the character use the double jump for the first time
	int isdead;//a boolean when the character egg is dead
	int score;//raw score for the egg
	int alpha;//opacity for the ready symbol for the double jump
}egg;
CP_Image eggy1;
void eggs_init(void);
void eggs_update(void);
void eggs_exit(void);