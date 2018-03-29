#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include "hardstuff.h"

class Brick : public HardStuff
{
public:
    Brick();

    virtual bool isTouched(const Ball * ball) const;
    virtual void updateAngle(Ball * ball) const;
    virtual void updatePosition(Ball * ball) const;
};

#endif // BRICK_H
