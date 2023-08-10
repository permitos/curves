#ifndef EXCEPTION_H
#define EXCEPTION_H

struct WrongRadiusException {
    float radius;
    WrongRadiusException(float r): radius(r) {}
    static bool checkRadius(float r) {
        return r < 0 ? true : false;
    }
};

struct WrongParameterException {
    float parameter;
    WrongParameterException(float p): parameter(p) {}
    static bool checkParameter(float p) {
        return (p < 0 || p >= 2*M_PI) ? true : false;
    }
};

#endif // EXCEPTION_H
