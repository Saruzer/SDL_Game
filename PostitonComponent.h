#pragma once
#include "Components.h"

class PositionComponent : public Component {
private:
	int xpos;
	int ypos;
public:

	PositionComponent() {
		xpos = 0;
		ypos = 0;
	}


	PositionComponent(int x, int y) {
		xpos = x;
		ypos = y;
	}

	int GetX() { return xpos; }
	int GetY() { return ypos; }

	void Update() override {
		xpos++;
		ypos++;
	}

	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
};