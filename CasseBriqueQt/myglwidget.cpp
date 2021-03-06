#define _USE_MATH_DEFINES

#include "myglwidget.h"

using namespace cv;

// Declarations des constantes
/*
const unsigned int WIN_WIDTH  = 700;
const unsigned int WIN_HEIGHT = 700;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;
*/
const unsigned int WIN_WIDTH  = 15;
const unsigned int WIN_HEIGHT = 6;
const float MAX_DIMENSION     = 200.0f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    //setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 12.0f;
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();

    model_ = new Model();
    qDebug()<<"On a fait le model"<<endl;
    detection_ = new Detection();
    qDebug()<<"Tout a été créé"<<endl;
}

// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0, 0, 0, 1);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
}

// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Système de coordonnées
    if(width != 0){
        //glOrtho(-MAX_DIMENSION, MAX_DIMENSION,-6.0,6.0,0.0,10.0);
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);
        //glOrtho(0.0,30.0,0.0,30.0,-5.0,5.0);
    }

    glMatrixMode(GL_MODELVIEW);

    //Réinitialisation
    glLoadIdentity();
}

// Fonction d'affichage
void MyGLWidget::paintGL()
{
    Point vect;
    int sensibilite = 5;
    bool lol = true;
    if(lol){
        // Acquisition de la caméra
        qDebug()<<"Et ca va draw une image"<<endl;
        vect = detection_->drawImage();
        qDebug()<<"Et ca draw une image"<<endl;
        //cerr<<vect.x<<"   "<<vect.y<<endl;

        if(vect.x>sensibilite){cerr<<"droite  "<<vect.x<<endl;}
        else if(vect.x<-sensibilite){cerr<<"gauche  "<<vect.x<<endl;}
        else{cerr<<"Pas bouger"<<endl;}
    }


    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definition de la matrice modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Caméra / Cible / Vecteur vertical
    gluLookAt(0.0,0.0,10,
              0.0,0.0,0.0,
              0.0,-1.0,0.0);

    model_->move(vect.x);
    model_->drawWall();
    model_->drawBrick();
    model_->drawDisk();
    model_->drawBall();

    //model_->updateGame(m_TimeElapsed);

}
