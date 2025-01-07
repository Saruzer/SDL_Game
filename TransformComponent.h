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
		position.Zero();
	}
	TransformComponent(int scale) {
		position.Zero();
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
		velocity.Zero();
	}
	void Update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};