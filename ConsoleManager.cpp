#include "ConsoleManager.h"

#include <thread>
#include <chrono>
#include <conio.h>

#include "Object.h"


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
	Object player { { 40, 20 }, 'o', player_physics };

	// <Update>			....    while(Update());
	while(true) {					// -> return bool...
		if(GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if(player.GetComponent<PhysicsMaterial>().getVelocity().x > -1.0f) {		// hard coding...
				player.GetComponent<PhysicsMaterial>().setVelocity({ player.getPhysics().getVelocity().x - 0.1f, player.getPhysics().getVelocity().y });
			}
		}
		else if(GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if(player.GetComponent<PhysicsMaterial>().getVelocity().x < 1.0f) {		// hard coding...
				player.GetComponent<PhysicsMaterial>().setVelocity({ player.getPhysics().getVelocity().x + 0.1f, player.getPhysics().getVelocity().y });
			}
		}
		else {
			if(player.GetComponent<PhysicsMaterial>().getVelocity().x > -1.0f) {		// hard coding...
				player.GetComponent<PhysicsMaterial>().setVelocity({ player.getPhysics().getVelocity().x - 0.1f, player.getPhysics().getVelocity().y });
			}
			else if(player.GetComponent<PhysicsMaterial>().getVelocity().x < 1.0f) {		// hard coding...
				player.GetComponent<PhysicsMaterial>().setVelocity({ player.getPhysics().getVelocity().x + 0.1f, player.getPhysics().getVelocity().y });
			}
			player.GetComponent<PhysicsMaterial>().setVelocity({ 0, player.getPhysics().getVelocity().y });
		}

		player.Update();


		GotoXY(static_cast<SHORT>(player.GetComponent<Position>().x), static_cast<SHORT>(player.GetComponent<Position>().y));
		cout << player.GetComponent<Sprite>().getSprite();
		this_thread::sleep_for(1000ms/60);
		GotoXY(static_cast<SHORT>(player.GetComponent<Position>().x), static_cast<SHORT>(player.GetComponent<Position>().y));
		cout << ' ';
	}
	// </Update>
}