
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

// EXAMPLE

/*

Welcome to Battleship!

  0  1  2  3  4  5  6  7  8  9
0 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
1 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
2 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
3 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
4 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
5 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
6 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
7 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
8 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
9 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~

x: 5
y: 5

Hit!
  0  1  2  3  4  5  6  7  8  9
0 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
1 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
2 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
3 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
4 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
5 ~  ~  ~  ~  ~  X  ~  ~  ~  ~
6 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
7 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
8 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
9 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~

x: 6
y: 6


.
.
.
.


You sank a ship with length 2!

Hit!
  0  1  2  3  4  5  6  7  8  9
0 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
1 ~  ~  X  X  ~  ~  ~  ~  ~  ~
2 o  o  ~  ~  ~  o  ~  ~  ~  ~
3 ~  ~  o  ~  ~  ~  ~  ~  ~  ~
4 ~  ~  o  ~  ~  o  ~  o  ~  ~
5 ~  ~  o  X  X  X  o  o  ~  ~
6 ~  ~  X  ~  o  o  ~  ~  ~  ~
7 ~  ~  X  ~  ~  ~  ~  ~  o  ~
8 ~  ~  X  ~  ~  ~  ~  ~  ~  o
9 ~  ~  X  ~  ~  ~  ~  ~  ~  ~

x: 8
y: 2

Miss!
  0  1  2  3  4  5  6  7  8  9
0 ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
1 ~  ~  X  X  ~  ~  ~  ~  ~  ~
2 o  o  ~  ~  ~  o  ~  ~  o  ~
3 ~  ~  o  ~  ~  ~  ~  ~  ~  ~
4 ~  ~  o  ~  ~  o  ~  o  ~  ~
5 ~  ~  o  X  X  X  o  o  ~  ~
6 ~  ~  X  ~  o  o  ~  ~  ~  ~
7 ~  ~  X  ~  ~  ~  ~  ~  o  ~
8 ~  ~  X  ~  ~  ~  ~  ~  ~  o
9 ~  ~  X  ~  ~  ~  ~  ~  ~  ~

x: 7
y: 2

Miss!
  0  1  2  3  4  5  6  7  8  9
0 ~  ~  ~  ~  o  ~  o  o  o  ~
1 ~  ~  X  X  ~  ~  X  X  X  o
2 o  o  ~  ~  ~  o  ~  o  o  ~
3 ~  ~  o  ~  o  ~  ~  ~  ~  o
4 ~  ~  o  ~  ~  o  ~  o  ~  ~
5 o  ~  o  X  X  X  o  o  ~  o
6 ~  o  X  ~  o  o  ~  ~  ~  ~
7 o  ~  X  o  o  ~  ~  ~  o  ~
8 o  ~  X  ~  ~  o  ~  ~  ~  o
9 ~  ~  X  ~  o  ~  ~  o  o  ~

x: 5
y: 1

Hit!
  0  1  2  3  4  5  6  7  8  9
0 ~  ~  ~  ~  o  ~  o  o  o  ~
1 ~  ~  X  X  ~  X  X  X  X  o
2 o  o  ~  ~  ~  o  ~  o  o  ~
3 ~  ~  o  ~  o  ~  ~  ~  ~  o
4 ~  ~  o  ~  ~  o  ~  o  ~  ~
5 o  ~  o  X  X  X  o  o  ~  o
6 ~  o  X  ~  o  o  ~  ~  ~  ~
7 o  ~  X  o  o  ~  ~  ~  o  ~
8 o  ~  X  ~  ~  o  ~  ~  ~  o
9 ~  ~  X  ~  o  ~  ~  o  o  ~

x: 4
y: 1

You sank a ship with length 5!

Hit!
  0  1  2  3  4  5  6  7  8  9
0 ~  ~  ~  ~  o  ~  o  o  o  ~
1 ~  ~  X  X  X  X  X  X  X  o
2 o  o  ~  ~  ~  o  ~  o  o  ~
3 ~  ~  o  ~  o  ~  ~  ~  ~  o
4 ~  ~  o  ~  ~  o  ~  o  ~  ~
5 o  ~  o  X  X  X  o  o  ~  o
6 ~  o  X  ~  o  o  ~  ~  ~  ~
7 o  ~  X  o  o  ~  ~  ~  o  ~
8 o  ~  X  ~  ~  o  ~  ~  ~  o
9 ~  ~  X  ~  o  ~  ~  o  o  ~

Good Job
*/
