#ifndef PLAYER_H
#define PLAYER_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class Player{
private:
    int score_;
    int nbBall_;

public:
    Player Player();
    int getScore(){return score_;}
    int getNbBall(){return nbBall_;}
    void addScore(int add){score_ += add;}
}

#endif // PLAYER_H
