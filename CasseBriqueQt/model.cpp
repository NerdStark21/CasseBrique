#include "model.h"

using namespace std;

Model::Model()
{
    disk_ = Disk(Rect(10, 10, 5, 1), 10, 20);
    state_ = 0;

    // Création de tous les murs
    Rect coordU(0, 10, 10, 1);
    Rect coordD(0, 0, 10, 1);
    Rect coordL(0, 0, 1, 10);
    Rect coordR(0, 10, 1, 10);

    Wall wallU(coordU, false);
    Wall wallD(coordD, true);
    Wall wallL(coordL, false);
    Wall wallR(coordR, false);

    walls_.push_back(wallU);
    walls_.push_back(wallD);
    walls_.push_back(wallL);
    walls_.push_back(wallR);
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
        //walls_ = walls;
        //bricks_ = bricks;
    }

    // Création du disk

}

void Model::setWall(){
    // On va faire afficher les 4 murs
    //Wall wall(Rect(), true);

    for(unsigned int k=0;k<4;k++){
        qDebug()<<"Ca marche !";
        Wall wall = getWall(k);
        qDebug()<<"Ca marche !";
        GLfloat* vertices = wall.getVertices();
        qDebug()<<"Ca marche !";
        GLfloat listVertices[72];
        for(int k=0;k<72;k++){
            listVertices[k] = *(vertices + k);
        }
        qDebug()<<"Ca marche !";
        glEnableClientState(GL_VERTEX_ARRAY); // Active le tableau permettant de définir les vertices
        glVertexPointer(3, GL_FLOAT, 0, listVertices); // 3 coordonnées pour chaque vertex
        glDrawArrays(GL_QUADS, 0, 4*1);
        glDisableClientState(GL_VERTEX_ARRAY); // Désactive le tableau
        qDebug()<<"Ca marche !";
    }
}
