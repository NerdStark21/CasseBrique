#ifndef BRICK_H
#define BRICK_H

#include "hardstuff.h"

class Brick : public HardStuff
{
private:
    Rect stuff;

public:
    Brick();
    bool isTouched(Ball* ball);
    void updateAngle();
};

#endif // BRICK_H
