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
	&anim_CornerToOnDiagonal,
	&anim_CornerToPlaneDiagonalFill,
	&anim_CornerToCornerDiagonalPlane
};
const char NUMCORNERFUNCS = 9;


AnimationFunction animFuncsOn[] = {
	&anim_OnToCornerDiagonal,
	&anim_OnToPlaneSimple
};
const char NUMONFUNCS = 2;

AnimationFunction animFuncsOff[] = {
	&anim_OffToCornerSimple//,
	//&anim_OffToOffText
};
const char NUMOFFFUNCS = 1;

AnimationFunction animFuncsPlane[] = {
	&anim_PlaneToCornerDiagonalEmpty,
	&anim_PlaneToPlaneSimple,
	&anim_PlaneToOnSimple
};
const char NUMPLANEFUNCS = 3;