#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
class ColliderComponent;
class Game
{

private:
	bool isRunning;
	SDL_Window* window;

public:
	Game();
	~Game();

	void Init(const char* title, int x, int y, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running() { return isRunning; };

	static SDL_Renderer* renderer;
	static SDL_Event e;
	static std::vector<ColliderComponent*> colliders;
};

