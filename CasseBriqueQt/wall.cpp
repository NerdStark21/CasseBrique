#include "wall.h"

Wall::Wall(Rect stuff, bool isDestructive) : HardStuff(stuff)
{
    isDestructive_ = isDestructive;
}

void Wall::updateBall(Ball *ball, const float time) const
{

}

GLfloat* Wall::getVertices(){
    int x = stuff_.x;
}
