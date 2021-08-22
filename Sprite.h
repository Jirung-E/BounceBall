#pragma once

class Sprite {
	char sprite;

public:
	Sprite() = default;
	Sprite(char sprite);

	char getSprite() const;
};