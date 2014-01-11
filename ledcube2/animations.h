#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#ifdef VSBUILD
#include "../ard.h"
#endif

#include "cube.h"
extern Cube *cube;

typedef void (*AnimationFunction)(void);

#define ANIMPAUSE 500
#define ANIMSLOW 180
#define ANIMMED 100
#define ANIMFAST 40

extern AnimationFunction animFuncsCorner[];
extern AnimationFunction animFuncsOn[];
extern AnimationFunction animFuncsOff[];
extern AnimationFunction animFuncsPlane[];

/* Animation Types

Corner -> Corner
Corner -> On
On -> Corner
On -> On
Off -> Off
Off -> Corner
Corner -> Off
On -> Off
Off -> On
Corner -> Plane
Plane -> Corner
Plane -> Plane
Plane -> On
On -> Plane
*/

void anim_nullAnimation();

//From Off
extern void anim_OffToCornerSimple();
extern void anim_OffToOffText();
extern const char NUMOFFFUNCS;

//From Corner
extern void anim_CornerToOffSimple();
extern void anim_CornerToCornerDiagonalSimple();
extern void anim_CornerToCornerPixelSimple();
extern void anim_CornerToOnDiagonal();
extern void anim_CornerToPlaneDiagonalFill();
extern void anim_CornerToCornerDiagonalPlane();
extern const char NUMCORNERFUNCS;

//From On
extern void anim_OnToCornerDiagonal();
extern void anim_OnToPlaneSimple();
extern const char NUMONFUNCS;

//From Plane
extern void anim_PlaneToCornerDiagonalEmpty();
extern void anim_PlaneToPlaneSimple();
extern void anim_PlaneToOnSimple();
extern const char NUMPLANEFUNCS;

//general funcs
void anim_SetCoordFromCorner(char *x, char* y, char *z, CubeCorners corner);
void anim_generalEnumerateAxis(CubeCorners startCorner, CubeCorners endCorner, bool on, bool clear);
void anim_ScrollPlanes();
void anim_PlaneMove(Planes startPlane, bool on, bool clear, bool stopShort);
//void anim_CornerToCorner(bool xPos, bool yPos, bool zPos, bool clear, bool on);
void anim_RandomLineScroll();
void anim_ScrollText(char* Text, char speed);
void anim_Flash();
void anim_CubeMove();

void getPlanesForCorner(CubeCorners corner, Planes* planes);
void getCornersForPlane(Planes plane, CubeCorners *corner);
Planes getPlaneFromOppositeCorners(CubeCorners a, CubeCorners b);

CubeCorners getOppositeCornerCube(CubeCorners corner);
CubeCorners getOppositeCornerPlane(CubeCorners corner, Planes plane);
Planes getOppositePlane(Planes plane);
//get random opposite corner on plane from corner
//get random adjacent corner on plane from corner


#endif