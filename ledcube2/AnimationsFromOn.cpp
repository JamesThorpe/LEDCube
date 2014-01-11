#include "animations.h"

void anim_OnToCornerDiagonal() {
	CubeCorners c = (CubeCorners)random(8);
	CubeCorners target = getOppositeCornerCube(c);
	anim_generalEnumerateAxis(c, target, false, false);
	cube->ActiveCorner = target;
	cube->State = State_corner;
}