#ifndef WALL_H
#define WALL_H

#include "hardstuff.h"

class Wall : public HardStuff
{
private:
    bool isDestructive_;    // Permet de savoir si un mur entraîne la destruction de la balle. Est à true si le mur détruit la balle et false sinon

public:
    Wall();
    Wall(Rect stuff, bool isDestructive);
    bool getIsDestructive() { return isDestructive_; }
    GLfloat* getVertices();
};

#endif // WALL_H
