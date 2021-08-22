#include "Sprite.h"


Sprite::Sprite(char sprite) : sprite { sprite } {

}


char Sprite::getSprite() const {
	return sprite;
}