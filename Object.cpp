#include "Object.h"


// <Position> -----------------------------------------------------------------------------------------------------------------
Position::Position() : x { 0.0f }, y { 0.0f } {
	
}

Position::Position(float x, float y) : x { x }, y { y } {

}


Position Position::operator+(Position position) {
	return Position { x + position.x, y + position.y };
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


Position Object::getPosition() const {
	return position;
}

char Object::getShape() const {
	return shape;
}
// </Object> ------------------------------------------------------------------------------------------------------------------