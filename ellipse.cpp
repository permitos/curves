#include "ellipse.h"

Ellipse::Ellipse(): _a(0), _b(0), Curve() {}
Ellipse::Ellipse(float a, float b): _a(a), _b(b), Curve() {}
Ellipse::Ellipse(float a, float b, float x, float y, float z = 0): _a(a), _b(b), Curve(x, y, z) {}
Ellipse::Ellipse(float a, float b, shared_ptr<Point> point): _a(a), _b(b), Curve(point) {}
Ellipse::~Ellipse() {}
Ellipse::Ellipse(const Ellipse &ellipse): Curve(ellipse) {

    _a = ellipse.getA();
    _b = ellipse.getB();
}

float Ellipse::getA() const { return _a; }
float Ellipse::getB() const { return _b; }

void Ellipse::setA(float a) { _a = a; }
void Ellipse::setB(float b) { _b = b; }

Point Ellipse::getPointPerParameter(float parameter) {

    checkForExceptionParameter(parameter);

    float x = _point->getX() + _a*cos(parameter);
    float y = _point->getY() + _b*sin(parameter);
    float z = _point->getZ();

    return Point(x, y, z);
}

Vector Ellipse::getFirstDerivativePerParameter(float parameter) {

    checkForExceptionParameter(parameter);

    float xEndPoint = (-1)*_a*sin(parameter);
    float yEndPoint = _b*cos(parameter);
    float zEndPoint = 0;

    return Vector(make_shared<Point>(*_point),
                  make_shared<Point>(xEndPoint, yEndPoint, zEndPoint));
}
