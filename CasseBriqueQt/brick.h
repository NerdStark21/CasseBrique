#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include "hardstuff.h"

class Brick : public HardStuff
{
private:
    short points_;    // Nombre de points gagnés par le joueur à la destructionde la brique

public:
    Brick();
    Brick(Rect stuff);
    short getPoints() const { return points_; }
    void getVertices(GLfloat listVertices[]);
    void drawBrick();
};

#endif // BRICK_H
