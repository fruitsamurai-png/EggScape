#pragma once
struct plate
{
	float x, y, movement, speed, alpha;
	float ro;
}plate;
int ptimer;
struct plate plates[2];
void plates_init(size_t count1);
void plates_update(size_t count2);
void plates_exit(size_t count3);