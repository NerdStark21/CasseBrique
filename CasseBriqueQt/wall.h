#ifndef WALL_H
#define WALL_H

#include "hardstuff.h"

class Wall : public HardStuff
{
private:
    GLfloat* vertices_;
    bool isDestructive_;

public:
    Wall(GLfloat* vertices, bool isDestructive);
    void drawWall();
    GLfloat* getVertices(){return vertices_;}
};

#endif // WALL_H
