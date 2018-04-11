#include "model.h"

using namespace std;

Model::Model()
{
    disk_ = Disk(Rect(10, 10, 5, 1));
    state_ = 0;
}

void Model::updateGame(const float time)
{
    // Gestion de la colision des murs
    vector<Wall>::iterator itw;
    for (itw = walls_.begin(); itw != walls_.end(); itw++) {
        if (itw->isTouched(&ball_)) {
            itw->updateBall(&ball_);
            if (itw->getIsDestructive()) {
                state = 0;
            }
        }
    }
    delete itw;

    // Gestion de la colision des briques
    list<Brick>::iterator itb;
    for (itb = bricks_.begin(); itb != bricks_.end(); itb++) {
        if (itb->isTouched(&ball)) {
            itb->updateBall(&ball);
            player_.addScore(itb->getPoints());
            bricks_.remove(itb);
        }
    }
    delete itb;

    // Gestion de la colision du disque
    if (disk_.isTouched(&ball)) {
        disk_.updateBall(&ball);
    }
}
