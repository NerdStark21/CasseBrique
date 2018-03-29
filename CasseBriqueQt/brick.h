#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include "hardstuff.h"

class Brick : public HardStuff
{
public:
    Brick();

    // Les fonctions abstraites de HardStuff
    bool isTouched(Ball *);
    void udateAngle(Ball *);
    void updatePosition(Ball *);
};

#endif // BRICK_H
