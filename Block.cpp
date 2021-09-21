#include "Block.h"


Block::Block() : Object { } {
	GetComponent<Sprite>() = Sprite{ '#' };
}

Block::Block(Position position) : Object { position } {
	GetComponent<Sprite>() = Sprite{ '#' };
}

Block::Block(Sprite sprite) : Object { sprite } {

}

Block::Block(Position position, Sprite sprite) : Object { position, sprite } {

}

Block::Block(Position position, Sprite sprite, PhysicsMaterial physics_material) : Object { position, sprite, physics_material } {

}

void Block::Update() {
	
}