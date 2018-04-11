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
    Rect stuff_;    // Le rectangle décrivant la position et la taille de l'objet. L'origine est en haut à gauche du jeu.
    static float depth_;    // Profondeur des briques du jeu.



public:
    HardStuff(Rect stuff);

    /**
     * @brief isTouched
     *  Cette fonction permet de savoir si l'objet est en colision avec la boule ou non
     *
     * @param ball
     *  Pointeur vers la boule à considérer
     *
     * @return true si la boule a une partie qui touche l'objet et false sinon
     */
    bool isTouched(const Ball * ball) const;

    /**
     * @brief updateAngle
     *  Cette fonction permet de mettre à jour les attributs angle_ et position_ de la ball
     * @param ball
     *  Pointeur vers la boule à mettre à jour
     */
    virtual void updateBall(Ball * ball, const float time) const = 0;



protected:
    /**
     * @brief ballPosition
     *  Cette fonction permet de connaître la position de la balle par rapport à l'objet.
     *  La position est considérée en V8.
     *  Par exemple, si le centre de la boule est en haut à gauche de l'objet, la fonction renverra 0.
     *  De même, si le centre de la boule est en bas de l'objet, la fonction renverra 5.
     *
     * @param ball
     *  Pointeur vers la boule à considérer.
     *
     * @return un nombre entre 0 et 7 correspondant à la position en V8 de la boule par rapport à l'objet.
     */
    short ballPosition(const Ball * ball) const;
};

#endif // HARDSTUFF_H
