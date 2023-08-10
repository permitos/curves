#include "helix.h"

Helix::Helix(): _radius(0), _step(0), Curve() {}

Helix::Helix(float radius, float step): _radius(radius), _step(step), Curve() {
    checkForExceptionRadius(radius);
}

Helix::Helix(float radius, float step, float x, float y, float z = 0):
    _radius(radius), _step(step), Curve(x, y, z) {
    checkForExceptionRadius(radius);
}
Helix::Helix(float radius, float step, shared_ptr<Point> point):
    _radius(radius), _step(step), Curve(point) {
    checkForExceptionRadius(radius);
}
Helix::~Helix() {}

Helix::Helix(const Helix &helix): Curve(helix) {

    _radius = helix.getRadius();
    _step = helix.getStep();
}

float Helix::getRadius() const { return _radius; }
float Helix::getStep() const { return _step; }

void Helix::setRadius(float radius) { _radius = radius; }
void Helix::setStep(float step) { _step = step; }

Point Helix::getPointPerParameter(float parameter) {

    checkForExceptionParameter(parameter);

    float x = _point->getX() + _radius*cos(parameter);
    float y = _point->getY() + _radius*sin(parameter);
    float z = _point->getZ() + (_step*parameter)/(2*M_PI);

    return Point(x, y, z);
}

Vector Helix::getFirstDerivativePerParameter(float parameter) {

    checkForExceptionParameter(parameter);

    float xEndPoint = (-1)*_radius*sin(parameter);
    float yEndPoint = _radius*cos(parameter);
    float zEndPoint = _step/(2*M_PI);

    return Vector(make_shared<Point>(*_point),
                  make_shared<Point>(xEndPoint, yEndPoint, zEndPoint));
}
