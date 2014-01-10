#include "animations.h"

void anim_OffToOffText() {
	//anim_ScrollText("Hello World!\0", ANIMMED);
}

//go from off to a corner
void anim_OffToCornerSimple() {
	CubeCorners corner = (CubeCorners)random(8);
	char x, y, z;
	switch(corner) {
	case Corner_xyz:
		x=y=z=0;
		break;
	case Corner_pxyz:
		x=7;y=z=0;
		break;
	case Corner_xpyz:
		x=z=0;y=7;
		break;
	case Corner_xypz:
		x=y=0;z=7;
		break;
	case Corner_pxpyz:
		x=y=7;z=0;
		break;
	case Corner_pxypz:
		x=z=7;y=0;
		break;
	case Corner_xpypz:
		x=0;y=z=7;
		break;
	case Corner_pxpypz:
		x=y=z=7;
		break;
	}
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