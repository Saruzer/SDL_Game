#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textsheet, SDL_Renderer* ren,int x,int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(textsheet, ren);
	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	xpos++;
	ypos++;

	srcRect.h = 2329;
	srcRect.w = 1454;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w / 9;
	destRect.h = srcRect.h / 9;

}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
