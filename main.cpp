#include "circle.h"
#include "helix.h"
#include <vector>
#include <random>
#include <algorithm>

template<class T>
T getRandomValue(T min, T max) {

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min,max);

    return uni(rng);
}

void getRandomCurves(vector<shared_ptr<Curve>> &curves) {

    enum TypeCurve {ellipse, circle, helix};

    for(int i = 0; i < getRandomValue(10, 20); ++i) {

        int typeOfCurve = getRandomValue(0, 2);
        shared_ptr<Point> point = make_shared<Point>(getRandomValue(-10, 10),
                                                     getRandomValue(-15, 15),
                                                     getRandomValue(-5, 5));

        switch(typeOfCurve) {

        case ellipse:
            curves.push_back(make_shared<Ellipse>(getRandomValue(0, 10), // "a" of ellipse
                                                  getRandomValue(0, 20), // "b" of ellipse
                                                  point));
        case circle:
            curves.push_back(make_shared<Circle>(getRandomValue(0, 30), // radius of circle
                                                 point));
        case helix:
            curves.push_back(make_shared<Helix>(getRandomValue(0, 30), // radius of helix
                                                getRandomValue(0, 10), // step of helix
                                                point));
        }
    }
}

void printCoordinatesOfCurves(vector<shared_ptr<Curve>> &curves) {

    float parameter = M_PI/4;

    for(auto &curve: curves)
        cout << "Curve type - \"" << typeid(*curve).name() << "\"" << endl <<
            "3D Point: " << curve->getPointPerParameter(parameter).toString() << endl <<
            "3D Point Derivative: " << curve->getFirstDerivativePerParameter(parameter).getEndPoint()->toString() << endl <<
            "3D Vector Derivative: " << curve->getFirstDerivativePerParameter(parameter).toString() << endl << endl;
}

void copyCirclesOnly(vector<shared_ptr<Curve>> &curves, vector<shared_ptr<Circle>> &circles) {

    for(auto &curve: curves) {

        if(shared_ptr<Circle> circle = dynamic_pointer_cast<Circle>(curve))
            circles.push_back(circle);
    }
}

float getSumOfRadii(vector<shared_ptr<Circle>> &circles) {

    float sumOfRadii = 0;
    for_each(circles.begin(), circles.end(),
             [&] (shared_ptr<Circle> circle) { sumOfRadii += circle->getRadius(); });

    return sumOfRadii;
}

int main() {

    try {

        vector<shared_ptr<Curve>> curves;
        vector<shared_ptr<Circle>> circles;

        // Populate a container (e.g. vector or list) of objects of these types created
        // in random manner with random parameters.
        getRandomCurves(curves);

        // Print coordinates of points and derivatives of all curves in the container at t=PI/4.
        printCoordinatesOfCurves(curves);

        // Populate a second container that would contain only circles from the first container.
        // Make sure the second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
        copyCirclesOnly(curves, circles);

        // Sort the second container in the ascending order of circles’ radii.
        // That is, the first element has the smallest radius, the last - the greatest.
        sort(circles.begin(), circles.end());

        // Compute the total sum of radii of all curves in the second container.
        cout << "Sum of radii: " << getSumOfRadii(circles) << endl;

    } catch (const WrongRadiusException& ex) {
        cout << "Radius is not correct: " << ex.radius << endl;
        return 1;

    } catch (const WrongParameterException& ex) {
        cout << "Parameter is not correct: " << ex.parameter << endl;
        return 1;
    }

    return 0;
}
