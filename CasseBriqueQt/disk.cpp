#include "disk.h"

Disk::Disk(Rect stuff, int minAngle, int maxAngle) : HardStuff(stuff)
{
    minAngle_ = minAngle;
    maxAngle_ = maxAngle;
}

bool Disk::isTouched(Ball *ball) const
{
    // abscisse de la balle
    int xb = ball->getPosition().x;
    //ordonné de la balle
    int yb = ball->getPosition().y;
    // Position V8 de la balle par rapport à l'objet comme défini dans la documentation de la fonction ballPosition
    short ballV8 = ballPosition(ball);
    // Distance d'entrée de la balle dans l'objet
    int move;
    // Angle à un coin de l'objet comme défini dans la documentation de la fonction getAngleToStuff
    float angleToStuff;
    // Direction suivante
    float angleDir;
    // Distance entre le centre de la balle et un coin
    float distBC;

    if (ballV8 % 2 == 0)
        angleToStuff = getAngleToStuff(ball, ballV8);

    switch(ballV8) {

    case 0: // Boule en haut à gauche
        distBC = sqrt(pow(xb - stuff_.x, 2) + pow(yb - stuff_.y, 2));
        if (ball->getRadius() > distBC) {
            move = ball->getRadius() - distBC;
            angleDir = ((float) xb / stuff_.width + 2 * ball->getRadius()) * (maxAngle_ - minAngle_) + minAngle_;
            ball->setPosition(xb + 2 * move * cos(angleDir), yb + 2 * move * sin(angleDir));
            ball->setAngle(angleDir);
            return true;
        }
        return false;

    case 2: // Boule en haut à droite
        distBC = sqrt(pow(xb - stuff_.x - stuff_.width, 2) + pow(yb - stuff_.y, 2));
        if (ball->getRadius() > distBC) {
            move = ball->getRadius() - distBC;
            angleDir = ((float) xb / stuff_.width + 2 * ball->getRadius()) * (maxAngle_ - minAngle_) + minAngle_;
            ball->setPosition(xb + 2 * move * cos(angleDir), yb + 2 * move * sin(angleDir));
            ball->setAngle(angleDir);
            return true;
        }
        return false;

    case 4: // Boule en bas à droite
        distBC = sqrt(pow(xb - stuff_.x - stuff_.width, 2) + pow(yb - stuff_.y - stuff_.height, 2));
        if (ball->getRadius() > distBC) {
            move = ball->getRadius() - distBC;
            angleDir = -(M_PI + ball->getAngle() - angleToStuff) + angleToStuff;
            ball->setPosition(xb + 2 * move * cos(angleDir), yb + 2 * move * sin(angleDir));
            ball->setAngle(angleDir);
            return true;
        }
        return false;

    case 6: // Boule en bas à gauche
        distBC = sqrt(pow(xb - stuff_.x, 2) + pow(yb - stuff_.y - stuff_.height, 2));
        if (ball->getRadius() > distBC) {
            move = ball->getRadius() - distBC;
            angleDir = -(M_PI + ball->getAngle() - angleToStuff) + angleToStuff;
            ball->setPosition(xb + 2 * move * cos(angleDir), yb + 2 * move * sin(angleDir));
            ball->setAngle(angleDir);
            return true;
        }
        return false;

    case 1: // Boule en haut au milieu
        if (ball->getRadius() > yb - stuff_.y) {
            move = yb + ball->getRadius() - stuff_.y;
            angleDir = ((float) xb / stuff_.width + 2 * ball->getRadius()) * (maxAngle_ - minAngle_) + minAngle_;
            ball->setPosition(xb + 2 * move * cos(angleDir), yb + 2 * move * sin(angleDir));
            ball->setAngle(angleDir);
            return true;
        }
        return false;

    case 3: // Boule à droite au milieu
        if (ball->getRadius() > xb - stuff_.x - stuff_.width) {
            move = stuff_.x + stuff_.width + ball->getRadius() - xb;
            ball->setPosition(xb + 2 * move, yb);
            ball->setAngle(-M_PI * ball->getAngle() + M_PI);
            return true;
        }
        return false;

    case 5: // Boule en bas au milieu
        if (ball->getRadius() > stuff_.y + stuff_.height - yb) {
            move = stuff_.y + stuff_.height + ball->getRadius() - yb;
            ball->setPosition(xb, yb + 2 * move);
            ball->setAngle(-ball->getAngle());
            return true;
        }
        return false;

    case 7: // Boule à gauche au milieu
        if (ball->getRadius() > stuff_.x - xb) {
            move = xb + ball->getRadius() - stuff_.x;
            ball->setPosition(xb - 2 * move, yb);
            ball->setAngle(-M_PI * ball->getAngle() + M_PI);
            return true;
        }
        return false;

    }

    return false;
}

