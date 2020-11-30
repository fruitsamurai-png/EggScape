#pragma once

struct hands
{
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	int speed;
	int increment;
}hands;

struct hands hand_full;
#define attackinter 120
void hands_movement(void);
void hand_Collision(void);
void hand_init(void);
int hand_update(int yes);
void hand_exit(void);
