#pragma once
#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component {
private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;


public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		SetTexture(path);
	}

	void SetTexture(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void Init() override {

		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;

	}
	void Update() override {
		destRect.x = position->GetX();
		destRect.y = position->GetY();
	}
	void Draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}

};