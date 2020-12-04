#pragma once
typedef struct plat {
	float dimx, dimy;
}plat;
plat plats[10];
void platform_init(int i);
void platform_update(int i);
void platform_exit(void);