#include "model.h"

using namespace std;

Model::Model()
{
    qDebug()<<"Création du model"<<endl;
    //disk_ = Disk(Rect(10, 10, 5, 1), 10, 20);
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
    delete &itw;

    // Gestion de la colision des briques
    vector<Brick>::iterator itb;
    for (itb = bricks_.begin(); itb != bricks_.end(); itb++) {
        if (itb->isTouched(&ball_)) {
            player_.addScore(itb->getPoints());
            bricks_.erase(itb);
        }
    }
    delete &itb;

    // Gestion de la colision du disque
    disk_.isTouched(&ball_);

}

/*
void Model::drawWall() {
    // On va faire afficher les 4 murs
    //Wall wall(Rect(), true);

    for(unsigned int k = 0 ; k < 4 ; k++){
        qDebug()<<"Ca marche !";
        Wall wall = getWall(k);
        qDebug()<<"Ca marche !";
        GLfloat vertices[72];
        wall.getVertices(vertices);
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
}*/

/*
void Model::drawWall() {

    vector<Wall>::iterator it;
    for (it = walls_.begin(); it != walls_.end(); it++) {
        GLfloat vertices[72];
        it->getVertices(vertices);

        glPushMatrix();
        glLoadIdentity();
        glBegin(GL_QUADS);
        glColor3ub(15, 15, 15);
        for (short f = 0; f < 6; f++) { // Les faces du parallélépipède rectangle
            for (short s = 0; s < 4; s++) { // Les sommets de la face
                glVertex3f(vertices[6 * f + 4 * s], vertices[6 * f + 4 * s + 1], vertices[6 * f + 4 * s + 2]);
            }
        }
    }
}*/

void Model::ballLost()
{
    player_.ballLost();
}

void Model::gameLost()
{
    state_ = 2;
}
