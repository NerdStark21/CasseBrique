#ifndef HARDSTUFF_H
#define HARDSTUFF_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "ball.h"

using namespace cv;

class HardStuff
{
protected:
    Rect stuff;

public:
    HardStuff();
    virtual bool isTouched(Ball*) = 0;
    virtual void newAngle(Ball*) = 0;
};

#endif // HARDSTUFF_H
