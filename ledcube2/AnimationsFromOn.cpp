#include "animations.h"

void anim_OnToCornerDiagonal() {
	CubeCorners c = (CubeCorners)random(8);
	switch(c) {
	case Corner_xyz:
		anim_CornerToCorner(true, true, true, false, false);
		cube->ActiveCorner = Corner_pxpypz;
		break;
	case Corner_pxyz:
		anim_CornerToCorner(false, true, true, false, false);
		cube->ActiveCorner = Corner_xpypz;
		break;
	case Corner_xpyz:
		anim_CornerToCorner(true, false, true, false, false);
		cube->ActiveCorner = Corner_pxypz;
		break;
	case Corner_xypz:
		anim_CornerToCorner(true, true, false, false, false);
		cube->ActiveCorner = Corner_pxpyz;
		break;
	case Corner_pxpyz:
		anim_CornerToCorner(false, false, true, false, false);
		cube->ActiveCorner = Corner_xypz;
		break;
	case Corner_pxypz:
		anim_CornerToCorner(false, true, false, false, false);
		cube->ActiveCorner = Corner_xpyz;
		break;
	case Corner_xpypz:
		anim_CornerToCorner(true, false, false, false, false);
		cube->ActiveCorner = Corner_pxyz;
		break;
	case Corner_pxpypz:
		anim_CornerToCorner(false, false, false, false, false);
		cube->ActiveCorner = Corner_xyz;
		break;
	}
	cube->State = State_corner;
}