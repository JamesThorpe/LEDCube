#include "animations.h"
void anim_PlaneToCornerDiagonalEmpty() {
	CubeCorners corners[4];
	getCornersForPlane(cube->ActivePlane, corners);
	CubeCorners start = corners[random(4)];
	cube->ActiveCorner = getOppositeCornerPlane(start, cube->ActivePlane);

	anim_generalEnumerateAxis(start, cube->ActiveCorner, false, false);
	cube->State = State_corner;
}

void anim_PlaneToPlaneSimple() {
	anim_PlaneMove(cube->ActivePlane, true, true, false);
	cube->ActivePlane = getOppositePlane(cube->ActivePlane);
}
void anim_PlaneToOnSimple() {
	anim_PlaneMove(cube->ActivePlane, true, false, false);
	cube->State = State_on;
}