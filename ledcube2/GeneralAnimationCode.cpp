#ifdef VSBUILD
#include <Windows.h>
#endif


#include "animations.h"
#include "font.h"

void anim_nullAnimation() {
}

void anim_Flash() {
  for (int x =0;x<50;x++) {
    cube->SetAll(false);
    delay(20);
    cube->SetAll(true);
    delay(20);
  } 
}

void anim_ScrollText(char* Text, char speed) {
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
	} while(++count < 8);
	count = 0;
	do {
		cube->SetPlaneYZ(count, true);
		delay(50);
		cube->ClearAll();
	} while(++count < 8);
	count = 0;
	do {
		cube->SetPlaneXY(count, true);
		cube->SetPlaneXZ(count, true);
		cube->SetPlaneYZ(count, true);
		delay(50);
		cube->ClearAll();
	} while(++count < 8);
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
    cube->ScrollOuterColumns(1<<layer);
    delay(30);
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
	for (int count = 0; count < 22; count++) {
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


CubeCorners getOppositeCornerCube(CubeCorners corner) {
	switch(corner) {
	case Corner_xyz:
		return Corner_pxpypz;
		break;
	case Corner_pxyz:
		return Corner_xpypz;
		break;
	case Corner_xpyz:
		return Corner_pxypz;
		break;
	case Corner_xypz:
		return Corner_pxpyz;
		break;
	case Corner_pxpyz:
		return Corner_xypz;
		break;
	case Corner_pxypz:
		return Corner_xpyz;
		break;
	case Corner_xpypz:
		return Corner_pxyz;
		break;
	case Corner_pxpypz:
		return Corner_xyz;
		break;
	}
}
/*CubeCorners getOppositeCornerPlane(CubeCorners corner, Planes plane) {
	switch(corner) {
	case Corner_xyz:
		switch(plane) {
		case Plane_x:
			return Corner_xpypz;
		case Plane_y:
			return Corner_pxypz;
		case Plane_z:
			return Corner_pxpyz;
		}
	case Corner_pxyz:
		return Corner_xpypz;
		break;
	case Corner_xpyz:
		return Corner_pxypz;
		break;
	case Corner_xypz:
		return Corner_pxpyz;
		break;
	case Corner_pxpyz:
		return Corner_xypz;
		break;
	case Corner_pxypz:
		return Corner_xpyz;
		break;
	case Corner_xpypz:
		return Corner_pxyz;
		break;
	case Corner_pxpypz:
		return Corner_xyz;
		break;
	}
}*/

void anim_CubeMove() {
  for (char x =0; x < 8; x++) {
    cube->DrawCube(0,0,0,x+1, true);
    delay(80); 
  }
  delay(500);
  for (char x = -8; x < 0;x++) {
    cube->DrawCube(7,7,7,x, true); 
    delay(80);
  }
}

