#ifndef BALL_H
#define BALL_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class Ball
{
private:
    Point position_;    // Position de la balle. L'origine est en bas à gauche et les axes sont usuels.
    float radius_;    // Rayon de la balle
    int speed_;    // Vitesse de la balle en pixels par seconde
    float angle_;    // Direction de la balle en radian

public:
    Ball();
    Ball(int x, int y, float radius, int speed, float angle);
    Point getPosition() const { return position_; }
    float getRadius() const { return radius_; }
    int getSpeed() const { return speed_; }
    float getAngle() const { return angle_; }
    void setAngle(const float angle) { angle_ = angle; }
    void setPosition(const int x, const int y);

};

#endif // BALL_H
