#include <Windows.h>

#include "ard.h"

int PORTC;
int PORTD;

void delay(int milli) {
	Sleep(milli);
}

int random(int max) {
	return rand()%max;
}

unsigned char pgm_read_byte_near(unsigned char *p) {
	return *p;
}