#pragma once
struct mouse
{
	float x, y, movement, speed;
}mouse;
struct mouse mouse;
void mouse_init(void);
void mouse_update(void);
void mouse_exit(void);