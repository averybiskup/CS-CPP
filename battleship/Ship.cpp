#include "Ship.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor Function
Ship::Ship(point originPoint, direction o, int l) {
  origin = originPoint;
  orientation = o;
  length = l;

  for (int i = 0; i < l; i++) {
    int add = i;

    // Making sure that the ship is in the board
    if (originPoint.getX() + l > 10 && o == 0)
      add = i * -1;
    if (originPoint.getY() + l > 10 && o == 1)
      add = i * -1;

    // Adding points
    points.add((o == 0) ? point(origin.getX() + add, origin.getY()) : point(origin.getX(), origin.getY() + add));
  }
}

// Copy Constructor
Ship::Ship(const Ship& s)  {
  *this = s;
}

// Checking if point there is a ship at a given point
bool Ship::containsPoint(const point& p) const {
  for (int i = 0; i < points.getSize(); i++) {
    if (points.get(i).getY() == p.getY() && points.get(i).getX() == p.getX())
      return true;
  }
  return false;
}

// Seeing if two ships collide
bool Ship::collidesWith(const Ship& s) const {
	for (int i = 0; i < points.getSize(); i++) {
    for (int l = 0; l < s.points.getSize(); l++) {
      if (points.get(i).getY() == s.points.get(l).getY() && points.get(i).getX() == s.points.get(l).getX()) {
        return true;
      }
    }
  }
  return false;
}

// Firing a shot at a given point
void Ship::shotFiredAtPoint(const point& p) {
  int total = 0;
  if (hitCount() < length) {

    // Making sure the hit hasn't already been registered
    for (int i = 0; i < hits.getSize(); i++) {
      if (isHitAtPoint(p))
        total++;
    }
  }

  // Making sure the ship hasn't already registered a hit
  if (total == 0) {
    hits.add(p);
    if (hits.getSize() == length)
      cout << "You sank a ship with length " << length << "!" << endl;
  }
}

// Checking if a ship is hit a given point
bool Ship::isHitAtPoint(const point& p) {
  for (int i = 0; i < hits.getSize(); i++) {
    if (hits.get(i).getY() == p.getY() && hits.get(i).getX() == p.getX())
      return true;
  }
  return false;
}

// How many hits the ship has
int Ship::hitCount() const {
    return hits.getSize();
}

// Ship's equals operator
const Ship& Ship::operator=(const Ship& s) {
  length = s.length;
  orientation = s.orientation;
  origin = s.origin;
  points = s.points;
  hits = s.hits;
	return *this;
}

// Testing if the ship has been sunk
bool Ship::isSunk() {
  if (hitCount() >= length)
    return true;
	return false;
}
