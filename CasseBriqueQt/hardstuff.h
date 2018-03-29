#ifndef HARDSTUFF_H
#define HARDSTUFF_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class HardStuff
{
protected:
    Rect stuff;

public:
    HardStuff();

    /**
     * @brief isTouched
     * Cette fonction permet de savoir si l'objet est en colision avec la boule ou non
     *
     * @return true si la boule a une partie qui touche l'objet et false sinon
     */
    virtual bool isTouched(Ball *) = 0;

    /**
     * @brief updateAngle
     *  Cette fonction permet de mettre à jour l'attribut angle_ de la ball
     * @param ball
     *  pointeur vers la boule à mettre à jour
     */
    virtual void updateAngle(Ball * ball) = 0;

    /**
     * @brief updatePosition
     *  Cette fonction permet de mettre à jour l'attribut position_ de la ball
     * @param ball
     *  pointeur vers la boule à mettre à jour
     */
    virtual void updatePosition(Ball * ball) = 0;
};

#endif // HARDSTUFF_H
