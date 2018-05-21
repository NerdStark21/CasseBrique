#include "ball.h"

Ball::Ball()
{
    position_ = Point(9, 5);
    radius_ = 15;
    speed_ = 30;
    angle_ = 3.141592 / 4;
}

Ball::Ball(float radius, int speed, float angle)
{
    position_ = Point(9, 5);
    radius_ = radius;
    speed_ = speed;
    angle_ = angle;
}

void Ball::setPosition(const int x, const int y)
{
    position_ = Point(x, y);
}
