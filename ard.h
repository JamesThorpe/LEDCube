#pragma once
#ifndef ard_h
#define ard_h

#include <stdlib.h>

extern int PORTC;
extern int PORTD;

extern void delay(int milli);
void digitalWrite(int pin, int level);
void pinMode(int pin, int level);
extern int random(int max);

#define HIGH 1
#define LOW 0

#define OUTPUT 1
#define INPUT 1

class SPI {
	public:
		static void transfer(unsigned char){};
};



#endif