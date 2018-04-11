#include "wall.h"

Wall::Wall(GLfloat* vertices, bool isDestructive)
{
    *vertices_ = *vertices;
    isDestructive_ = isDestructive;
    depth = 10;
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
