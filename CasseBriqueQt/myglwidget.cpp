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
    detection_ = new Detection();
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
    int sensibilite = 5;
    bool lol = true;
    if(lol){
        // Acquisition de la caméra
        Point vect = detection_->drawImage();
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
    /*
    bool affichageRepere = false;
    if(affichageRepere){
        // Affichage d'un repère
        glBegin(GL_LINES);
        glColor3ub(255,0,0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(-10.0, 0.0, 0.0);

        glColor3ub(0,255,0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, -10.0, 0.0);

        glColor3ub(0,0,255);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, -10.0);
        glEnd();
    }

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    glColor3ub(255,0,255);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glColor3ub(255,0,0);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glColor3ub(0,255,255);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);

    glColor3ub(0,255,0);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glColor3ub(255,255,0);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);



    glEnd();
    // Matrice de translation
    */

    model_->drawWall();
    model_->drawBrick();

    //glPopMatrix();
}
