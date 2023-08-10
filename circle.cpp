#include "circle.h"

Circle::Circle(): _radius(0), Ellipse() {}

Circle::Circle(float radius):
    _radius(radius), Ellipse(radius, radius) {
    checkForExceptionRadius(radius);
}

Circle::Circle(float radius, float x, float y, float z = 0):
    _radius(radius), Ellipse(radius, radius, x, y, z) {
    checkForExceptionRadius(radius);
}

Circle::Circle(float radius, shared_ptr<Point> point):
    _radius(radius), Ellipse(radius, radius, point) {
    checkForExceptionRadius(radius);
}

Circle::~Circle() {}
Circle::Circle(const Circle &circle): Ellipse(circle) { _radius = circle.getRadius(); }

float Circle::getRadius() const { return _radius; }
void Circle::setRadius(float radius) { _radius = radius; }
