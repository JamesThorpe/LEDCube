#include "core.h"

void runCube() {
	
	/*anim_OffToOffText();
	return;*/

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
