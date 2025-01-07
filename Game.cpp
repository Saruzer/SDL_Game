#include "Game.h"
#include "TextureManager.h"	
#include "Map.h"
#include "Components.h"
#include "Collision.h"

Map* GameMap;
Manager GameManager;

SDL_Event Game::e;
SDL_Renderer* Game::renderer = nullptr;

std::vector<ColliderComponent*> Game::colliders;

auto& Player(GameManager.addEntity());

auto& Wall(GameManager.addEntity());

auto& tile0(GameManager.addEntity());
auto& tile1(GameManager.addEntity());
auto& tile2(GameManager.addEntity());
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
	

	tile0.addComponent<TileComponent>(200, 200, 32, 32, 0);
	tile1.addComponent<TileComponent>(250, 250, 32, 32, 2);
	tile1.addComponent<ColliderComponent>("Dirt");
	tile2.addComponent<TileComponent>(150, 150,32,32,1);
	tile2.addComponent<ColliderComponent>("Grass");

	Player.addComponent<TransformComponent>();
	Player.addComponent<SpriteComponent>("Player.png");
	Player.addComponent<KeyboardController>();
	Player.addComponent<ColliderComponent>("Player");


	Wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	Wall.addComponent<SpriteComponent>("Wall.png");
	Wall.addComponent<ColliderComponent>("Wall");

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

	for (auto cc : colliders) {
		Collision::AABB(Player.getComponent<ColliderComponent>(), *cc);
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	GameManager.Draw();

	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}