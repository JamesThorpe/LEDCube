#include "animations.h"
/*

	switch(cube->ActiveCorner) {
	case xyz:

		break;
	case pxyz:

		break;
	case xpyz:

		break;
	case pxpyz:

		break;
	case xypz:

		break;
	case pxypz:

		break;
	case xpypz:

		break;
	case pxpypz:

		break;
	}



	switch(cube->ActiveCorner) {
	case Corner_xyz:
		x=y=z=0;
		break;
	case Corner_pxyz:
		x=7;y=z=0;
		break;
	case Corner_xpyz:
		x=z=0;y=7;
		break;
	case Corner_pxpyz:
		x=y=7;z=0;
		break;
	case Corner_xypz:
		x=y=0;z=7;
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


	*/

void anim_CornerToPlaneDiagonalFill() {
	char x, y, z;
	char dx, dy, dz;
	dx=dy=dz=0;
	switch(cube->ActiveCorner) {
	case Corner_xyz:
		x=y=z=0;
		switch(random(3)) {
		case 0:
			dx = 1;
			dz = 1;
			cube->ActivePlane = Plane_y;
			break;
		case 1:
			dy = 1;
			dz = 1;
			cube->ActivePlane = Plane_x;
			break;
		case 2:
			dx = 1;
			dy = 1;
			cube->ActivePlane = Plane_z;
			break;
		}
		break;
	case Corner_pxyz:
		x=7;y=z=0;
		switch(random(3)) {
		case 0:
			dx = -1;
			dz = 1;
			cube->ActivePlane = Plane_y;
			break;
		case 1:
			dy = 1;
			dz = 1;
			cube->ActivePlane = Plane_px;
			break;
		case 2:
			dz = 1;
			dx = -1;
			cube->ActivePlane = Plane_z;
			break;
		}
		break;
	case Corner_xpyz:
		x=z=0;y=7;
		switch(random(3)) {
		case 0:
			dx = 1;
			dy = -1;
			cube->ActivePlane = Plane_z;
			break;
		case 1:
			dy = -1;
			dz = 1;
			cube->ActivePlane = Plane_x;
			break;
		case 2:
			dz = 1;
			dx = 1;
			cube->ActivePlane = Plane_py;
			break;
		}
		break;
	case Corner_xypz:
		x=y=0;z=7;
		switch(random(3)) {
		case 0:
			dx = 1;
			dy = 1;
			cube->ActivePlane = Plane_pz;
			break;
		case 1:
			dy = 1;
			dz = -1;
			cube->ActivePlane = Plane_x;
			break;
		case 2:
			dz = -1;
			dx = 1;
			cube->ActivePlane = Plane_y;
			break;
		}
		break;
	case Corner_pxpyz:
		x=y=7;z=0;
		switch(random(3)) {
		case 0:
			dx = -1;
			dz = 1;
			cube->ActivePlane = Plane_py;
			break;
		case 1:
			dy = -1;
			dx = -1;
			cube->ActivePlane = Plane_z;
			break;
		case 2:
			dz = 1;
			dy = -1;
			cube->ActivePlane = Plane_px;
			break;
		}
		break;
	case Corner_pxypz:
		x=z=7;y=0;
		switch(random(3)) {
		case 0:
			dx = -1;
			dy = 1;
			cube->ActivePlane = Plane_pz;
			break;
		case 1:
			dy = 1;
			dz = -1;
			cube->ActivePlane = Plane_px;
			break;
		case 2:
			dz = -1;
			dx = -1;
			cube->ActivePlane = Plane_y;
			break;
		}
		break;
	case Corner_xpypz:
		x=0;y=z=7;
		switch(random(3)) {
		case 0:
			dx = 1;
			dy = -1;
			cube->ActivePlane = Plane_pz;
			break;
		case 1:
			dy = -1;
			dz = -1;
			cube->ActivePlane = Plane_x;
			break;
		case 2:
			dz = -1;
			dx = 1;
			cube->ActivePlane = Plane_py;
			break;
		}
		break;
	case Corner_pxpypz:
		x=y=z=7;
		switch(random(3)) {
		case 0:
			dx = -1;
			dy = -1;
			cube->ActivePlane = Plane_pz;
			break;
		case 1:
			dy = -1;
			dz = -1;
			cube->ActivePlane = Plane_px;
			break;
		case 2:
			dz = -1;
			dx = -1;
			cube->ActivePlane = Plane_py;
			break;
		}
		break;
	}

	char cx, cy, cz;
	for (char c = 0; c< 22;c++) {
		cx = x;
		do {
			cy = y;

			do {

				cz = z;
				do {


					char xx, yy, zz;
					xx = dx == -1 ? 7-cx : cx;
					yy = dy == -1 ? 7-cy : cy;
					zz = dz == -1 ? 7-cz : cz;
					if (xx+yy+zz == c)
						cube->SetLed(cx,cy,cz, true);
					cz += dz;
				} while(dz != 0 && abs(z-cz) != 8);
				cy+=dy;
			} while (dy != 0 && abs(y-cy) != 8);
			cx += dx;
		} while (dx != 0 && abs(x-cx) != 8);
		delay(ANIMFAST);
	}
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
	switch(cube->ActiveCorner) {
	case Corner_xyz:
		anim_CornerToCorner(true, true, true, false, true);
		break;
	case Corner_pxyz:
		anim_CornerToCorner(false, true, true, false, true);
		break;
	case Corner_xpyz:
		anim_CornerToCorner(true, false, true, false, true);
		break;
	case Corner_xypz:
		anim_CornerToCorner(true, true, false, false, true);
		break;
	case Corner_pxpyz:
		anim_CornerToCorner(false, false, true, false, true);
		break;
	case Corner_pxypz:
		anim_CornerToCorner(false, true, false, false, true);
		break;
	case Corner_xpypz:
		anim_CornerToCorner(true, false, false, false, true);
		break;
	case Corner_pxpypz:
		anim_CornerToCorner(false, false, false, false, true);
		break;
	}
	cube->State = State_on;
}
void anim_CornerToCornerDiagonalSimple() {

	switch(cube->ActiveCorner) {
	case Corner_xyz:
		anim_CornerToCorner(true, true, true, true, true);
		cube->ActiveCorner = Corner_pxpypz;
		break;
	case Corner_pxyz:
		anim_CornerToCorner(false, true, true, true, true);
		cube->ActiveCorner = Corner_xpypz;
		break;
	case Corner_xpyz:
		anim_CornerToCorner(true, false, true, true, true);
		cube->ActiveCorner = Corner_pxypz;
		break;
	case Corner_xypz:
		anim_CornerToCorner(true, true, false, true, true);
		cube->ActiveCorner = Corner_pxpyz;
		break;
	case Corner_pxpyz:
		anim_CornerToCorner(false, false, true, true, true);
		cube->ActiveCorner = Corner_xypz;
		break;
	case Corner_pxypz:
		anim_CornerToCorner(false, true, false, true, true);
		cube->ActiveCorner = Corner_xpyz;
		break;
	case Corner_xpypz:
		anim_CornerToCorner(true, false, false, true, true);
		cube->ActiveCorner = Corner_pxyz;
		break;
	case Corner_pxpypz:
		anim_CornerToCorner(false, false, false, true, true);
		cube->ActiveCorner = Corner_xyz;
		break;
	}
}

void anim_CornerToOffSimple() {

	char x, y, z;
	switch(cube->ActiveCorner) {
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
