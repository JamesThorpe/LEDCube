#ifdef VSBUILD
#include "../ard.h"
#endif

#include "cube.h"
extern Cube *cube;

void anim_ScrollPlanes();
void anim_CornerToCorner(bool xPos, bool yPos, bool zPos,bool clear, bool on);
void anim_RandomLineScroll();
void anim_ScrollText(char* Text);
void anim_Flash();
void anim_CubeMove();
void anim_PlaneFlipWithPause(bool pos, char plane);