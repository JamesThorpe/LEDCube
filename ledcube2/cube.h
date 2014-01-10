#ifndef CUBE_H
#define CUBE_H

#ifndef VSBUILD
#include "Arduino.h"
#endif

#define PLANE_X 1
#define PLANE_Y 2
#define PLANE_Z 3

class Cube {
private:
	unsigned char data[8][8];

public:
	Cube();
	void ClearAll();
	void FillAll();
	void SetAll(bool on);
	void SetLed(char x, char y, char z, bool on);
	bool GetLed(char x, char y, char z);

	void SetPlaneXY(char layer, bool on);
	void SetPlaneXZ(char layer, bool on);
	void SetPlaneYZ(char layer, bool on);
	void ScrollOuterColumns(char src);
        void DrawLineX(char startX, char endX, char y, char z, bool on);
        void DrawLineY(char startY, char endY, char x, char z, bool on);
        void DrawLineZ(char startZ, char endZ, char x, char y, bool on);
        void DrawCube(char x, char y, char z, char s, bool clr);
        
	unsigned char* GetLayer(char layer);
};

#endif  

