#include "core.h"

bool isStarted = false;
void runCube() {
	//if (!isStarted) {
	//	isStarted = true;
	//	for (char x = 2; x < 6; x++) {
	//		for (char y = 2; y < 6; y++) {
	//			cube->SetLed(x, y, 0, true);
	//		}
	//	}
	//	cube->ActivePlane = Plane_z;
	//}
	//anim_PlaneToPlaneSlide();
	//return;

	anim_OffToOffText();
	return;

	AnimationFunction func;
	switch(cube->State) {
	case State_corner:
		func = animFuncsCorner[random(NUMCORNERFUNCS)];
		break;
	case State_off:
		func = animFuncsOff[random(NUMOFFFUNCS)];
		break;
	case State_on:
		func = animFuncsOn[random(NUMONFUNCS)];
		break;
	case State_plane:
		func = animFuncsPlane[random(NUMPLANEFUNCS)];
		break;
	default:
		int x = 0;
	}

	func();
}
