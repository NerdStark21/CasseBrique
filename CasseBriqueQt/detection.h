#ifndef DETECTION_H
#define DETECTION_H

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QTimer>
#include <QDebug>

#include <cstdio>
#include <iostream>

using namespace cv;
using namespace std;

class Detection
{
private:
    int frameWidth_;
    int frameHeight_;
    VideoCapture cap_;

public:
    Detection();
    Point drawImage();
};

#endif // DETECTION_H
