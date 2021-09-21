#include "Object.h"


// <Object> -------------------------------------------------------------------------------------------------------------------
Object::Object() : position { 0, 0 }, sprite { ' ' } {

}

Object::Object(Position position) : position { position }, sprite { ' ' } {

}

Object::Object(Sprite sprite) : position { 0, 0 }, sprite { sprite } {

}

Object::Object(Position position, Sprite sprite) : position { position }, sprite { sprite } {

}

Object::Object(Position position, Sprite sprite, PhysicsMaterial physics_material) :
	position { position }, sprite { sprite }, physics { physics_material } {
	
}


// getter
Position Object::getPosition() const {
	return position;
}

Sprite Object::getSprite() const {
	return sprite;
}

PhysicsMaterial Object::getPhysics() const {
	return physics;
}

template<>
Position& Object::GetComponent<Position>() {
	return position;
}

template<>
Sprite& Object::GetComponent<Sprite>() {
	return sprite;
}

template<>
PhysicsMaterial& Object::GetComponent<PhysicsMaterial>() {
	return physics;
}


//setter
void Object::setPhysics(const PhysicsMaterial& physics_material) {
	physics = physics_material;
}

void Object::Update() {
	physics.setVelocity({ physics.getVelocity().x * 0.998f + physics.getAcceleration().x/(50/3), physics.getVelocity().y + physics.getAcceleration().y/(50/3) });
	position += { physics.getVelocity().x, physics.getVelocity().y };

	if(position.y < 0) {
		position.y = 0;
		physics.setVelocity({ physics.getVelocity().x, -physics.getVelocity().y * physics.getBounciness() });
	}
	else if(position.y > 28) {///////////////////////////////// hard coding
		position.y = 28;
		physics.setVelocity({ physics.getVelocity().x, -physics.getVelocity().y * physics.getBounciness() });
	}
	if(position.x < 0) {
		position.x = 0;
		physics.setVelocity({ -physics.getVelocity().x * physics.getBounciness(), physics.getVelocity().y });
	}
	else if(position.x > 119) {///////////////////////////////// hard coding
		position.x = 119;
		physics.setVelocity({ -physics.getVelocity().x * physics.getBounciness(), physics.getVelocity().y });
	}

	if(-0.02f < physics.getVelocity().x && physics.getVelocity().x < 0.02f) {
		physics.setVelocity({ 0.0f, physics.getVelocity().y });
	}
	//if(-0.001f < physics.getVelocity().y && physics.getVelocity().y < 0.001f) {
	//	physics.setVelocity({ physics.getVelocity().x, 0.0f });
	//}
}
// </Object> ------------------------------------------------------------------------------------------------------------------