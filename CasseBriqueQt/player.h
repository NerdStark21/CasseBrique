#ifndef PLAYER_H
#define PLAYER_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class Player{
private:
    int score_;    // Le score du joueur
    int nbBall_;    // Le nombre de balles restantes au joueur

public:
    Player();
    int getScore() const { return score_; }
    int getNbBall() const { return nbBall_; }
    void addScore(const int add) { score_ += add; }
};

#endif // PLAYER_H
