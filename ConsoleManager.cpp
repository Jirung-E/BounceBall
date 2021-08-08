#include "ConsoleManager.h"

// <for test()>
#include <thread>
#include <chrono>

#include "Object.h"
// </for test()>


void ConsoleManager::GotoXY(SHORT x, SHORT y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { x, y });
}

void ConsoleManager::test() {
	using namespace std;
	
	PhysicsMaterial physics1 { 10.0f, { 0.0f, 0.0f }, { 10.0f, 5.0f }, 0.9f, { 0.0f, 0.98f } };
	PhysicsMaterial physics2 { 10.0f, { 0.0f, 0.0f }, { 2.0f, 16.0f }, 0.9f, { 0.0f, 0.98f } };
	Object o { {10, 0}, 'o', physics1 };
	Object o2 { {70, 0}, '@', physics2 };

	while(true) {
		GotoXY(static_cast<SHORT>(o.getPosition().x), static_cast<SHORT>(o.getPosition().y));
		cout << o.getShape();
		GotoXY(static_cast<SHORT>(o2.getPosition().x), static_cast<SHORT>(o2.getPosition().y));
		cout << o2.getShape();

		this_thread::sleep_for(1000ms/60);
		GotoXY(static_cast<SHORT>(o.getPosition().x), static_cast<SHORT>(o.getPosition().y));
		GotoXY(static_cast<SHORT>(o2.getPosition().x), static_cast<SHORT>(o2.getPosition().y));
		//cout << ' ';

		o.Update();
		o2.Update();
	}
}