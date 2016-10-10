#include <TimerOne.h>

#include <SPI.h>
#include "cube.h"

#include "core.h"

#define PIN_SINKLATCH	9
#define PIN_SINKDATA	11 //SPI
#define PIN_SINKOUTPUT	8
#define PIN_SINKCLOCK	13 //SPI

#define PIN_LAYERSELECTA 5
#define PIN_LAYERSELECTB 6
#define PIN_LAYERSELECTC 7
#define PIN_LAYERENABLE 4


Cube *cube;


char currentLayer = 0;
unsigned char portMask = (1<<4) | (1<<3) | (1<<2) | (1<<1) | 1;
void isr_output() {
	//get a pointer to the next layer - 8 bytes worth
	unsigned char* layer;
    layer = cube->GetLayer(currentLayer);


	//get ready for latching data
	digitalWrite(PIN_SINKLATCH, HIGH);

	//loop through and send layer information to columns.  Use built in arduino SPI hardware for speed
	char bc = 7;
	do {
          SPI.transfer(layer[bc]);
	} while (--bc >=0);
	
	//disable layer - turn off entire cube
	digitalWrite(PIN_LAYERENABLE, LOW);  // *** keep minimal code between here...

	//latch column data
	digitalWrite(PIN_SINKLATCH, LOW);

	//PORTD = 00-07, using 05 - 07 for layer.  00 & 01 are serial
	PORTD = (PORTD & portMask) | ((currentLayer) << 5);

	//enable source
	digitalWrite(PIN_LAYERENABLE, HIGH);  // *** ...and here - any time spent between these lines is time the cube isn't on at all

	//get ready for next layer
	if (++currentLayer == 8) currentLayer = 0;
}

void setup () {
  	cube = new Cube();
	
	pinMode(PIN_LAYERSELECTA, OUTPUT);
	pinMode(PIN_LAYERSELECTB, OUTPUT);
	pinMode(PIN_LAYERSELECTC, OUTPUT);
	pinMode(PIN_LAYERENABLE, OUTPUT);
    pinMode(PIN_SINKOUTPUT, OUTPUT);
    pinMode(PIN_SINKLATCH, OUTPUT);

	digitalWrite(PIN_LAYERSELECTA, LOW);
	digitalWrite(PIN_LAYERSELECTB, LOW);
	digitalWrite(PIN_LAYERSELECTC, LOW);
	digitalWrite(PIN_LAYERENABLE, HIGH);
	digitalWrite(PIN_SINKOUTPUT, LOW);

    SPI.begin();
    Serial.begin(9600);

  randomSeed(analogRead(5));
  Timer1.initialize(1500);
  Timer1.attachInterrupt(isr_output);
  
}

void loop() {
  //anim_ScrollText("ABAB\0");
  runCube(); 
}
