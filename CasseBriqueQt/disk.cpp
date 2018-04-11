#include "disk.h"

Disk::Disk(Rect stuff, int minAngle, int maxAngle) : HardStuff(stuff)
{
    minAngle_ = minAngle;
    maxAngle_ = maxAngle;
}

void Disk::updateBall(Ball *ball, const float time) const
{

}
