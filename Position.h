#pragma once


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