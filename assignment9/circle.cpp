#include <iostream>
#include <string>
#include "Circle.h"
#include <math.h>
#include <cmath>

using namespace std;

void Circle::setRadius(double r) {
  radius = r;
}

void Circle::setX(double value) {
  x = value;
}

void Circle::setY(double value) {
  y = value;
}

double Circle::getRadius() {
  return radius;
}

double Circle::getX() {
  return x;
}

double Circle::getY() {
  return y;
}

// Area = pi * r^2, that's what this function is
double Circle::getArea() {
  return 3.14 * getRadius() * getRadius();
}

// Making sure that the point is in the circle
bool Circle::containsPoint(double x, double y) {
  // Length from center to point
  double xLength = abs(x - getX());
  double yLength = abs(y - getY());
  float l = sqrt((xLength * xLength) + (yLength * yLength));
  if (l <= getRadius()) {
    return true;
  }
  return false;
}
