#include "Object.h"


// <Position> -----------------------------------------------------------------------------------------------------------------
Position::Position() : x { 0.0f }, y { 0.0f } {
	
}

Position::Position(float x, float y) : x { x }, y { y } {

}


Position Position::operator+(Position position) const {
	return Position { x + position.x, y + position.y };
}

Position Position::operator-(Position position) const {
	return Position { x - position.x, y - position.y };
}

Position Position::operator+=(Position position) {
	*this = *this + position;
	return *this;
}

Position Position::operator-=(Position position) {
	*this = *this - position;
	return *this;
}
// </Position> ----------------------------------------------------------------------------------------------------------------




// <Object> -------------------------------------------------------------------------------------------------------------------
Object::Object() : position { 0, 0 }, shape { ' ' } {

}

Object::Object(Position position) : position { position }, shape { ' ' } {

}

Object::Object(char shape) : position { 0, 0 }, shape { shape } {

}

Object::Object(Position position, char shape) : position { position }, shape { shape } {

}

Object::Object(Position position, char shape, PhysicsMaterial physics_material) :
	position { position }, shape { shape }, physics { physics_material } {
	
}


Position Object::getPosition() const {
	return position;
}

char Object::getShape() const {
	return shape;
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