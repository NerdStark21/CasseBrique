#include "disk.h"

Disk::Disk(Rect stuff, int minAngle, int maxAngle) : HardStuff(stuff)
{
    minAngle_ = minAngle;
    maxAngle_ = maxAngle;
}

bool Disk::isTouched(const Ball *ball) const
{
    return true;
}

void Disk::updateAngle(Ball *ball) const
{

}

void Disk::updatePosition(Ball *ball) const
{

}

