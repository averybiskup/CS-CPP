#include <iostream>
#include <string>
#include "Circle.h"

using namespace std;

int main() {
  Circle a;

  // Setting values
  a.setX(5.0);
  a.setY(5.0);
  a.setRadius(5.0);

  cout << "Area: " << a.getArea() << endl;

  Circle * ptr = & a;

  // Setting values using the pointer
  ptr->setX(8.0);
  ptr->setY(7.0);
  ptr->setRadius(9.0);

  // Running contains point function
  float x = 8, y = 8.1;
  string contains = (ptr->containsPoint(x, y)) ? "Contains" : "Does not contain";
  cout << contains << " (" << x << ", " << y << ")" << endl;

  // Running contains point with new coordinates
  x = 16, y = 17;
  contains = (ptr->containsPoint(x, y)) ? "Contains" : "Does not contain";
  cout << contains << " (" << x << ", " << y << ")" << endl;
  return 0;
}
