#include "Ball.h"


Ball::Ball() : Object() {

}

Ball::Ball(Position position) : Object { position } {

}

Ball::Ball(Sprite sprite) : Object { sprite } {

}

Ball::Ball(Position position, Sprite sprite) : Object { position, sprite } {

}

Ball::Ball(Position position, Sprite sprite, PhysicsMaterial physics_material) : Object { position, sprite, physics_material } {

}

void Ball::Update() {
	physics.setVelocity({ physics.getVelocity().x * 0.998f + physics.getAcceleration().x / (50 / 3), physics.getVelocity().y + physics.getAcceleration().y / (50 / 3) });
	position += { physics.getVelocity().x, physics.getVelocity().y };

	if (position.y < 0) {
		position.y = 0;
		physics.setVelocity({ physics.getVelocity().x, -physics.getVelocity().y * physics.getBounciness() });
	}
	else if (position.y > 28) {///////////////////////////////// hard coding
		position.y = 28;
		physics.setVelocity({ physics.getVelocity().x, -physics.getVelocity().y * physics.getBounciness() });
	}
	if (position.x < 0) {
		position.x = 0;
		physics.setVelocity({ -physics.getVelocity().x * physics.getBounciness(), physics.getVelocity().y });
	}
	else if (position.x > 119) {///////////////////////////////// hard coding
		position.x = 119;
		physics.setVelocity({ -physics.getVelocity().x * physics.getBounciness(), physics.getVelocity().y });
	}

	if (-0.02f < physics.getVelocity().x && physics.getVelocity().x < 0.02f) {
		physics.setVelocity({ 0.0f, physics.getVelocity().y });
	}
	//if(-0.001f < physics.getVelocity().y && physics.getVelocity().y < 0.001f) {
	//	physics.setVelocity({ physics.getVelocity().x, 0.0f });
	//}
}