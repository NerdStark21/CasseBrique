#ifndef WALL_H
#define WALL_H

#include "hardstuff.h"

class Wall : public HardStuff
{
private:
    // Le point pour dessiner la ligne du mur
    GLfloat* vertices_;
    // Si un mur entraine la destruction de la balle ou non
    bool isDestructive_;
    GLfloat depth;

public:
    Wall(GLfloat* vertices, bool isDestructive);
    GLfloat* getVertices(){return vertices_;}
    virtual bool isTouched(const Ball * ball) const;
    virtual void updateAngle(Ball * ball) const;
    virtual void updatePosition(Ball * ball) const;
};

#endif // WALL_H
