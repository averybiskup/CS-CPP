#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>

using namespace std;

// Initializing the class
class Circle {
  private:
    double x;
    double y;
    double radius;
  public:
    void setRadius(double r);
    void setX(double value);
    void setY(double value);
    double getRadius();
    double getX();
    double getY();
    double getArea();
    bool containsPoint(double xValue, double yValue);
};

#endif
