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