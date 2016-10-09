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
void anim_PlaneToPlaneSlide() {
	bool plane = random(2) == 0;
	bool clockwise = random(2) == 0;
	Planes planeToRotate;
	switch(cube->ActivePlane) {
	case Plane_x:
		if (plane) {
			planeToRotate = Plane_y;
			if (clockwise) {
				cube->ActivePlane = Plane_pz;
			} else {
				cube->ActivePlane = Plane_z;
			}
		} else {
			planeToRotate = Plane_z;
			if (clockwise) {
				cube->ActivePlane = Plane_y;
			} else {
				cube->ActivePlane = Plane_py;
			}
		}
		break;
	case Plane_px:
		if (plane) {
			planeToRotate = Plane_y;
			if (clockwise) {
				cube->ActivePlane = Plane_z;
			} else {
				cube->ActivePlane = Plane_pz;
			}
		} else {
			planeToRotate = Plane_z;
			if (clockwise) {
				cube->ActivePlane = Plane_py;
			} else {
				cube->ActivePlane = Plane_y;
			}
		}
		break;
	case Plane_y:
		if (plane) {
			planeToRotate = Plane_x;
			if (clockwise) {
				cube->ActivePlane = Plane_z;
			} else {
				cube->ActivePlane = Plane_pz;
			}
		} else {
			planeToRotate = Plane_z;
			if (clockwise) {
				cube->ActivePlane = Plane_px;
			} else {
				cube->ActivePlane = Plane_x;
			}
		}
		break;
	case Plane_py:
		if (plane) {
			planeToRotate = Plane_x;
			if (clockwise) {
				cube->ActivePlane = Plane_pz;
			} else {
				cube->ActivePlane = Plane_z;
			}
		} else {
			planeToRotate = Plane_z;
			if (clockwise) {
				cube->ActivePlane = Plane_x;
			} else {
				cube->ActivePlane = Plane_px;
			}
		}
		break;
	case Plane_z:
		if (plane) {
			planeToRotate = Plane_x;
			if (clockwise) {
				cube->ActivePlane = Plane_py;
			} else {
				cube->ActivePlane = Plane_y;
			}
		} else {
			planeToRotate = Plane_y;
			if (clockwise) {
				cube->ActivePlane = Plane_x;
			} else {
				cube->ActivePlane = Plane_px;
			}
		}
		break;
	case Plane_pz:
		if (plane) {
			planeToRotate = Plane_x;
			if (clockwise) {
				cube->ActivePlane = Plane_y;
			} else {
				cube->ActivePlane = Plane_py;
			}
		} else {
			planeToRotate = Plane_y;
			if (clockwise) {
				cube->ActivePlane = Plane_px;
			} else {
				cube->ActivePlane = Plane_x;
			}
		}
		break;
	}
	for (char x = 0; x < 7; x++) {
		cube->RotateOuterLayers(planeToRotate, clockwise, Plane_x, 0);
		delay(ANIMFAST);
	}
}