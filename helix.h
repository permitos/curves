#ifndef HELIX_H
#define HELIX_H

#include "curve.h"

/* Helix is spatial and is defined by its radius and step (see the figure below). It takes 2 * PI in
 * parametric space to make a round, i.e. any point on helix satisfies the condition C(t + 2*PI) = C(t) +
 * {0, 0, step}. */

class Helix: public Curve {

    float _radius, _step;

public:

    Helix();
    Helix(float radius, float step);
    Helix(float radius, float step, float x, float y, float z);
    Helix(float radius, float step, shared_ptr<Point> point);
    virtual ~Helix();
    Helix(const Helix &helix);

    float getRadius() const;
    float getStep() const;

    void setRadius(float radius);
    void setStep(float step);

    Point getPointPerParameter(float parameter) override;
    Vector getFirstDerivativePerParameter(float parameter) override;
};

#endif // HELIX_H
