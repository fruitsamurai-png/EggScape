#pragma once

struct hands
{
	float positionX;//x position of the hand
	float positionY;//y position of the hand
	float sizeX;//size of the hand
	float sizeY;
	int speed;//speed of the hand
	int increment;//position y increment when it attacks
}hands;
int htimer;
struct hands hand_full;
#define attackinter 120//timer interval for the attack
void hands_movement(void);
void hand_Collision(void);
void hand_init(void);
int hand_update(int yes);
void hand_exit(void);
