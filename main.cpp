#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

#include "ledcube2/Cube.h"
#include "ledcube2/core.h"

Cube *cube;

void init();
void printcube();
void clear_screen();

void main() {
	init();	
	
	while(true)
		runCube();
}

DWORD WINAPI renderThread(LPVOID lpParam) {
	system("cls");
	while(true) {
		printcube();
		Sleep(33);
	}
}

void init() {
	cube = new Cube();

	DWORD threadId;
	CreateThread(NULL, 0, renderThread, NULL, 0, &threadId	);
}

void clear_screen ( )
{
  COORD coord = {0};               /* Top left screen position */

  /* Get a handle to the console */
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

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

	clear_screen();
	cout << s->c_str();
	delete s;


}