#pragma once
#include "Components.h"
#include "Vector2D.h"

struct TransformComponent : public Component {
public:

	Vector2D position;
	Vector2D velocity;

	int	height = 32;
	int	width = 32;
	int scale = 1;

	int speed = 3;
	
	TransformComponent() {
		position.x = 0;
		position.y = 0;
	}
	TransformComponent(int scale) {
		position.x = 0;
		position.y = 0;
		this->scale = scale;
	}

	TransformComponent(float x, float y) {
		position.x= x;
		position.y = y;
	}
	TransformComponent(float x, float y, int w, int h,int scale) {
		position.x = x;
		position.y = y;
		width = w;
		height = h;
		this->scale = scale;
	}

	void Init() override{
		velocity.x = 0;
		velocity.y = 0;
	}
	void Update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};