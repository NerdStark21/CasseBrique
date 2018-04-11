#ifndef WALL_H
#define WALL_H

#include "hardstuff.h"

class Wall : public HardStuff
{
private:
    // Si un mur entraine la destruction de la balle ou non
    bool isDestructive_;    // Est à true si le mur détruit la balle et false sinon

public:
    Wall(Rect stuff, bool isDestructive);
    GLfloat* getVertices();

    // Les fonctions abstraites de HardStuff
    virtual bool isTouched(const Ball *) const;
    virtual void updateAngle(Ball *) const;
    virtual void updatePosition(Ball *) const;
};

#endif // WALL_H
