#pragma once
int variation;
int count;
int isout;
int springtimer;
enum dimensions { dimw = 125, dimh = 50, };
void platform_global_init(void);
void platform_global_update(void);
void platform_global_exit(void);