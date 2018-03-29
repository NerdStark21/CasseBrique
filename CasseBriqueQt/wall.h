#ifndef WALL_H
#define WALL_H

#include "hardstuff.h"

class Wall : public HardStuff
{
public:
    Wall();

    // Les fonctions abstraites de HardStuff
    bool isTouched(Ball *);
    void updateAngle(Ball *);
    void updatePosition(Ball *);
};

#endif // WALL_H
