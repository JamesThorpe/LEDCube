#ifdef VSBUILD
#include <Windows.h>
#endif

#include "cube.h"
#include "animations.h"

Cube::Cube() {
	ClearAll();
	this->State = State_off;
}

void Cube::SetAll(bool on) {
  
  memset((void*)&data, on?255:0, sizeof(data));
  
}

void Cube::SetPlaneXY(char layer, bool on) {
	memset((void*)data[layer], on?255:0, sizeof(data[layer]));
}
void Cube::SetPlaneXZ(char layer, bool on) {
    
	char y = 0;
	do {
		char x = 0;
		do {
			if (on)
				data[y][x] |= 1 << layer;
			else
				data[y][x] &= ~(1 << layer);

		} while(++x < 8);
	} while(++y < 8);
  
}
void Cube::SetPlaneYZ(char layer, bool on) {
    
	char x = 0;
	do {
		memset((void*)&data[x][layer], on?255:0, sizeof(data[x][layer]));
	} while (++x < 8);
  
}
void Cube::ScrollOuterColumns(char src) {
    
	char layer = 0;
	char x;
	/*
	
	Imagine looking top down onto cube - we're shifting like this:
	   > B >
	........
 C  .      . A
 ^  .      . v
	........
       < D <
	

	Losing data from the bottom of A and introducing it at the right of D

	*/
	do {
		//remember bit at corner of A/D
		unsigned char obit = data[layer][7] & 1;
		

		//Shift A
		data[layer][7] >>= 1;
		//make sure A/D stays as it was
		if (obit & 1) {
			data[layer][7] |= 1;
		} else {
			data[layer][7] &= ~1;
		}

		//Loop through shifting B
		x = 7;
		unsigned char bit = 1 << 7;
		do {
			data[layer][x] &= ~bit;
			data[layer][x] |= data[layer][x-1] & bit;
		} while(x-- > 0);

		//Shift C
		data[layer][0] = data[layer][0]<<1;

		//Loop through shifting D
		x = 0;
		char b = 1;
		do {
			data[layer][x] &= ~b;
			data[layer][x] |= data[layer][x+1] & b;
		} while (x++ < 7);

		//finally grab new source
		bit = 1;
		data[layer][7] &= ~bit;
		data[layer][7] |= (src & (1 << layer)) == (1 << layer) ? 1 : 0;

	} while(++layer < 8);
  
}
void Cube::FillAll() {
	SetAll(true);
}
void Cube::ClearAll() {
	SetAll(false);
}

void Cube::SetLed(char x, char y, char z, bool on) {
	if (on)
		data[z][x] |= 1 << y;
	else
		data[z][x] &= ~(1 << y);
  
}

unsigned char* Cube::GetLayer(char layer)
{
	return data[layer];
}

void Cube::DrawLineX(char startX, char endX, char y, char z, bool on) {
  char sx = startX, ex = endX;
  if (startX > endX) {sx=endX; ex = startX;}
  for (char x = sx; x <= ex; x++)
    this->SetLed(x, y, z, on);
}
void Cube::DrawLineY(char startY, char endY, char x, char z, bool on) {
  char sy = startY, ey = endY;
  if (startY > endY) {sy = endY; ey = startY;}
  for (char y = sy; y <= ey; y++)
    this->SetLed(x,y,z,on);
}
void Cube::DrawLineZ(char startZ, char endZ, char x, char y, bool on) {
  char sz = startZ, ez = endZ;
  if (startZ > endZ) {sz = endZ; ez = startZ;}
  for (char z = sz; z <= ez; z++)
    this->SetLed(x,y,z,on);
}
void Cube::DrawCube(char x, char y, char z, char s, bool clr) {
  if (clr)
    this->SetAll(false);
  if (s < 0)
    s++;
  else
    s--;  
  this->DrawLineX(x,x+s,y,z, true);
  this->DrawLineX(x,x+s,y,z+s, true);
  this->DrawLineX(x,x+s,y+s,z, true);
  this->DrawLineX(x,x+s,y+s,z+s, true);
  this->DrawLineY(y,y+s,x,z, true);
  this->DrawLineY(y,y+s,x,z+s, true);
  this->DrawLineY(y,y+s,x+s,z, true);
  this->DrawLineY(y,y+s,x+s,z+s, true);
  this->DrawLineZ(z,z+s,x,y, true);
  this->DrawLineZ(z,z+s,x,y+s, true);
  this->DrawLineZ(z,z+s,x+s,y, true);
  this->DrawLineZ(z,z+s,x+s,y+s, true);
}

bool Cube::GetLed(char x, char y, char z) {
	return (data[z][x] & (1<<y)) == (1<<y);
}

void Cube::RotateOuterLayers(Planes rotationPlane, bool clockwise, Planes sourcePlane, unsigned char *source) {
	Planes plane = rotationPlane;
	unsigned char newData = 0;
	if (source != 0)
		newData = *source;
	if (rotationPlane == Plane_px ||
		rotationPlane == Plane_py ||
		rotationPlane == Plane_pz) {
		clockwise = !clockwise;
		plane = getOppositePlane(rotationPlane);
		newData = reverse(newData);
	}

	switch (rotationPlane) {
	case Plane_x:
		if (clockwise) {
			//store byte in y=0,z=0
			unsigned char original = 0;
			for (char x = 0; x < 8; x++) {
				original |= (data[0][x] & 1);

				//shift y down
				for (char z = 0; z < 7; z++) {
					data[z][x] &= ~1;
					data[z][x] |= (data[z+1][x] & 1);
				}
			
				//shift pz towards
				data[7][x] >>= 1;
			

				//shift py up
				for (char z = 7; z > 0; z--) {
					data[z][x] &= ~(1<<7);
					data[z][x] |= (data[z-1][x] & (1<<7));
				}
			

				//shift z away
				data[0][x] <<= 1;
			
				//put byte in y=1, z=0
				data[0][x] &= ~(1<<1);
				data[0][x] |= original & (1<<1);
			}
		} else {
			//store byte in y = 0, z=0
			//shift y up
			//shift pz away
			//shift py down
			//shift z towards
			//restore byte in y =0, z=1
		}
		break;
	case Plane_y:
		break;
	case Plane_z:
		break;
	}
}