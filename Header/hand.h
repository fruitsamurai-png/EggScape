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
struct mouse
{
	float x, y,movement,speed;
}mouse;
struct hands hand_full;
struct mouse mouse;
#define attackinter 120
void hand_init(void);
void hand_update(void);
void hand_exit(void);
static void raise_hands(void);
void hands_movement(void);
void hand_Collision(void);
void mouse_init(void);
void mouse_drop(void);
