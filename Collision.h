#pragma once
#include "SDL.h"
class Collision {
private:


public:
	static bool AABB(const SDL_Rect& recA,const SDL_Rect& recB);
};