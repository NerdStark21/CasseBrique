#include "detection.h"

Detection::Detection()
{
    VideoCapture cap(0); // open the default camera

    if(!cap.isOpened())  // check if we succeeded
    {
        cerr << "Error openning the default camera" << endl;
        return -1;
    }
}
