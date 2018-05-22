#include "model.h"

using namespace std;

Model::Model()
{
    qDebug()<<"Création du model"<<endl;
    state_ = 0;
    int cote = 250;
    int epaisseur = 5;
    // Création de tous les murs
    Rect coordU(-cote/2, cote/2, cote, epaisseur);
    Rect coordD(-cote/2, -cote/2, cote, epaisseur);
    Rect coordL(-cote/2, -cote/2, epaisseur, cote);
    Rect coordR(cote/2, -cote/2, epaisseur, cote);

    Wall wallU(coordU, false);
    Wall wallD(coordD, true);
    Wall wallL(coordL, false);
    Wall wallR(coordR, false);

    walls_.push_back(wallU);
    walls_.push_back(wallD);
    walls_.push_back(wallL);
    walls_.push_back(wallR);

    int largeur = 6;
    // Création de toutes les briques
    for(int ligne=0;ligne<12;ligne++){
        for(int colonne=0;colonne<10;colonne++){
            Brick brick(Rect(colonne*(3*largeur+5) -110, 110 - ligne*(largeur+3), 3*largeur, largeur));
            //Brick brick(Rect(colonne*25 -110, 110 - ligne*10, 21, 7));
            bricks_.push_back(brick);
        }
    }

    Rect coordDisk(-20, -cote/2+10, 40, 10);
    disk_ = Disk(coordDisk, -45, 45);

    ball_ = Ball(0, 20, 10, 20, -0.7);

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
            qDebug() << "Coucou je suis là" << endl;
            if (itw->getIsDestructive()) {
                ballLost();
            }
        }
    }
    delete &itw;

    // Gestion de la colision des briques
    vector<Brick>::iterator itb;
    for (itb = bricks_.begin(); itb != bricks_.end(); itb++) {
        if (!itb->getIsDestroyed() && itb->isTouched(&ball_)) {
            player_.addScore(itb->getPoints());
            itb->destroy();
        }
    }
    delete &itb;

    // Gestion de la colision du disque
    disk_.isTouched(&ball_);

}

void Model::ballLost()
{
    player_.ballLost();
}

void Model::gameLost()
{
    state_ = 2;
}

void Model::drawWall()
{
    vector<Wall>::iterator itw;
    for (itw = walls_.begin(); itw != walls_.end(); itw++)
        itw->drawWall();
}

void Model::drawBrick()
{
    vector<Brick>::iterator itw;
    for (itw = bricks_.begin(); itw != bricks_.end(); itw++) {
        if (!itw->getIsDestroyed())
            itw->drawBrick();
    }
}

void Model::drawBall()
{
    GLUquadric* quadrique = gluNewQuadric();
    glPushMatrix();
    glColor3ub(255, 150, 130);
    glTranslatef(ball_.getPosition().x, ball_.getPosition().y, - ball_.getRadius());
    gluQuadricDrawStyle(quadrique, GLU_FILL);
    gluSphere(quadrique, ball_.getRadius(), 20, 20);
    gluDeleteQuadric(quadrique);
    glPopMatrix();
}

