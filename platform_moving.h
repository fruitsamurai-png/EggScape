#pragma once
typedef struct plat_moving {
	float dimx, dimy;
	int time, speed;
}plat_moving;
plat_moving plats_moving[10];
void platform_moving_init(void);
void platform_moving_update(int i);
void platform_moving_exit(void);