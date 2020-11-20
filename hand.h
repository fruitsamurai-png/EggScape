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

void hand_init(void);
void hand_update(void);
void hand_exit(void);
static void raise_hands(void);
void hands_movement(void);
void hand_Collision(void);