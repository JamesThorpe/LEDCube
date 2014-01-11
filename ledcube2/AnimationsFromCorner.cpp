#include "animations.h"

void anim_CornerToPlaneDiagonalFill() {
	CubeCorners target;
	switch(cube->ActiveCorner) {
	case Corner_xyz:

		switch(random(3)) {
		case 0:
			target = Corner_pxypz;
			cube->ActivePlane = Plane_y;
			break;
		case 1:
			target = Corner_xpypz;
			cube->ActivePlane = Plane_x;
			break;
		case 2:
			target = Corner_pxpyz;
			cube->ActivePlane = Plane_z;
			break;
		}
		break;
	case Corner_pxyz:
		switch(random(3)) {
		case 0:
			target = Corner_xypz;
			cube->ActivePlane = Plane_y;
			break;
		case 1:
			target = Corner_pxpypz;
			cube->ActivePlane = Plane_px;
			break;
		case 2:
			target = Corner_xypz;
			cube->ActivePlane = Plane_z;
			break;
		}
		break;
	case Corner_xpyz:
		switch(random(3)) {
		case 0:
			target = Corner_pxyz;
			cube->ActivePlane = Plane_z;
			break;
		case 1:
			target = Corner_xypz;
			cube->ActivePlane = Plane_x;
			break;
		case 2:
			target = Corner_pxpypz;
			cube->ActivePlane = Plane_py;
			break;
		}
		break;
	case Corner_xypz:
		switch(random(3)) {
		case 0:
			target = Corner_pxpypz;
			cube->ActivePlane = Plane_pz;
			break;
		case 1:
			target = Corner_xpyz;
			cube->ActivePlane = Plane_x;
			break;
		case 2:
			target = Corner_pxyz;
			cube->ActivePlane = Plane_y;
			break;
		}
		break;
	case Corner_pxpyz:
		switch(random(3)) {
		case 0:
			target = Corner_xpypz;
			cube->ActivePlane = Plane_py;
			break;
		case 1:
			target = Corner_xyz;
			cube->ActivePlane = Plane_z;
			break;
		case 2:
			target = Corner_pxypz;
			cube->ActivePlane = Plane_px;
			break;
		}
		break;
	case Corner_pxypz:
		switch(random(3)) {
		case 0:
			target = Corner_xpypz;
			cube->ActivePlane = Plane_pz;
			break;
		case 1:
			target = Corner_pxpyz;
			cube->ActivePlane = Plane_px;
			break;
		case 2:
			target = Corner_xyz;
			cube->ActivePlane = Plane_y;
			break;
		}
		break;
	case Corner_xpypz:
		switch(random(3)) {
		case 0:
			target = Corner_pxypz;
			cube->ActivePlane = Plane_pz;
			break;
		case 1:
			target = Corner_xyz;
			cube->ActivePlane = Plane_x;
			break;
		case 2:
			target = Corner_pxpyz;
			cube->ActivePlane = Plane_py;
			break;
		}
		break;
	case Corner_pxpypz:
		switch(random(3)) {
		case 0:
			target = Corner_xypz;
			cube->ActivePlane = Plane_pz;
			break;
		case 1:
			target = Corner_pxyz;
			cube->ActivePlane = Plane_px;
			break;
		case 2:
			target = Corner_xpyz;
			cube->ActivePlane = Plane_py;
			break;
		}
		break;
	}

	anim_generalEnumerateAxis(cube->ActiveCorner, target, true, false);
	
	cube->State = State_plane;


	delay(1000);
	cube->SetAll(false);
	cube->State = State_off;

}

void anim_CornerToCornerPixelSimple() {
	char x, y, z;
	char dx, dy, dz;
	dx=dy=dz=0;
	switch(cube->ActiveCorner) {
	case Corner_xyz:
		x=y=z=0;
		switch(random(3)) {
		case 0:
			dx = 1;
			cube->ActiveCorner = Corner_pxyz;
			break;
		case 1:
			dy = 1;
			cube->ActiveCorner = Corner_xpyz;
			break;
		case 2:
			dz = 1;
			cube->ActiveCorner = Corner_xypz;
			break;
		}
		break;
	case Corner_pxyz:
		x=7;y=z=0;
				switch(random(3)) {
		case 0:
			dx = -1;
			cube->ActiveCorner = Corner_xyz;
			break;
		case 1:
			dy = 1;
			cube->ActiveCorner = Corner_pxpyz;
			break;
		case 2:
			dz = 1;
			cube->ActiveCorner = Corner_pxypz;
			break;
		}
		break;
	case Corner_xpyz:
		x=z=0;y=7;
		switch(random(3)) {
		case 0:
			dx = 1;
			cube->ActiveCorner = Corner_pxpyz;
			break;
		case 1:
			dy = -1;
			cube->ActiveCorner = Corner_xyz;
			break;
		case 2:
			dz = 1;
			cube->ActiveCorner = Corner_xpypz;
			break;
		}
		break;
	case Corner_xypz:
		x=y=0;z=7;
		switch(random(3)) {
		case 0:
			dx = 1;
			cube->ActiveCorner = Corner_pxypz;
			break;
		case 1:
			dy = 1;
			cube->ActiveCorner = Corner_xpypz;
			break;
		case 2:
			dz = -1;
			cube->ActiveCorner = Corner_xyz;
			break;
		}
		break;
	case Corner_pxpyz:
		x=y=7;z=0;
		switch(random(3)) {
		case 0:
			dx = -1;
			cube->ActiveCorner = Corner_xpyz;
			break;
		case 1:
			dy = -1;
			cube->ActiveCorner = Corner_pxyz;
			break;
		case 2:
			dz = 1;
			cube->ActiveCorner = Corner_pxpypz;
			break;
		}
		break;
	case Corner_pxypz:
		x=z=7;y=0;
		switch(random(3)) {
		case 0:
			dx = -1;
			cube->ActiveCorner = Corner_xypz;
			break;
		case 1:
			dy = 1;
			cube->ActiveCorner = Corner_pxpypz;
			break;
		case 2:
			dz = -1;
			cube->ActiveCorner = Corner_pxyz;
			break;
		}
		break;
	case Corner_xpypz:
		x=0;y=z=7;
		switch(random(3)) {
		case 0:
			dx = 1;
			cube->ActiveCorner = Corner_pxpypz;
			break;
		case 1:
			dy = -1;
			cube->ActiveCorner = Corner_xypz;
			break;
		case 2:
			dz = -1;
			cube->ActiveCorner = Corner_xpyz;
			break;
		}
		break;
	case Corner_pxpypz:
		x=y=z=7;
		switch(random(3)) {
		case 0:
			dx = -1;
			cube->ActiveCorner = Corner_xpypz;
			break;
		case 1:
			dy = -1;
			cube->ActiveCorner = Corner_pxypz;
			break;
		case 2:
			dz = -1;
			cube->ActiveCorner = Corner_pxpyz;
			break;
		}
		break;
	}

	for (char c = 0; c < 7; c++) {
		cube->SetLed(x,y,z,false);
		x+=dx;
		y+=dy;
		z+=dz;
		cube->SetLed(x,y,z,true);
		delay(ANIMFAST);
	}
}
void anim_CornerToOnDiagonal() {
	CubeCorners target = getOppositeCornerCube(cube->ActiveCorner);
	anim_generalEnumerateAxis(cube->ActiveCorner, target, true, false);
	cube->ActiveCorner = target;
	cube->State = State_on;
}
void anim_CornerToCornerDiagonalSimple() {
	CubeCorners target = getOppositeCornerCube(cube->ActiveCorner);
	anim_generalEnumerateAxis(cube->ActiveCorner, target, true, true);
	cube->ActiveCorner = target;
}

void anim_CornerToOffSimple() {

	char x, y, z;
	anim_SetCoordFromCorner(&x, &y, &z, cube->ActiveCorner);
	
	bool on = true;
	for (char c = 0; c <= 100; c+=5) {
		on = !on;
		cube->SetLed(x,y,z,on);
		delay(c);
	}
	cube->SetLed(x,y,z,false);
	delay(ANIMPAUSE);

	cube->State = State_off;
}
