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
		cout << o.getShape();
		GotoXY(static_cast<SHORT>(o2.getPosition().x), static_cast<SHORT>(o2.getPosition().y));
		cout << o2.getShape();
		GotoXY(static_cast<SHORT>(o3.getPosition().x), static_cast<SHORT>(o3.getPosition().y));
		cout << o3.getShape();

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

	const Vector2D player_velocity{ 0, 10 };
	PhysicsMaterial player_physics { 10.0f, { 0.0f, 0.0f }, { 0.0f, 0.0f }, 0.0f, { 0.0f, 0.98f } };
	PhysicsMaterial p{ player_physics };
	Object player { { 40, 20 }, 'o', player_physics };

	while(true) {
		if(_kbhit()) {
			char c = _getch();
			if(c == 'q' || c == 'e') {
				break;
			}
			
			else if(c == 'a') {
				
			}
			else if(c == 'd') {

			}
		}
	}
}