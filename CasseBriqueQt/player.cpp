#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "player.h"

using namespace cv;
using namespace std;

Player Player(){
    score_ = 0;
    nbBall_ = 3;    //Le joueur a 3 vies initialement
}
