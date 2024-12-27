#include <iostream>
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();
	game->Init("Simple game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
	while (game->Running()) {
		
		game->HandleEvents();
		game->Update();
		game->Render();
	
	}
	game->Clean();
	return 0;
}