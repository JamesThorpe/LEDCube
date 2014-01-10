#include "core.h"

void runCube() {
	anim_ScrollText("En error has occurred\0");
 
	anim_CubeMove();
 anim_RandomLineScroll();
 
 
  anim_ScrollPlanes();
  
  anim_CornerToCorner(true,true,true, false, true);
  anim_CornerToCorner(true,true,true, true, false);
  anim_CornerToCorner(true,true,true, false, false);

  anim_ScrollText("En error has occurred\0");
  anim_CornerToCorner(true,true,false, true, true);
  anim_CornerToCorner(false,true,false, true, true);
  anim_CornerToCorner(true,false,false, true, true);
  anim_CornerToCorner(false,false,false, true, true);
  anim_ScrollText("Object reference not set to an instance of an object\0");
  //cube->SetPlaneXZ(0, true);
anim_Flash(); 
}
