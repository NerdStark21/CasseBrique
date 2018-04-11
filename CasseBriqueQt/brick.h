#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include "hardstuff.h"

class Brick : public HardStuff
{
private:
    short points_;    // Nombre de points gagnés par le joueur à la destructionde la brique

public:
    Brick(Rect stuff);
    short getPoints() const { return points_; }

    // Les fonctions abstraites de HardStuff
    void updateBall(Ball * ball, const float time) const override;
};

#endif // BRICK_H
