#pragma once

#include "Object.h"


class Ball : public Object {
public:
	Ball();
	Ball(Position position);
	Ball(Sprite sprite);
	Ball(Position position, Sprite sprite);
	Ball(Position position, Sprite sprite, PhysicsMaterial physics_material);

	//void Update();
};