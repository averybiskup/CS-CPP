//
//  Board.cpp
//  Battleship
//

#include "Board.h"
#include "Ship.h"
#include "PointCollection.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Point.h"

using namespace std;

Board::Board() {
  srand(time(0)); // Randomizing time

  int lengths[4] = {5, 4, 3, 2};
  for (int i = 0; i < 4; i++)
    ships[i] = generateShipWithLength(lengths[i]);
}

// Deleting Ships
Board::~Board() {
  for (int i = 0; i < 4; i++)
    delete ships[i];
}

// Function for firing a shot at a given point
bool Board::fireShot(int x, int y) {

  // Seeing if the shot hits
  for (int i = 0; i < 4; i++) {
    if (ships[i]->containsPoint(point(x, y))) {
      ships[i]->shotFiredAtPoint(point(x, y));
      cout << "\nHit!" << endl;
      display();
      return true;
    }
  }

  // Not adding to misses arr if it has already been added
  if (!misses.contains(point(x, y)))
    misses.add(point(x, y));

  cout << "\nMiss!" << endl;
  display();
  return false;
}

void Board::display() {
  cout << " ";

  for (int w = 0; w < 10; w++)
    cout << " " << w << " ";

  cout << endl;

  // Creating the board
  for (int y = 0; y < 10; y++) {
    cout << y;
    for (int x = 0; x < 10; x++) {
      int placed = 0;

      // Loop for printing something rather than water
      for (int l = 0; l < 4; l++) {
        if (ships[l]->isHitAtPoint(point(x, y))) {
          cout << " X ";
          placed++;
        }
      }
      if (misses.contains(point(x, y))) {
        cout << " o ";
        placed++;
      }
      if (placed == 0)
        cout << " ~ ";
    }
    cout << endl;
  }
  cout << endl;
}

// Function for generating a new ship
Ship * Board::generateShipWithLength(int l) {

  // Random Origin
  int x = (rand()%(9) + 1), y = (rand()%(9) + 1);

  point p(x, y);

  // Random orientation
  int orientation[2] = {0, 1};
  direction o = (rand()%(100) + 1 >= 50) ? VERTICAL : HORIZONTAL;

  Ship * s;
  s = new Ship(p, o, l);

  // Making sure the new ship has a new spot
  for (int i = 0; i < 4; i++) {
    if (ships[i]) {
      if (s->collidesWith(*ships[i])) {
        delete s;
         generateShipWithLength(l);
      }
    }
  }

  return s;
}

// Checking how many ships are unsunk
int Board::unsunkShipCount() {
  int total = 0;
  for (int i = 0; i < 4; i++) {
    if (ships[i]->isSunk())
      total++;
  }
  return total;
}
