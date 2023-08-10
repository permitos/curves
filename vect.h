#ifndef VECT_H
#define VECT_H

#include "point.h"
#include <memory>
#include <cmath>

class Vector {

    shared_ptr<Point> _startPoint, _endPoint;

public:

    Vector();
    Vector(shared_ptr<Point> startPoint, shared_ptr<Point> endPoint);
    Vector(const Vector& vector);
    ~Vector();

    shared_ptr<Point> getStartPoint() const;
    shared_ptr<Point> getEndPoint() const;

    void setStartPoint(shared_ptr<Point> startPoint);
    void setEndPoint(shared_ptr<Point> endPoint);

    string toString();
};

#endif // VECT_H
