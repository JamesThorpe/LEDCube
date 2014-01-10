#ifdef VSBUILD
#include <Windows.h>
#endif


#include "animations.h"
#include "font.h"

void anim_Flash() {
  for (int x =0;x<50;x++) {
    cube->SetAll(false);
    delay(20);
    cube->SetAll(true);
    delay(20);
  } 
}

void anim_ScrollText(char* Text) {
  char* c = Text;
  //Serial.println(Text);
  while (*c != 0) {
    //Serial.println(c);
    for (char col = 0; col < FONT_WIDTH; col++) {
      //Serial.println((int)GetByteForCharacterColumn(*c, col));
      cube->ScrollOuterColumns(GetByteForCharacterColumn(*c, col));
      delay(60);
    }
    cube->ScrollOuterColumns(0);
    delay(60);
    c++; 
  }
  for (int x =0; x < 28;x++){
    cube->ScrollOuterColumns(0);
    delay(60);
  }
}

void anim_ScrollPlanes() {
	cube->SetAll(false);
	unsigned char count = 0;
	do {
		cube->SetPlaneXY(count, true);
		delay(50);
		cube->ClearAll();
	} while (++count < 8);
	
	count = 0;
	do {
		cube->SetPlaneXZ(count, true);
		delay(50);
		cube->ClearAll();
	} while(++count < 8);
	count = 0;
	do {
		cube->SetPlaneYZ(count, true);
		delay(50);
		cube->ClearAll();
	} while(++count < 8);
	count = 0;
	do {
		cube->SetPlaneXY(count, true);
		cube->SetPlaneXZ(count, true);
		cube->SetPlaneYZ(count, true);
		delay(50);
		cube->ClearAll();
	} while(++count < 8);
}
void anim_RandomLineScroll() {
  char layer = 4;
  char dir = 1;
  cube->SetAll(false);
  for (int count = 0; count < 400; count++)
  {
    if (random(6) < 4) {
      layer += dir;
    }
    if (layer < 0) layer = 0;
    if (layer > 7) layer = 7;
    if (random(20) < 3) {
      dir = 0 - dir; 
    }
    cube->ScrollOuterColumns(1<<layer);
    delay(30);
  }
}
void anim_CornerToCorner(bool xPos, bool yPos, bool zPos, bool clear, bool on) {
  if (clear)
	cube->SetAll(!on);

	for (int count = 0; count < 22; count++) {
		char x, y, z;
		
		x = xPos ? 0 : 7;
		do {
			y = yPos ? 0 : 7;
			do {
				z = zPos ? 0 : 7;
				do {
                                        char xc, yc, zc;
                                        xc = xPos ? x : 7-x;
                                        yc = yPos ? y : 7-y;
                                        zc = zPos ? z : 7-z;
					if (xc + yc + zc == count)
						cube->SetLed(x,y,z,on);

					if (zPos)
						z++;
					else
						z--;
				} while ((zPos && z < 8) || (!zPos && z >= 0));

				if (yPos)
					y++;
				else
					y--;

			} while ((yPos && y < 8) || (!yPos && y >= 0));


			if (xPos)
				x++;
			else
				x--;
		} while ((xPos && x < 8) || (!xPos && x >= 0));
		delay(50);
                if (clear)
		  cube->SetAll(!on);
	}
}

void anim_CubeMove() {
  for (char x =0; x < 8; x++) {
    cube->DrawCube(0,0,0,x+1, true);
    delay(80); 
  }
  delay(500);
  for (char x = -8; x < 0;x++) {
    cube->DrawCube(7,7,7,x, true); 
    delay(80);
  }
}


void anim_PlaneFlipWithPause(bool pos, char plane)
{
	bool *stopped = new bool[8*8];
	memset(stopped, 0, sizeof(*stopped) * 64);

	char x, y, z;

	switch (plane) {
	case PLANE_X:
		cube->SetPlaneYZ(pos?0:7, true);
		break;
	case PLANE_Y:
		cube->SetPlaneXZ(pos?0:7, true);
		break;
	case PLANE_Z:
		cube->SetPlaneXY(pos?0:7, true);
		break;
	}

	do {
		for (char a = 0; a < 8; a++) {
			for (char b = 0; b < 8; b++) {
				switch (plane) {

				}
			}
		}
	} while(
		(plane == PLANE_X && ((pos && x < 8) || (!pos && x >= 0))) ||
		(plane == PLANE_Y && ((pos && y < 8) || (!pos && y >= 0))) ||
		(plane == PLANE_Z && ((pos && z < 8) || (!pos && z >= 0))));
	


	delete[] stopped;
}