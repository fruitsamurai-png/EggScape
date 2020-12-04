#pragma once
typedef struct spring {
	float dimx, dimy;
	int onspring;
}spring;
spring springs[10];
void springs_init(int i);
void springs_update(int i);
void springs_exit(void);