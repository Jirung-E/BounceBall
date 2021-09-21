#pragma once

#include "PhysicsMaterial.h"
#include "Sprite.h"
#include "Position.h"


class Object {
protected:
	Position position;
	Sprite sprite;
	PhysicsMaterial physics;

public:
	Object();
	Object(Position position);
	Object(Sprite sprite);
	Object(Position position, Sprite sprite);
	Object(Position position, Sprite sprite, PhysicsMaterial physics_material);

	//getter
	Position getPosition() const;
	Sprite getSprite() const;
	PhysicsMaterial getPhysics() const;

	template<class T>
	T& GetComponent();

	//setter
	void setPhysics(const PhysicsMaterial& physics_material);

	void Update();
};