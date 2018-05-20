#include "model.h"

using namespace std;

Model::Model()
{
    disk_ = Disk(Rect(10, 10, 5, 1));
    state_ = 0;
}

void Model::updateGame(const float time)
{
    // Avancement de la balle
    int newX = ball_.getPosition().x + ball_.getSpeed() * time * cos(ball_.getAngle());
    int newY = ball_.getPosition().y + ball_.getSpeed() * time * sin(ball_.getAngle());
    // TODO : l'attribut speed de ball_ est en pixels par secondes. Il faut vérifier l'unité de time pour que ça colle.
    ball_.setPosition(newX, newY);

    // Gestion de la colision des murs
    vector<Wall>::iterator itw;
    for (itw = walls_.begin(); itw != walls_.end(); itw++) {
        if (itw->isTouched(&ball_)) {
            if (itw->getIsDestructive()) {
                ballLost();
            }
        }
    }
    delete itw;

    // Gestion de la colision des briques
    list<Brick>::iterator itb;
    for (itb = bricks_.begin(); itb != bricks_.end(); itb++) {
        if (itb->isTouched(&ball_)) {
            player_.addScore(itb->getPoints());
            bricks_.remove(itb);
        }
    }
    delete itb;

    // Gestion de la colision du disque
    disk_.isTouched(&ball_);
}

void Model::ballLost()
{
    player_.ballLost();
}

void Model::gameLost()
{

}
