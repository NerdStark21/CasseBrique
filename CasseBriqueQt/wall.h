#ifndef WALL_H
#define WALL_H

#include "hardstuff.h"

class Wall : public HardStuff
{
private:
<<<<<<< HEAD
    // Le point pour dessiner la ligne du mur
    GLfloat* vertices_;
    // Si un mur entraine la destruction de la balle ou non
    bool isDestructive_;
    GLfloat depth;
=======
    bool isDestructive_; // Est à true si le mur détruit la balle et false sinon
>>>>>>> 08345aaba3c459cf1b1932ba55bb0c12964e9f52

public:
    Wall(GLfloat* vertices, bool isDestructive);
    GLfloat* getVertices() { return vertices_; }

    // Les fonctions abstraites de HardStuff
    virtual bool isTouched(const Ball *) const;
    virtual void updateAngle(Ball *) const;
    virtual void updatePosition(Ball *) const;
};

#endif // WALL_H
