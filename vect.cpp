#include "vect.h"

Vector::Vector():
    _startPoint(make_shared<Point>(Point(0, 0, 0))),
    _endPoint(make_shared<Point>(Point(0, 0, 0))) {}

Vector::Vector(shared_ptr<Point> startPoint, shared_ptr<Point>endPoint):
    _startPoint(startPoint), _endPoint(endPoint) {}

Vector::~Vector() {}

Vector::Vector(const Vector &vector) {

    _startPoint = vector.getStartPoint();
    _endPoint = vector.getEndPoint();
}

shared_ptr<Point> Vector::getStartPoint() const { return _startPoint; }
shared_ptr<Point> Vector::getEndPoint() const { return _endPoint; }

void Vector::setStartPoint(shared_ptr<Point> startPoint) { _startPoint = startPoint; }
void Vector::setEndPoint(shared_ptr<Point> endPoint) { _endPoint = endPoint; }

string Vector::toString() { return string("v = (" + to_string(_endPoint->getX() - _startPoint->getX()) +
                  ")i + (" + to_string(_endPoint->getY() - _startPoint->getY()) +
                  ")j + (" + to_string(_endPoint->getZ() - _startPoint->getZ()) +
                  ")k"); }
