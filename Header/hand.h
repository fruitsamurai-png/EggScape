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
void hand_init(void);
void hand_update(void);
void hand_exit(void);
void hands_movement(void);
void hand_Collision(void);
