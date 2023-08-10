#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

// Ellipse is planar in the plane XoY and is defined by its two radii, along X and Y axes.

class Ellipse: public Curve {

    float _a, _b;

public:

    Point getPointPerParameter(float parameter) override;
    Vector getFirstDerivativePerParameter(float parameter) override;

    Ellipse();
    Ellipse(float a, float b);
    Ellipse(float a, float b, float x, float y, float z);
    Ellipse(float a, float b, shared_ptr<Point> point);
    virtual ~Ellipse();
    Ellipse(const Ellipse &ellipse);

    float getA() const;
    float getB() const;

    void setA(float a);
    void setB(float b);
};

#endif // ELLIPSE_H
