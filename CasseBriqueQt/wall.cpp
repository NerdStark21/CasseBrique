#include "wall.h"

Wall::Wall(GLfloat* vertices, bool isDestructive)
{
    *vertices_ = *vertices;
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
