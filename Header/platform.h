#pragma once
struct level {

	enum areas { areax = 760, areay = 392, cordy = 833, cordx = 0 }platforms;
}level;
typedef struct plat {
	float dimx, dimy;
}plat;
enum dimensions { dimw = 125, dimh = 50, };
plat plats[10];
void platform_init(int i);
void platform_update(int i);
void platform_exit(void);