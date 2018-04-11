#include "wall.h"

Wall::Wall(Rect stuff, bool isDestructive)
{
    stuff_ = stuff;
    isDestructive_ = isDestructive;
    depth_ = 10;
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

}

GLfloat* getVertices(){
    int x = stuff_.x;
}
