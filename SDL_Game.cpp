#include <iostream>
#include "Game.h"


Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	
	Uint32 frameStart;
	int frameTime;
	
	game = new Game();
	game->Init("Simple game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);
	
	while (game->Running()) {
		
		frameStart = SDL_GetTicks();
		

		game->HandleEvents();
		game->Update();
		game->Render();
	
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);

		}

	}
	game->Clean();
	return 0;
}