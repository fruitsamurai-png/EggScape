#pragma once
struct mouse
{
	float x, y, movement, speed,alpha;
}mouse;
int mtimer;
struct mouse mouses[2];
void mouse_init(size_t count1);
void mouse_update(size_t count2);
void mouse_exit(size_t count3);