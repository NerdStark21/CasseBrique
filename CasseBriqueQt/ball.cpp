#include "ball.h"

Ball::Ball(float radius, int speed, float angle)
{
    position_ = Point(9, 5);
    radius_ = radius;
    speed_ = speed;
    angle_ = angle;
}
