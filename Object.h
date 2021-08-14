#pragma once

#include "PhysicsMaterial.h"


class Position {
public:
	float x;
	float y;

	Position();
	Position(float x, float y);

	Position operator+(Position position) const;
	Position operator-(Position position) const;
	Position operator+=(Position position);
	Position operator-=(Position position);
};

class Object {
	Position position;
	char shape;
	PhysicsMaterial physics;

public:
	Object();
	Object(Position position);
	Object(char shape);
	Object(Position position, char shape);
	Object(Position position, char shape, PhysicsMaterial physics_material);

	Position getPosition() const;
	char getShape() const;
	PhysicsMaterial getPhysics() const;

	void Update();
};