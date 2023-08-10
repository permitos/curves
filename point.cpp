#include "point.h"

Point::Point(): _x(0), _y(0), _z(0) {}
Point::Point(float x, float y, float z): _x(x), _y(y), _z(z) {}
Point::~Point() {}

Point::Point(const Point &point) {

    _x = point.getX();
    _y = point.getY();
    _z = point.getZ();
}

float Point::getX() const { return _x; }
float Point::getY() const { return _y; }
float Point::getZ() const { return _z; }

void Point::setX(float x) { _x = x; }
void Point::setY(float y) { _y = y; }
void Point::setZ(float z) { _z = z; }

string Point::toString() { return string("P (" + to_string(_x) +
                  ", " + to_string(_y) +
                  ", " + to_string(_z) +
                  ")"); }
