#include "ConsoleManager.h"

#include <thread>
#include <chrono>

#include "Object.h"
#include "Ball.h"
#include "Block.h"


void ConsoleManager::GotoXY(SHORT x, SHORT y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { x, y });
}

void ConsoleManager::test() {
	using namespace std;
	
	PhysicsMaterial physics1 { 10.0f, { 0.0f, 0.0f }, { 10.0f, 5.0f }, 0.9f, { 0.0f, 0.98f } };
	PhysicsMaterial physics2 { 10.0f, { 0.0f, 0.0f }, { 2.0f, 16.0f }, 0.9f, { 0.0f, 0.98f } };
	Object o { {10, 0}, 'o', physics1 };
	Object o2 { {70, 0}, '@', physics2 };
	Object o3{ { 40, 30 }, '3', physics1 };

	while(true) {
		GotoXY(static_cast<SHORT>(o.getPosition().x), static_cast<SHORT>(o.getPosition().y));
		cout << o.getSprite().getSprite();
		GotoXY(static_cast<SHORT>(o2.getPosition().x), static_cast<SHORT>(o2.getPosition().y));
		cout << o2.getSprite().getSprite();
		GotoXY(static_cast<SHORT>(o3.getPosition().x), static_cast<SHORT>(o3.getPosition().y));
		cout << o3.getSprite().getSprite();

		this_thread::sleep_for(1000ms/60);
		GotoXY(static_cast<SHORT>(o.getPosition().x), static_cast<SHORT>(o.getPosition().y));
		cout << ' ';
		GotoXY(static_cast<SHORT>(o2.getPosition().x), static_cast<SHORT>(o2.getPosition().y));
		cout << ' ';
		GotoXY(static_cast<SHORT>(o3.getPosition().x), static_cast<SHORT>(o3.getPosition().y));
		cout << ' ';

		o.Update();
		o2.Update();
		o3.Update();
	}
}

//void ConsoleManager::update() {
//
//}

void ConsoleManager::controlTest() {
	using namespace std;

	const Vector2D player_velocity { 0, 10 };
	PhysicsMaterial player_physics { 10.0f, { 0.0f, 0.0f }, { 0.0f, 0.0f }, 1.0f, { 0.0f, 0.98f } };
	//PhysicsMaterial p { player_physics };
	Ball player1 { { 40, 20 }, 'o', player_physics };
	Ball player2 { { 10, 20 }, 'x', player_physics };

	// <Update>			....    while(Update());
	while(true) {					// -> return bool...
		//p1
		if(GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if(player1.GetComponent<PhysicsMaterial>().getVelocity().x > -1.0f) {		// hard coding...
				player1.GetComponent<PhysicsMaterial>().setVelocity({ player1.getPhysics().getVelocity().x - 0.1f, player1.getPhysics().getVelocity().y });
			}
		}
		else if(GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if(player1.GetComponent<PhysicsMaterial>().getVelocity().x < 1.0f) {		// hard coding...
				player1.GetComponent<PhysicsMaterial>().setVelocity({ player1.getPhysics().getVelocity().x + 0.1f, player1.getPhysics().getVelocity().y });
			}
		}
		else {
			if(player1.GetComponent<PhysicsMaterial>().getVelocity().x > -1.0f) {		// hard coding...
				player1.GetComponent<PhysicsMaterial>().setVelocity({ player1.getPhysics().getVelocity().x - 0.1f, player1.getPhysics().getVelocity().y });
			}
			else if(player1.GetComponent<PhysicsMaterial>().getVelocity().x < 1.0f) {		// hard coding...
				player1.GetComponent<PhysicsMaterial>().setVelocity({ player1.getPhysics().getVelocity().x + 0.1f, player1.getPhysics().getVelocity().y });
			}
			player1.GetComponent<PhysicsMaterial>().setVelocity({ 0, player1.getPhysics().getVelocity().y });
		}

		//p2
		if (GetAsyncKeyState(0x41) & 0x8000) {
			if (player2.GetComponent<PhysicsMaterial>().getVelocity().x > -1.0f) {		// hard coding...
				player2.GetComponent<PhysicsMaterial>().setVelocity({ player2.getPhysics().getVelocity().x - 0.1f, player2.getPhysics().getVelocity().y });
			}
		}
		else if (GetAsyncKeyState(0x44) & 0x8000) {
			if (player2.GetComponent<PhysicsMaterial>().getVelocity().x < 1.0f) {		// hard coding...
				player2.GetComponent<PhysicsMaterial>().setVelocity({ player2.getPhysics().getVelocity().x + 0.1f, player2.getPhysics().getVelocity().y });
			}
		}
		else {
			if (player2.GetComponent<PhysicsMaterial>().getVelocity().x > -1.0f) {		// hard coding...
				player2.GetComponent<PhysicsMaterial>().setVelocity({ player2.getPhysics().getVelocity().x - 0.1f, player2.getPhysics().getVelocity().y });
			}
			else if (player2.GetComponent<PhysicsMaterial>().getVelocity().x < 1.0f) {		// hard coding...
				player2.GetComponent<PhysicsMaterial>().setVelocity({ player2.getPhysics().getVelocity().x + 0.1f, player2.getPhysics().getVelocity().y });
			}
			player2.GetComponent<PhysicsMaterial>().setVelocity({ 0, player2.getPhysics().getVelocity().y });
		}

		// update
		player1.Update();
		player2.Update();

		// draw .
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			cout << '.';
		}

		// draw player sprite
		GotoXY(static_cast<SHORT>(player1.GetComponent<Position>().x), static_cast<SHORT>(player1.GetComponent<Position>().y));
		cout << player1.GetComponent<Sprite>().getSprite();
		GotoXY(static_cast<SHORT>(player2.GetComponent<Position>().x), static_cast<SHORT>(player2.GetComponent<Position>().y));
		cout << player2.GetComponent<Sprite>().getSprite();

		this_thread::sleep_for(1000ms/60);

		// erase player sprite
		GotoXY(static_cast<SHORT>(player1.GetComponent<Position>().x), static_cast<SHORT>(player1.GetComponent<Position>().y));
		cout << ' ';
		GotoXY(static_cast<SHORT>(player2.GetComponent<Position>().x), static_cast<SHORT>(player2.GetComponent<Position>().y));
		cout << ' ';
	}
	// </Update>
}

void ConsoleManager::constructorTest() {
	using namespace std;

	PhysicsMaterial player_physics{ 10.0f, { 0.0f, 0.0f }, { 0.0f, 0.0f }, 1.0f, { 0.0f, 0.98f } };
	Ball ball { { 40, 20 }, 'o', player_physics };

	Block block{ { 50, 30 } };

	GotoXY(static_cast<SHORT>(block.GetComponent<Position>().x), static_cast<SHORT>(block.GetComponent<Position>().y));
	cout << block.GetComponent<Sprite>().getSprite();

	while (1) {
		ball.Update();

		// draw player sprite
		GotoXY(static_cast<SHORT>(ball.GetComponent<Position>().x), static_cast<SHORT>(ball.GetComponent<Position>().y));
		cout << ball.GetComponent<Sprite>().getSprite();

		this_thread::sleep_for(1000ms / 60);

		// erase player sprite
		GotoXY(static_cast<SHORT>(ball.GetComponent<Position>().x), static_cast<SHORT>(ball.GetComponent<Position>().y));
		cout << ' ';
	}
}