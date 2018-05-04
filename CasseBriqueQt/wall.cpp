#include "wall.h"

Wall::Wall(Rect stuff, bool isDestructive) : HardStuff(stuff)
{
    isDestructive_ = isDestructive;
}

GLfloat* Wall::getVertices(){
    int x = stuff_.x;
}
