#include "hardstuff.h"

float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

HardStuff::HardStuff(Rect stuff)
{
    stuff_ = stuff;
    depth_ = 7;
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
    throw new Exception();
}

bool HardStuff::isTouched(const Ball *ball) const
{
    int xb = ball->getPosition().x;
    int yb = ball->getPosition().y;
    short ballPos = ballPosition(ball);

    switch(ballPos) {

    case 0: // Boule en haut à gauche
        return ball->getRadius() > distance(xb, yb, stuff_.x, stuff_.y);

    case 2: // Boule en haut à droite
        return ball->getRadius() > distance(xb, yb, stuff_.x + stuff_.width, stuff_.y);

    case 4: // Boule en bas à droite
        return ball->getRadius() > distance(xb, yb, stuff_.x + stuff_.width, stuff_.y + stuff_.height);

    case 6: // Boule en bas à gauche
        return ball->getRadius() > distance(xb, yb, stuff_.x, stuff_.y + stuff_.height);

    case 1: // Boule en haut au milieu
        return ball->getRadius() > yb - stuff_.y;

    case 3: // Boule à droite au milieu
        return ball->getRadius() > xb - stuff_.x - stuff_.width;

    case 5: // Boule en bas au milieu
        return ball->getRadius() > stuff_.y + stuff_.height - yb;

    case 7: // Boule à gauche au milieu
        return ball->getRadius() > stuff_.x - xb;

    }
}
