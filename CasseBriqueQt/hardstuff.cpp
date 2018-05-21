#include "hardstuff.h"

float HardStuff::depth_ = 1.0;

float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

HardStuff::HardStuff()
{
    stuff_ = Rect(0, 0, 0, 0);
}

HardStuff::HardStuff(Rect stuff)
{
    stuff_ = stuff;
}



short HardStuff::ballPosition(const Ball *ball) const
{
    int xb = ball->getPosition().x;
    int yb = ball->getPosition().y;

        // Boule en haut à gauche
    if (xb < stuff_.x && yb < stuff_.y) {
        return 0;
    }
        // Boule en haut à droite
    if (xb > stuff_.x + stuff_.width && yb < stuff_.y) {
        return 2;
    }
        // Boule en bas à droite
    if (xb > stuff_.x + stuff_.width && yb > stuff_.y + stuff_.height) {
        return 4;
    }
        // Boule en bas à gauche
    if (xb < stuff_.x && yb > stuff_.y + stuff_.height) {
        return 6;
    }
        // Boule en haut au milieu
    if (yb < stuff_.y) {
        return 1;
    }
        // Boule à droite au milieu
    if (xb > stuff_.x + stuff_.width) {
        return 3;
    }
        // Boule en bas au milieu
    if (yb > stuff_.y + stuff_.width) {
        return 5;
    }
        // Boule à gauche au milieu
    if (xb < stuff_.x) {
        return 7;
    }

    throw std::logic_error("La fonction ballPosition n'est pas censée arriver ici");
}



float HardStuff::getAngleToStuff(const Ball *ball, short posV8) const
{
    // Les coordonnées du coin
    int xCoin, yCoin;

    switch(posV8) {

    case 0: // Boule en haut à gauche
        xCoin = stuff_.x;
        yCoin = stuff_.y;
        break;

    case 2: // Boule en haut à droite
        xCoin = stuff_.x + stuff_.width;
        yCoin = stuff_.y;
        break;

    case 4: // Boule en bas à droite
        xCoin = stuff_.x + stuff_.width;
        yCoin = stuff_.y + stuff_.height;
        break;

    case 6: // Boule en bas à gauche
        xCoin = stuff_.x;
        yCoin = stuff_.y + stuff_.height;
        break;

    }

    // Les coordonnées du vecteur coin -> centre de la boule
    int xVect = ball->getPosition().x - xCoin;
    int yVect = yCoin - ball->getPosition().y; // On met xCoin - xBoule pour avoir des angles dans le sens trigonométrique
    // La norme du vecteur coin -> centre de la boule
    float normeVect = sqrt(xVect * xVect + yVect * yVect);

    return 2 * atan( yVect / (xVect + normeVect));
}

bool HardStuff::isTouched(Ball *ball) const
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

    if (ballV8 % 2 == 0)
        angleToStuff = getAngleToStuff(ball, ballV8);

    switch(ballV8) {

    case 0: // Boule en haut à gauche
        if (ball->getRadius() > distance(xb, yb, stuff_.x, stuff_.y)) {
            move = ball->getRadius() - distance(xb, yb, stuff_.x, stuff_.y);
            angleDir = -(M_PI + ball->getAngle() - angleToStuff) + angleToStuff;
            ball->setPosition(xb + 2 * move * cos(angleDir), yb + 2 * move * sin(angleDir));
            ball->setAngle(angleDir);
            return true;
        }
        return false;

    case 2: // Boule en haut à droite
        if (ball->getRadius() > distance(xb, yb, stuff_.x + stuff_.width, stuff_.y)) {
            move = ball->getRadius() - distance(xb, yb, stuff_.x + stuff_.width, stuff_.y);
            angleDir = -(M_PI + ball->getAngle() - angleToStuff) + angleToStuff;
            ball->setPosition(xb + 2 * move * cos(angleDir), yb + 2 * move * sin(angleDir));
            ball->setAngle(angleDir);
            return true;
        }
        return false;

    case 4: // Boule en bas à droite
        if (ball->getRadius() > distance(xb, yb, stuff_.x + stuff_.width, stuff_.y + stuff_.height)) {
            move = ball->getRadius() - distance(xb, yb, stuff_.x + stuff_.width, stuff_.y + stuff_.height);
            angleDir = -(M_PI + ball->getAngle() - angleToStuff) + angleToStuff;
            ball->setPosition(xb + 2 * move * cos(angleDir), yb + 2 * move * sin(angleDir));
            ball->setAngle(angleDir);
            return true;
        }
        return false;

    case 6: // Boule en bas à gauche
        if (ball->getRadius() > distance(xb, yb, stuff_.x, stuff_.y + stuff_.height)) {
            move = ball->getRadius() - distance(xb, yb, stuff_.x, stuff_.y + stuff_.height);
            angleDir = -(M_PI + ball->getAngle() - angleToStuff) + angleToStuff;
            ball->setPosition(xb + 2 * move * cos(angleDir), yb + 2 * move * sin(angleDir));
            ball->setAngle(angleDir);
            return true;
        }
        return false;

    case 1: // Boule en haut au milieu
        if (ball->getRadius() > yb - stuff_.y) {
            move = yb + ball->getRadius() - stuff_.y;
            ball->setPosition(xb, yb - 2 * move);
            ball->setAngle(-ball->getAngle());
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

    throw std::logic_error("La fonction ballPosition n'est pas censée arriver ici");
}
