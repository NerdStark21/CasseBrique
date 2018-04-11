#ifndef HARDSTUFF_H
#define HARDSTUFF_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QtOpenGL/QGLWidget>
#include <GL/glu.h>

#include "ball.h"

using namespace cv;

class HardStuff
{
protected:
    Rect stuff_; // Le rectangle décrivant la position et la taille de l'objet. L'origine est en haut à gauche du jeu.
    static float depth_; // Profondeur des briques du jeu.

public:
    HardStuff();

    /**
     * @brief isTouched
     * Cette fonction permet de savoir si l'objet est en colision avec la boule ou non
     *
     * @param ball
     *  Pointeur vers la boule à considérer
     *
     * @return true si la boule a une partie qui touche l'objet et false sinon
     */
    virtual bool isTouched(const Ball * ball) const = 0;

    /**
     * @brief updateAngle
     *  Cette fonction permet de mettre à jour l'attribut angle_ de la ball
     * @param ball
     *  Pointeur vers la boule à mettre à jour
     */
    virtual void updateAngle(Ball * ball) const = 0;

    /**
     * @brief updatePosition
     *  Cette fonction permet de mettre à jour l'attribut position_ de la ball
     * @param ball
     *  Pointeur vers la boule à mettre à jour
     */
    virtual void updatePosition(Ball * ball) const = 0;
};

#endif // HARDSTUFF_H
