#include "PhysicsMaterial.h"


PhysicsMaterial::PhysicsMaterial() :
	mass { 0.0f }, acceleration { 0.0f, 0.0f }, velocity { 0.0f, 0.0f }, bounciness { 0.0f }, gravity { 0.0f, 0.0f } {

}

PhysicsMaterial::PhysicsMaterial(float mass, Vector2D acceleration, Vector2D velocity, float bounciness, Vector2D gravity) : 
	mass { mass }, acceleration { acceleration + gravity }, velocity { velocity }, bounciness { bounciness }, gravity { gravity } {

}

PhysicsMaterial PhysicsMaterial::operator=(const PhysicsMaterial& physics_material) {
	mass = physics_material.mass;
	acceleration = physics_material.acceleration;
	velocity = physics_material.velocity;
	bounciness = physics_material.bounciness;

	return *this;
}

//PhysicsMaterial::PhysicsMaterial(const PhysicsMaterial& physics_material) = default;


void PhysicsMaterial::setMass(double mass) {
	if(mass < 0) {
		mass = 0;
	}
	this->mass = static_cast<float>(mass);
}

float PhysicsMaterial::getMass() const {
	return mass;
}

void PhysicsMaterial::setAcceleration(Vector2D acceleration) {
	this->acceleration = acceleration;
}

Vector2D PhysicsMaterial::getAcceleration() const {
	return acceleration;
}

void PhysicsMaterial::setVelocity(Vector2D velocity) {
	this->velocity = velocity;
}

Vector2D PhysicsMaterial::getVelocity() const {
	return velocity;
}

void PhysicsMaterial::setBounciness(double bounciness) {
	if(bounciness > 1) {
		bounciness = 1;
	}
	else if(bounciness < 0) {
		bounciness = 0;
	}
	this->bounciness = static_cast<float>(bounciness);
}

float PhysicsMaterial::getBounciness() const {
	return bounciness;
}


void PhysicsMaterial::update() {
	
}