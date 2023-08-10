#ifndef CIRCLE_H
#define CIRCLE_H

#include "ellipse.h"

// Circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.

class Circle: public Ellipse {

    float _radius;

public:

    Circle();
    Circle(float radius);
    Circle(float radius, float x, float y, float z);
    Circle(float radius, shared_ptr<Point> point);
    virtual ~Circle();
    Circle(const Circle &circle);

    float getRadius() const;
    void setRadius(float radius);

    bool operator<(const Circle &circle) const { return _radius < circle.getRadius(); }
};

#endif // CIRCLE_H
