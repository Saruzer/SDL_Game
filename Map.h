#pragma once
#include "Game.h"
class Map
{
private:
	SDL_Rect src, dest;
	SDL_Texture *grass;
	SDL_Texture *dirt;
	SDL_Texture *water;
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

	int map[20][25];
};

