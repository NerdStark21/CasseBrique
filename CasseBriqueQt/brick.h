#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include "hardstuff.h"

class Brick : public HardStuff
{
public:
    Brick(Rect stuff);

    // Les fonctions abstraites de HardStuff
    virtual bool isTouched(const Ball *) const;
    virtual void updateAngle(Ball *) const;
    virtual void updatePosition(Ball *) const;
};

#endif // BRICK_H
