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
extern const char NUMCORNERFUNCS;

//From On
extern void anim_OnToCornerDiagonal();
extern const char NUMONFUNCS;

//general funcs
void anim_ScrollPlanes();
void anim_CornerToCorner(bool xPos, bool yPos, bool zPos, bool clear, bool on);
void anim_RandomLineScroll();
void anim_ScrollText(char* Text, char speed);
void anim_Flash();
void anim_CubeMove();
void anim_PlaneFlipWithPause(bool pos, char plane);



#endif