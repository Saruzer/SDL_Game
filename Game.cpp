#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* Player;
GameObject* Enemy;


Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, x, y, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		isRunning = true;
	}
	Player = new GameObject("Zombie.png",renderer,0,0);
	Enemy = new GameObject("Pea.png", renderer, 500, 200);

}

void Game::HandleEvents()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}
int cnt = 0;
void Game::Update()
{
	Player->Update();
	Enemy->Update();

}

void Game::Render()
{
	SDL_RenderClear(renderer);

	Player->Render();
	Enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}