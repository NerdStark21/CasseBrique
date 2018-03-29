#ifndef BALL_H
#define BALL_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class Ball
{
    Point position_; // Position de la balle. L'origine est en bas à gauche et les axes sont usuels.
    float radius_; // Rayon de la balle
    int speed_; // Vitesse de la balle en pixels par seconde
    float angle_; // Direction de la balle

public:
    Ball();
    Point getPosition() { return position_; }
    void setAngle(float angle) { angle_ = angle; }

};

#endif // BALL_H