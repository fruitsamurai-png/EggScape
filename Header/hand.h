#pragma once

struct hands
{
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	int speed;
}hands;


struct hand_bottom
{
	int positionx;
	int positiony;
	float sizex;
	float sizey;

}hand_bottom;

void hand_init(void);
void hand_update(void);
void hand_exit(void);
static void raise_hands(void);
void hands_movement(void);
void hand_Collision(void);
