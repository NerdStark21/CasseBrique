#ifndef HARDSTUFF_H
#define HARDSTUFF_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class HardStuff
{
protected:
    virtual Rect stuff;

public:
    HardStuff();
    virtual bool isTouched(Ball*);
    virtual void updateAngle(Ball*);
};

#endif // HARDSTUFF_H
