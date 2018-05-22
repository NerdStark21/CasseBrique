#ifndef BRICK_H
#define BRICK_H

#include "hardstuff.h"

class Brick : public HardStuff
{
private:
    short points_;    // Nombre de points gagnés par le joueur à la destructionde la brique
    bool isDestroyed_;  // True when the brick is destroyed and false otherwise

public:
    Brick();
    Brick(Rect stuff);
    short getPoints() const { return points_; }
    void getVertices(GLfloat listVertices[]);
    bool getIsDestroyed() { return isDestroyed_; }
    void destroy() { isDestroyed_ = false; }
    void drawBrick();
};

#endif // BRICK_H
