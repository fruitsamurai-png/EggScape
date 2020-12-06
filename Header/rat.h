#pragma once
struct mouse
{
	float x;//x position of the rat
	float y;//y position of the rat
	float speed;//movement speed
	float alpha;//opacity of the warning symbol
}mouse;
int mtimer;//timer for the rat to appear
struct mouse mouses[2];
void mouse_init(size_t count1);
void mouse_update(size_t count2);
void mouse_exit(size_t count3);