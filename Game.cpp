#include "Game.h"
#include "TextureManager.h"	
#include "Map.h"
#include "Components.h"

Map* GameMap;
Manager GameManager;
SDL_Event Game::e;
SDL_Renderer* Game::renderer = nullptr;

auto& Player(GameManager.addEntity());


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

	GameMap = new Map();
	
	Player.addComponent<TransformComponent>();
	Player.addComponent<SpriteComponent>("Player.png");
	Player.addComponent<KeyboardController>();


}

void Game::HandleEvents()
{
	

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
	GameManager.Update();
	GameManager.Refresh();
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	GameMap->DrawMap();
	GameManager.Draw();

	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}