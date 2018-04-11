#define _USE_MATH_DEFINES

#include "myglwidget.h"

using namespace cv;

// Declarations des constantes
// 1600 - 900
const unsigned int WIN_WIDTH  = 1000;
const unsigned int WIN_HEIGHT = 600;
const float MAX_DIMENSION     = 50.0f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
}

// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    GLfloat coordU[4] = {0, 10, 10, 10};
    GLfloat coordD[4] = {0, 0, 0, 10};
    GLfloat coordL[4] = {0, 0, 0, 10};
    GLfloat coordR[4] = {10, 10, 10, 0};

    model_ = new Model();

    model_->createWall(coordU, false);
    model_->createWall(coordD, true);
    model_->createWall(coordR, false);
    model_->createWall(coordL, false);
}

// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    width_ = width;
    height_ = height;

    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width),
                MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f,
                MAX_DIMENSION * 2.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT);

    for(unsigned int k=0;k<4;k++){

    }
    glEnableClientState(GL_VERTEX_ARRAY); // Active le tableau permettant de définir les vertices
    glVertexPointer(2, GL_FLOAT, 0, vertices); // 2 coordonnées pour chaque vertex
    glDrawArrays(GL_LINES, 0, 3*1); // Dessine 2 triangles ayant 3 vertices chacun
    glDisableClientState(GL_VERTEX_ARRAY); // Désactive le tableau


    // Definition de la position de la camera
    // Caméra / Cible / Vecteur vertical
    glLoadIdentity();
    gluLookAt(-10, 0, 0, 0, 0, 0, 0, 0, 1);
}
