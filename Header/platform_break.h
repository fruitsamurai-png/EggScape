#pragma once

typedef struct plat_break {
	float dimx, dimy;
	int isbroken,alpha;
}plat_break;
plat_break plats_break[10];
void platform_break_init(int i);
void platform_break_update(int i);
void platform_break_exit(void);

