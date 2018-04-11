#include "brick.h"

Brick::Brick(Rect stuff) : HardStuff(stuff)
{
}

bool Brick::isTouched(const Ball *ball) const
{
    return true;
}

void Brick::updateAngle(Ball *ball) const
{

}

void Brick::updatePosition(Ball *ball) const
{

}
