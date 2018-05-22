#include "detection.h"

using namespace cv;
using namespace std;

Detection::Detection()
{
    frameWidth_=320;
    frameHeight_=240;

    VideoCapture cap(0); // open the default camera
    cap_ = cap;

    cap_.set(CV_CAP_PROP_FRAME_WIDTH,frameWidth_);
    cap_.set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight_);

    if(!cap_.isOpened())  // check if we succeeded
    {
        cerr<<"Error openning the default camera"<<endl;
    }

    // Init output window
    namedWindow("WebCam",1);

    drawImage();
}

Point Detection::drawImage(){
    int subImageWidth=100;
    int subImageHeight=100;
    int templateWidth=25;
    int templateHeight=25;
    Rect workingRect((frameWidth_-subImageWidth)/2,frameHeight_/2+(frameHeight_/2-subImageHeight)/2,subImageWidth,subImageHeight);
    Rect templateRect((workingRect.width-templateWidth)/2,(workingRect.height-templateHeight)/2,templateWidth,templateHeight);
    Point workingCenter(workingRect.x+subImageWidth/2,workingRect.y+subImageHeight/2);

    Mat frame1,frame2,frameRect1,frameRect2;

    // Get frame1
    cap_ >> frame1;
    // Mirror effect
    cv::flip(frame1,frame1,1);
    // Extract rect1 and convert to gray
    cv::cvtColor(Mat(frame1,workingRect),frameRect1,COLOR_BGR2GRAY);
    //Mat(frame1,rect).copyTo(frameRect1);

    // Create the matchTemplate image result
    Mat resultImage;    // to store the matchTemplate result
    int result_cols =  frame1.cols-templateWidth  + 1;
    int result_rows = frame1.rows-templateHeight + 1;
    resultImage.create( result_cols, result_rows, CV_32FC1 );

    // Init output window
    namedWindow("WebCam",1);

    QTimer timer;
    // Il y aura un quart de seconde entre deux acquisitions pour avoir un delta potable
    timer.start(100);

    // Get frame2
    cap_ >> frame2;
    // Mirror effect
    cv::flip(frame2,frame2,1);
    // Extract working rect in frame2 and convert to gray
    cv::cvtColor(Mat(frame2,workingRect),frameRect2,COLOR_BGR2GRAY);

    // Extract template image in frame1
    Mat templateImage(frameRect1,templateRect);
    // Do the Matching between the working rect in frame2 and the templateImage in frame1
    matchTemplate( frameRect2, templateImage, resultImage, TM_CCORR_NORMED );
    // Localize the best match with minMaxLoc
    double minVal; double maxVal; Point minLoc; Point maxLoc;
    minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);
    // Compute the translation vector between the origin and the matching rect
    Point vect(maxLoc.x-templateRect.x,maxLoc.y-templateRect.y);

    // Draw green rectangle and the translation vector
    rectangle(frame2,workingRect,Scalar( 0, 255, 0),2);
    Point p(workingCenter.x+vect.x,workingCenter.y+vect.y);
    arrowedLine(frame2,workingCenter,p,Scalar(255,255,255),2);

    // Display frame2
    imshow("WebCam", frame2);

    // Swap matrixes
    swap(frameRect1,frameRect2);
    // the camera will be deinitialized automatically in VideoCapture destructor
    return vect;
}
