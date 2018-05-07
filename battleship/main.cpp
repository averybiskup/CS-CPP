
#include "PointCollection.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>

using namespace std;

void play(Board * s) {
	cout << "Welcome to Battleship!\n" << endl;

	// First display
	s->display();

	// Game loop
	while (s->unsunkShipCount() < 4 && !cin.fail()) {
		int x = 0, y = 0;
		cout << "x: ";
		cin >> x;

		cout << "y: ";
		cin >> y;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl; // This just makes the board look nicer
		s->fireShot(x, y);
	}
	if (s->unsunkShipCount() == 4)
		cout << "Good Job" << endl;
}

int main() {
	Board s;
	play(&s);
}
