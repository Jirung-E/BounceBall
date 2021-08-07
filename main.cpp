#include "Object.h"
#include "ConsoleManager.h"


int main() {
	using namespace ConsoleManager;
	using namespace std;
	

	Position p1 { -1.421f, 231 };
	Position p2 { 4211.5f, 532.085f };

	cout << (p1 + p2).x << ", " << (p1 + p2).y << endl;


	Object o { {10, 10}, 'o' };
	GotoXY(o.getPosition().x, o.getPosition().y);
	cout << o.getShape();
}