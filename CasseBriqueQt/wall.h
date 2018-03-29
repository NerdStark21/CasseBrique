#ifndef WALL_H
#define WALL_H

#include "hardstuff.h"

class Wall : public HardStuff
{
private:
    bool isDestructive_;

public:
    Wall(GLfloat* vertices, bool isDestructive);
    GLfloat* getVertices() { return vertices_; }

    // Les fonctions abstraites de HardStuff
    virtual bool isTouched(const Ball *) const;
    virtual void updateAngle(Ball *) const;
    virtual void updatePosition(Ball *) const;
};

#endif // WALL_H
