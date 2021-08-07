#include "Object.h"


// <Position> -----------------------------------------------------------------------------------------------------------------
Position::Position() {
	x = 0.0f;
	y = 0.0f;
}

Position::Position(float x, float y) : x { x }, y { y } {

}


Position Position::operator+(Position position) {
	return Position{ x + position.x, y + position.y };
}
// </Position> ----------------------------------------------------------------------------------------------------------------

// <Object> -------------------------------------------------------------------------------------------------------------------
Object::Object() {

}

Object::Object(Position position) {

}

Object::Object(char shape) {

}

Object::Object(Position position, char shape) {

}
// </Object> ------------------------------------------------------------------------------------------------------------------