#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point {

    float _x, _y, _z;

public:

    Point();
    Point(float x, float y, float z);
    Point(const Point& point);
    ~Point();

    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(float x);
    void setY(float y);
    void setZ(float z);

    string toString();
};

#endif // POINT_H
