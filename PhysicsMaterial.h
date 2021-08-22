#pragma once

#include "Vector2D.h"


// F = ma
// v = v0 + at

class PhysicsMaterial {
	float mass;
	Vector2D acceleration;
	Vector2D velocity;
	float bounciness;

	const Vector2D gravity;


public:
	PhysicsMaterial();
	PhysicsMaterial(float mass, Vector2D acceleration, Vector2D velocity, float bounciness, Vector2D gravity);
	//PhysicsMaterial(const PhysicsMaterial& physics_material) = default;
	PhysicsMaterial operator=(const PhysicsMaterial& physics_material);


	void setMass(double mass);
	float getMass() const;

	void setAcceleration(Vector2D acceleration);
	Vector2D getAcceleration() const;

	void setVelocity(Vector2D velocity);
	Vector2D getVelocity() const;

	void setBounciness(double bounciness);
	float getBounciness() const;

	void update();
};