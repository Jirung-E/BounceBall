#pragma once

#include "Object.h"


class Block : public Object {
public:
	Block();
	Block(Position position);
	Block(Sprite sprite);
	Block(Position position, Sprite sprite);
	Block(Position position, Sprite sprite, PhysicsMaterial physics_material);

	void Update();
};