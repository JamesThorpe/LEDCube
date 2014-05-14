#ifdef VSBUILD
#include <Windows.h>
#endif


#include "animations.h"
#include "font.h"

void anim_nullAnimation() {
}

void anim_ScrollText(char* Text, unsigned char speed) {
  char* c = Text;
  //Serial.println(Text);
  while (*c != 0) {
    //Serial.println(c);
    for (char col = 0; col < FONT_WIDTH; col++) {
      //Serial.println((int)GetByteForCharacterColumn(*c, col));
      cube->ScrollOuterColumns(GetByteForCharacterColumn(*c, col));
      delay(speed);
    }
	cube->ScrollOuterColumns(0);
    delay(speed);
    c++; 
  }
  for (int x =0; x < 28;x++){
    cube->ScrollOuterColumns(0);
    delay(speed);
  }
}

void anim_SetCoordFromCorner(char *x, char *y, char *z, CubeCorners corner) {
	switch(corner) {
	case Corner_xyz:
		*x=*y=*z=0;
		break;
	case Corner_pxyz:
		*x=7;*y=*z=0;
		break;
	case Corner_xpyz:
		*x=*z=0;*y=7;
		break;
	case Corner_pxpyz:
		*x=*y=7;*z=0;
		break;
	case Corner_xypz:
		*x=*y=0;*z=7;
		break;
	case Corner_pxypz:
		*x=*z=7;*y=0;
		break;
	case Corner_xpypz:
		*x=0;*y=*z=7;
		break;
	case Corner_pxpypz:
		*x=*y=*z=7;
		break;
	}
}

void anim_generalEnumerateAxis(CubeCorners startCorner, CubeCorners endCorner, bool on, bool clear) {
	char x1,y1,z1,x2,y2,z2;
	anim_SetCoordFromCorner(&x1, &y1, &z1, startCorner);
	anim_SetCoordFromCorner(&x2, &y2, &z2, endCorner);
	char dx, dy, dz;
	dx=dy=dz=0;

	if (x1 > x2) dx = -1;
	else if (x2 > x1) dx = 1;
	if (y1 > y2) dy = -1;
	else if (y2 > y1) dy = 1;
	if (z1 > z2) dz = -1;
	else if (z2 > z1) dz = 1;

	char cx, cy, cz;

	//count needs to be from 0-15 (x,y,z) or 8-22 (px,py,pz) if on a single plane...
	char startCount = 0;
	char endCount = 22;

	Planes p = getPlaneFromOppositeCorners(startCorner, endCorner);
	if (p != Plane_undefined) {
		switch(p) {
		case Plane_x:
		case Plane_y:
		case Plane_z:
			endCount = 15;
			break;
		default:
			startCount = 7;
		}
	}

	for (int count = startCount; count < endCount; count++) {
		if (clear)
			cube->SetAll(!on);

		cx = x1;
		do {
			cy = y1;
			do {
				cz = z1;
				do {
					char xx, yy, zz;
					xx = dx == -1 ? 7-cx : cx;
					yy = dy == -1 ? 7-cy : cy;
					zz = dz == -1 ? 7-cz : cz;
					if (xx+yy+zz == count)
						cube->SetLed(cx,cy,cz, on);

					cz += dz;
				}while(dz != 0 && abs(z1-cz) != 8);
				cy += dy;
			}while(dy != 0 && abs(y1-cy) != 8);
			cx += dx;
		} while(dx != 0 && abs(x1-cx) != 8);
		delay(ANIMFAST);
	}
}

Planes getPlaneFromOppositeCorners(CubeCorners a, CubeCorners b) {
	Planes planesA[3];
	Planes planesB[3];

	getPlanesForCorner(a, planesA);
	getPlanesForCorner(b, planesB);

	for (char x = 0; x < 3; x++) {
		for (char y= 0; y < 3; y++) {
			if (planesA[x] == planesB[y])
				return planesA[x];
		}
	}
	return Plane_undefined;
}
void getCornersForPlane(Planes plane, CubeCorners *corners)
{
	switch(plane) {
	case Plane_x:
		corners[0] = Corner_xyz;
		corners[1] = Corner_xpyz;
		corners[2] = Corner_xypz;
		corners[3] = Corner_xpypz;
		break;
	case Plane_y:
		corners[0] = Corner_xyz;
		corners[1] = Corner_pxyz;
		corners[2] = Corner_xypz;
		corners[3] = Corner_pxypz;
		break;
	case Plane_z:
		corners[0] = Corner_xyz;
		corners[1] = Corner_pxyz;
		corners[2] = Corner_xpyz;
		corners[3] = Corner_pxpyz;
		break;
	case Plane_px:
		corners[0] = Corner_pxyz;
		corners[1] = Corner_pxpyz;
		corners[2] = Corner_pxypz;
		corners[3] = Corner_pxpypz;
		break;
	case Plane_py:
		corners[0] = Corner_xpyz;
		corners[1] = Corner_pxpyz;
		corners[2] = Corner_xpypz;
		corners[3] = Corner_pxpypz;
		break;
	case Plane_pz:
		corners[0] = Corner_xypz;
		corners[1] = Corner_pxypz;
		corners[2] = Corner_xpypz;
		corners[3] = Corner_pxpypz;
		break;
	}
}
void getPlanesForCorner(CubeCorners corner, Planes* planes) {
switch(corner) {
	case Corner_xyz:
		planes[0] = Plane_x;
		planes[1] = Plane_y;
		planes[2] = Plane_z;
		break;
	case Corner_pxyz:
		planes[0] = Plane_px;
		planes[1] = Plane_y;
		planes[2] = Plane_z;
		break;
	case Corner_xpyz:
		planes[0] = Plane_x;
		planes[1] = Plane_py;
		planes[2] = Plane_z;
		break;
	case Corner_xypz:
		planes[0] = Plane_x;
		planes[1] = Plane_y;
		planes[2] = Plane_pz;
		break;
	case Corner_pxpyz:
		planes[0] = Plane_px;
		planes[1] = Plane_py;
		planes[2] = Plane_z;
		break;
	case Corner_pxypz:
		planes[0] = Plane_px;
		planes[1] = Plane_y;
		planes[2] = Plane_pz;
		break;
	case Corner_xpypz:
		planes[0] = Plane_x;
		planes[1] = Plane_py;
		planes[2] = Plane_pz;
		break;
	case Corner_pxpypz:
		planes[0] = Plane_px;
		planes[1] = Plane_py;
		planes[2] = Plane_pz;
		break;
	}
}

CubeCorners getOppositeCornerCube(CubeCorners corner) {
	CubeCorners ret;
	switch(corner) {
	case Corner_xyz:
		ret =  Corner_pxpypz;
		break;
	case Corner_pxyz:
		ret =  Corner_xpypz;
		break;
	case Corner_xpyz:
		ret =  Corner_pxypz;
		break;
	case Corner_xypz:
		ret =  Corner_pxpyz;
		break;
	case Corner_pxpyz:
		ret =  Corner_xypz;
		break;
	case Corner_pxypz:
		ret =  Corner_xpyz;
		break;
	case Corner_xpypz:
		ret =  Corner_pxyz;
		break;
	case Corner_pxpypz:
		ret =  Corner_xyz;
		break;
	}
	return ret;
}


CubeCorners getOppositeCornerPlane(CubeCorners corner, Planes plane) {
	CubeCorners ret;
	switch(corner) {
	case Corner_xyz:
		switch(plane) {
		case Plane_x:
			ret = Corner_xpypz;
			break;
		case Plane_y:
			ret = Corner_pxypz;
			break;
		case Plane_z:
			ret = Corner_pxpyz;
			break;
		}
		break;
	case Corner_pxyz:
		switch(plane) {
		case Plane_px:
			ret = Corner_pxpypz;
			break;
		case Plane_y:
			ret = Corner_xypz;
			break;
		case Plane_z:
			ret = Corner_xpyz;
			break;
		}
		break;
	case Corner_xpyz:
		switch(plane) {
		case Plane_x:
			ret = Corner_xypz;
			break;
		case Plane_py:
			ret = Corner_pxpypz;
			break;
		case Plane_z:
			ret = Corner_pxyz;
			break;
		}
		break;
	case Corner_xypz:
		switch(plane) {
		case Plane_x:
			ret = Corner_xpyz;
			break;
		case Plane_y:
			ret = Corner_pxyz;
			break;
		case Plane_pz:
			ret = Corner_pxpypz;
			break;
		}
		break;
	case Corner_pxpyz:
		switch(plane) {
		case Plane_px:
			ret = Corner_pxypz;
			break;
		case Plane_py:
			ret = Corner_xpypz;
			break;
		case Plane_z:
			ret = Corner_xyz;
			break;
		}
		break;
	case Corner_pxypz:
		switch(plane) {
		case Plane_px:
			ret = Corner_pxpyz;
			break;
		case Plane_y:
			ret = Corner_xyz;
			break;
		case Plane_pz:
			ret = Corner_xpypz;
			break;
		}
		break;
	case Corner_xpypz:
		switch(plane) {
		case Plane_x:
			ret = Corner_xyz;
			break;
		case Plane_py:
			ret = Corner_pxpyz;
			break;
		case Plane_pz:
			ret = Corner_pxypz;
			break;
		}
		break;
	case Corner_pxpypz:
		switch(plane) {
		case Plane_px:
			ret = Corner_pxyz;
			break;
		case Plane_py:
			ret = Corner_xpyz;
			break;
		case Plane_pz:
			ret = Corner_xypz;
			break;
		}
		break;
	}
	return ret;
}

void anim_PlaneMove(Planes startPlane, bool on, bool clear, bool stopShort) {
	char index = 0, delta = 1, stop = 7;

	switch(startPlane) {
	case Plane_px:
	case Plane_py:
	case Plane_pz:
		index = 7;
		delta = -1;
		stop = 0;
	}
	delay(ANIMFAST);
	bool last = false;
	bool onemore = false;
	do {

		if (clear)
			cube->SetAll(!on);
		switch(startPlane) {
		case Plane_x:
		case Plane_px:
			cube->SetPlaneYZ(index, on);
			break;
		case Plane_y:
		case Plane_py:
			cube->SetPlaneXZ(index, on);
			break;
		case Plane_z:
		case Plane_pz:
			cube->SetPlaneXY(index, on);
			break;
		}
		delay(ANIMFAST);
		index += delta;
		if (onemore) last = true;
		if (index == stop) { 
			onemore = true;
			if (stopShort) last = true;
		}
		
	} while(!last);

}

Planes getOppositePlane(Planes plane) {
	switch(plane) {
	case Plane_x:
		return Plane_px;
	case Plane_y:
		return Plane_py;
	case Plane_z:
		return Plane_pz;
	case Plane_px:
		return Plane_x;
	case Plane_py:
		return Plane_y;
	default:
		return Plane_z;
	}
}

unsigned char reverse(unsigned char b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}


/*  Currently Unused  */
void anim_ScrollPlanes() {
	cube->SetAll(false);
	unsigned char count = 0;
	do {
		cube->SetPlaneXY(count, true);
		delay(50);
		cube->ClearAll();
	} while (++count < 8);

	count = 0;
	do {
		cube->SetPlaneXZ(count, true);
		delay(50);
		cube->ClearAll();
	} while (++count < 8);
	count = 0;
	do {
		cube->SetPlaneYZ(count, true);
		delay(50);
		cube->ClearAll();
	} while (++count < 8);
	count = 0;
	do {
		cube->SetPlaneXY(count, true);
		cube->SetPlaneXZ(count, true);
		cube->SetPlaneYZ(count, true);
		delay(50);
		cube->ClearAll();
	} while (++count < 8);
}

void anim_RandomLineScroll() {
	char layer = 4;
	char dir = 1;
	cube->SetAll(false);
	for (int count = 0; count < 400; count++)
	{
		if (random(6) < 4) {
			layer += dir;
		}
		if (layer < 0) layer = 0;
		if (layer > 7) layer = 7;
		if (random(20) < 3) {
			dir = 0 - dir;
		}
		cube->ScrollOuterColumns(1 << layer);
		delay(30);
	}
}

void anim_Flash() {
	for (int x = 0; x<50; x++) {
		cube->SetAll(false);
		delay(20);
		cube->SetAll(true);
		delay(20);
	}
}

void anim_CubeMove() {
	for (char x = 0; x < 8; x++) {
		cube->DrawCube(0, 0, 0, x + 1, true);
		delay(80);
	}
	delay(500);
	for (char x = -8; x < 0; x++) {
		cube->DrawCube(7, 7, 7, x, true);
		delay(80);
	}
}
