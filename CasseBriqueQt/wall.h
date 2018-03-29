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
    GLfloat* getVertices(){return vertices_;}
    virtual bool isTouched(const Ball * ball) const;
    virtual void updateAngle(Ball * ball) const;
    virtual void updatePosition(Ball * ball) const;
};

#endif // WALL_H
