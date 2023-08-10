#ifndef CURVE_H
#define CURVE_H

#include "vect.h"
#include "exception.h"

// All curves are parametrically defined, i.e. a point is calculated using some C(t) formula.

class Curve {

protected:

    shared_ptr<Point> _point;

public:

    virtual Point getPointPerParameter(float parameter) = 0;
    virtual Vector getFirstDerivativePerParameter(float parameter) = 0;

    Curve();
    Curve(float x, float y, float z);
    Curve(shared_ptr<Point> point);
    Curve(const Curve& curve);
    virtual ~Curve();

    shared_ptr<Point> getPoint() const;
    void setPoint(shared_ptr<Point> point);

    void checkForExceptionRadius(float radius) const;
    void checkForExceptionParameter(float parameter) const;
};

#endif // CURVE_H
