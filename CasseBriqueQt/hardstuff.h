#ifndef HARDSTUFF_H
#define HARDSTUFF_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QtOpenGL/QGLWidget>
#include <GL/glu.h>
#include <math.h>
#include <vector>
#include <qdebug.h>

#include "ball.h"

using namespace cv;

class HardStuff
{
protected:
    Rect stuff_;    // Le rectangle décrivant la position et la taille de l'objet. L'origine est en haut à gauche du jeu.
    static float depth_;    // Profondeur des briques du jeu.

public:
    HardStuff();
    HardStuff(Rect stuff);

    /**
     * @brief isTouched
     *  Cette fonction permet de savoir si l'objet est en colision avec la boule ou non.
     *  Elle permet aussi d'actualiser l'angle et la position de la boule s'il y a touche.
     *
     * @param ball
     *  Pointeur vers la boule à considérer
     *
     * @return true si la boule a une partie qui touche l'objet et false sinon
     */
    virtual bool isTouched(Ball * ball) const;



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
     * @return un nombre entre 0 et 7 correspondant à la position en V8 de la boule par rapport à
     *  l'objet en commençant en haut à gauche.
     */
    short ballPosition(const Ball * ball) const;

    /**
     * @brief getAngleToStuff
     *  Cette fonction renvoie l'angle entre un coin de l'objet et la balle.
     *  À l'appel de cette fonction, on suppose que posV8 est un nombre pair et que
     *  le centre de la balle n'est pas dans l'objet.
     *  Par exemple, si l'objet est un rectangle Rect(1, 1, 2, 1) et que la balle est en (0, 0),
     *  alors la fonction renvoie 3 pi / 4.
     *
     * @param ball
     *  Pointeur vers la boule à considérer
     *
     * @param posV8
     *  Position de la balle par rapport à l'objet en V8, càd nombre renvoyé par la fonction ballPosition(ball).
     *
     * @return un float correspondant à l'angle entre le coin de l'objet le plus
     *  proche et la balle.
     */
    float getAngleToStuff(const Ball * ball, short posV8) const;
};

#endif // HARDSTUFF_H
