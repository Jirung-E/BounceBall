#include "Position.h"


// <Position> -----------------------------------------------------------------------------------------------------------------
Position::Position() : x{ 0.0f }, y{ 0.0f } {

}

Position::Position(float x, float y) : x{ x }, y{ y } {

}


Position Position::operator+(Position position) const {
	return Position{ x + position.x, y + position.y };
}

Position Position::operator-(Position position) const {
	return Position{ x - position.x, y - position.y };
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