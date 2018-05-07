//
//  Board.h
//  Battleship
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Ship.h"
#include "PointCollection.h"
#include "Point.h"

class Board {
  private:
    Ship * ships[4]; // Ship arr
    PointCollection misses; // Misses PointCollection
    Ship * generateShipWithLength(int l); // Function for generating a new ship
  public:
    Board(); // Constructor
    ~Board(); // Destructor
    bool fireShot(int x, int y); // Function for firing a shot
    int unsunkShipCount(); // Checking how many ships still stand
    void display(); // Displaying the game

};

#endif
