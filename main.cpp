#include "Object.h"

#include <iostream>


int main() {
	using namespace std;

	Position p1 { -1.421f, 231 };
	Position p2 { 4211.5f, 532.085f };

	cout << (p1 + p2).x << ", " << (p1 + p2).y;
}