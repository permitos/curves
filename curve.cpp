#include "curve.h"

Curve::Curve(): _point(make_shared<Point>(Point(0, 0, 0))) {}
Curve::~Curve() {}
Curve::Curve(float x, float y, float z): _point(make_shared<Point>(Point(x, y, z))) {}
Curve::Curve(shared_ptr<Point> point): _point(point) {}
Curve::Curve(const Curve &curve) { _point = curve.getPoint(); }

shared_ptr<Point> Curve::getPoint() const { return _point; }
void Curve::setPoint(shared_ptr<Point> point) { _point = point; }

void Curve::checkForExceptionRadius(float radius) const {

    if(WrongRadiusException::checkRadius(radius))
        throw WrongRadiusException(radius);
}

void Curve::checkForExceptionParameter(float parameter) const {

    if(WrongParameterException::checkParameter(parameter))
        throw WrongParameterException(parameter);
}
