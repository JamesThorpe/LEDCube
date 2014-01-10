#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

#include "ledcube2/Cube.h"
#include "ledcube2/animations.h"
#include "ledcube2/core.h"

#define PIN_SINKLATCH	9
#define PIN_SINKDATA	11 //SPI
#define PIN_SINKOUTPUT	8
#define PIN_SINKCLOCK	13 //SPI

#define PIN_LAYERSELECTA 5
#define PIN_LAYERSELECTB 6
#define PIN_LAYERSELECTC 7
#define PIN_LAYERENABLE 4

Cube *cube;
void init();
void printcube();
void clear_screen(bool);

void main() {
	init();	
	while(true)
	runCube();
}

DWORD WINAPI renderThread(LPVOID lpParam) {
	system("cls");
	//bool first = true;
	while(true) {
		printcube();
		Sleep(33);
		/*if (first) {
			clear_screen(true);
			first = false;
		}*/
	}
}

void init() {
	cube = new Cube();
	DWORD threadId;
	CreateThread(NULL, 0, renderThread, NULL, 0, &threadId	);
}

void clear_screen ( bool all )
{
  DWORD n;                         /* Number of characters written */
  DWORD size;                      /* number of visible characters */
  COORD coord = {0};               /* Top left screen position */
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  /* Get a handle to the console */
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

  GetConsoleScreenBufferInfo ( h, &csbi );

  if (all) {
  /* Find the number of characters to overwrite */
  size = csbi.dwSize.X * csbi.dwSize.Y;

  /* Overwrite the screen buffer with whitespace */
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );
  }

  /* Reset the cursor to the top left position */
  SetConsoleCursorPosition ( h, coord );
}

void printcube() {
	string *s = new string();
	s->append("Bottom   ");
	for (int x = 0; x < 54;x++)
		s->append(" ");
	s->append("Top\n");
	unsigned char* layer[8];
	for (int x = 0; x < 8; x++) {
		layer[x] = cube->GetLayer(x);
	}

	unsigned char mask = 0x80;
	for (int y = 7; y >= 0; y--) {
		for (int l = 0; l < 8; l++) {
			for (char x = 0; x < 8; x++) {
			    if (layer[l][x] & mask) {
					s->append("O");
				}
				else {
					s->append(".");
				}
			}
			s->append(" ");
		}
		mask >>= 1;
		s->append("\n");
	}
	s->append("\nFront    ");
	for (int x = 0; x < 54;x++)
		s->append(" ");
	s->append("Back\n");
	
	for (int z = 7; z >= 0; z--) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				s->append(cube->GetLed(x,y,z) ? "O" : ".");
			}
			s->append(" ");
		}
		s->append("\n");
	}

	s->append("\nLeft     ");
	for (int x = 0; x < 54;x++)
		s->append(" ");
	s->append("Right\n");

	for (int z = 7; z >= 0; z--) {
		for (int x = 0; x < 8 ; x++) {
			for (int y = 7; y >= 0; y--) {
				s->append(cube->GetLed(x,y,z) ? "O" : ".");
			}
			s->append(" ");
		}
		s->append("\n");
	}

	s->append("\nRight    Back     Left     Front\n");
	for (int z = 7; z >= 0; z--) {
		//right
		for (int y = 0; y < 8; y++)
			s->append(cube->GetLed(7,y,z)?"O":".");
		
		s->append(" ");
		//back
		for (int x = 7; x>=0; x--)
			s->append(cube->GetLed(x,7,z)?"O":".");

		s->append(" ");
		//left
		for (int y = 7; y>=0; y--)
			s->append(cube->GetLed(0,y,z)?"O":".");
		
		s->append(" ");
		//front
		for (int x = 0; x < 8; x++)
			s->append(cube->GetLed(x, 0, z)?"O":".");
		s->append("\n");
	}

	clear_screen(false);
	cout << s->c_str();
	delete s;


}