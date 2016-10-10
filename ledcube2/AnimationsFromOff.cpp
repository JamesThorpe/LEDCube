#include "animations.h"

void anim_OffToOffText() {
	anim_ScrollText("Hello World!", ANIMMED);
}

//go from off to a corner
void anim_OffToCornerSimple() {
	CubeCorners corner = (CubeCorners)random(8);
	
	char x, y, z;
	anim_SetCoordFromCorner(&x, &y, &z, corner);

	bool on = false;
	for (char c = 100; c >= 0; c-=5) {
		on = !on;
		cube->SetLed(x,y,z,on);
		delay(c);
	}
	cube->SetLed(x,y,z,true);
	delay(ANIMPAUSE);

	cube->ActiveCorner = corner;
	cube->State = State_corner;
}

void OffToOnFlashPlanes() {
	for (char x = 0; x < 8; x++) {
		for (char c = 0; c < 4; c++) {
			for (char z = x; z < 8; z++) {
				cube->SetPlaneXY(z, true);
				delay(ANIMREALLYFAST/2);
				cube->SetPlaneXY(z, false);
			}
		}

		cube->SetPlaneXY(x, true);
	}
	cube->State = State_on;
}