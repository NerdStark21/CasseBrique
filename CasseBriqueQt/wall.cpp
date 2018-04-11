#include "wall.h"

Wall::Wall(Rect stuff, bool isDestructive) : HardStuff(stuff)
{
    isDestructive_ = isDestructive;
}

bool Wall::isTouched(const Ball *ball) const
{
    return true;
}

void Wall::updateAngle(Ball *ball) const
{

}

void Wall::updatePosition(Ball *ball) const
{
    int x = stuff_.x;
}

GLfloat* Wall::getVertices(){
    int x = stuff_.x;
}
