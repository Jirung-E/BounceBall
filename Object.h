#pragma once

class Position {
public:
	float x;
	float y;

	Position();
	Position(float x, float y);

	Position operator+(Position position);
};

class Object {
	Position position;
	char shape;

public:
	Object();
	Object(Position position);
	Object(char shape);
	Object(Position position, char shape);

	Position getPosition() const;
	char getShape() const;
};