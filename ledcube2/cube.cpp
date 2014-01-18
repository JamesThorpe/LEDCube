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

	switch (plane) {
	case Plane_x:
		if (clockwise) {
			for (char x = 0; x < 8; x++) {
				//get bit from corner we're about to lose
				bool o = (data[0][x] & 1) == 1;

				//shift y down
				for (char z = 0; z < 7; z++) {
					data[z][x] &= ~(1<<0);
					data[z][x] |= (data[z+1][x] & 1);
				}
			
				//shift pz towards
				data[7][x] >>= 1;
			

				//shift py up
				for (char z = 7; z > 0; z--) {
					data[z][x] &= ~(1<<7);
					data[z][x] |= (data[z-1][x] & (1<<7));
				}
			

				//shift z away, ensuring we don't pull the first column with it
				data[0][x] = (data[0][x] << 1) | (data[0][x] & 1);
			
				//restore bit in correct position
				data[0][x] &= ~(1<<1);
				if (o)
					data[0][x] |= (1<<1);
			}
		} else {
			for (char x = 0; x < 8; x++) {
				//get bit from the corner we'll lose
				bool o = (data[7][x] & 1) == 1;

				//shift y up
				for (char z = 7; z > 0; z--)
				{
					data[z][x] &= ~(1<<0);
					data[z][x] |= data[z-1][x] & (1<<0);
				}

				//shift z towards
				data[0][x] >>= 1;
			
				//shift py down
				for (char z = 0; z < 7; z++) {
					data[z][x] &= ~(1<<7);
					data[z][x] |= (data[z+1][x] & (1<<7));
				}

				//shift pz away
				data[7][x] = (data[7][x] << 1) | (data[7][x] & 1);

				data[7][x] &= ~(1<<1);
				if (o)
					data[7][x] |= (1<<1);
			}
			
		}
		//TODO: introduce source at correct edge if present
		break;
	case Plane_y:
		if (clockwise) {
			//remember byte at top of x
			unsigned char original = data[7][0];

			//shift x up
			for (char z = 7; z>0;z--) {
				data[z][0] = data[z-1][0];
			}

			//shift z left
			for (char x = 0; x < 7;x++) {
				data[0][x] = data[0][x+1];
			}

			//shift px down
			for (char z = 0; z < 7;z++) {
				data[z][7] = data[z+1][7];
			}

			//shift pz right, leaving top of x in place
			for (char x = 7; x > 1; x--) {
				data[7][x] = data[7][x-1];
			}

			//restore byte at z=7,x=1
			data[7][1] = original;
		} else {
			//remember byte at bottom of x
			unsigned char original = data[0][0];

			//shift x down
			for (char z = 0; z < 7; z++) {
				data[z][0] = data[z+1][0];
			}

			//shift pz left
			for (char x = 0; x < 7; x++) {
				data[7][x] = data[7][x+1];
			}

			//shift px up
			for (char z = 7; z > 0; z--) {
				data[z][7] = data[z-1][7];
			}

			//shift z right, leaving bottom of x in place
			for (char x = 7; x > 1; x--) {
				data[0][x] = data[0][x-1];
			}

			//restore byte at z = 0, x = 1
			data[0][1] = original;
		}
		//TODO: introduce source at correct edge if present
		break;
	case Plane_z:
		if (clockwise) {
		
			for (char z = 0; z < 8; z++) {
				//remember x=7,y=0
				bool o = (data[z][7] & (1<<0)) == (1<<0);

				//shift y right
				for (char x = 7; x > 0; x--) {
					data[z][x] &= ~(1<<0);
					data[z][x] |= (data[z][x-1] & (1<<0));
				}

				//shift x towards
				data[z][0] >>= 1;

				//shift py left
				for (char x = 0; x < 7; x++) {
					data[z][x] &= ~(1<<7);
					data[z][x] |= (data[z][x+1] & (1<<7));
				}

				//shift px away, leaving y in place
				data[z][7] = (data[z][7] << 1) | (data[z][7] & 1);

				//restore x=7,y=1
				data[z][7] &= ~(1<<1);
				if (o)
					data[z][7] |= (1<<1);
			}
		} else {
			for (char z = 0; z < 8; z++) {
				//remember x = 0, y = 0
				bool o = (data[z][0] & (1<<0)) == (1<<0);

				//shift y left
				for (char x = 0; x < 7; x++) {
					data[z][x] &= ~(1<<0);
					data[z][x] |= data[z][x+1] & (1<<0);
				}

				//shift px towards
				data[z][7] >>= 1;

				//shift py right
				for (char x = 7; x > 0; x--) {
					data[z][x] &= ~(1<<7);
					data[z][x] |= data[z][x-1] & (1<<7);
				}

				//shift x away, leaving y in place
				data[z][0] = (data[z][0] << 1) | (data[z][0] & 1);

				//restore original at x = 0, y = 1
				data[z][0] &= ~(1<<1);
				if (o)
					data[z][0] |= (1<<1);
			}
		}
		//TODO: introduce source at correct edge if present
		break;
	}
}