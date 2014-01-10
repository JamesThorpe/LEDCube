#ifdef VSBUILD
#include <Windows.h>
#endif


#include "animations.h"
#include "font.h"

AnimationFunction animFuncsCorner[] = { 
	&anim_CornerToOffSimple,
	&anim_CornerToCornerDiagonalSimple,
	&anim_CornerToCornerPixelSimple,
	&anim_CornerToCornerPixelSimple,
	&anim_CornerToCornerPixelSimple,
	&anim_CornerToCornerPixelSimple,
	&anim_CornerToOnDiagonal
};
const char NUMCORNERFUNCS = 7;


AnimationFunction animFuncsOn[] = {
	&anim_OnToCornerDiagonal
};
const char NUMONFUNCS = 1;

AnimationFunction animFuncsOff[] = {
	&anim_OffToCornerSimple,
	&anim_OffToOffText
};
const char NUMOFFFUNCS = 2;

AnimationFunction animFuncsPlane[] = {
	&anim_nullAnimation
};