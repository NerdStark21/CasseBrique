#define _USE_MATH_DEFINES

#include "myglwidget.h"
#include <GL/glu.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 400;
const unsigned int WIN_HEIGHT = 400;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;
int z = -10;
bool zBufferActivated = true;
double angleX = 0;
double angleY = 1;
double angleZ = 0;
double phi = 90;
double theta = 0;


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
    glClearColor(0.5, 0.5, 0.5, 1);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
}


// Test de trackball inachevé
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(	0, 0, 400, 400);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    if(zBufferActivated)
    {
        glEnable(GL_DEPTH_TEST);
    }
    else{
        glDisable(GL_DEPTH_TEST);
    }

    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definition de la matrice modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, (GLdouble)WIN_WIDTH/(GLdouble)WIN_WIDTH, 0.1, 12.0);

    // Caméra / Cible / Vecteur vertical
    glPushMatrix();
    gluLookAt(0, 0, z,
              0, 0, 0,
              angleX, angleY, angleZ);


    // ----------------------------------------------------------------
    // Affichage du cube
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3f(3.0, 3.0, -5.0);
    glVertex3f(1.0, 3.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glVertex3f(3.0, 1.0, -5.0);

    glColor3ub(255,0,255);
    glVertex3f(3.0, 3.0, -7.0);
    glVertex3f(3.0, 1.0, -7.0);
    glVertex3f(1.0, 1.0, -7.0);
    glVertex3f(1.0, 3.0, -7.0);

    glColor3ub(255,0,0);
    glVertex3f(3.0, 1.0, -7.0);
    glVertex3f(3.0, 1.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glVertex3f(1.0, 1.0, -7.0);

    glColor3ub(0,255,255);
    glVertex3f(3.0, 3.0, -7.0);
    glVertex3f(1.0, 3.0, -7.0);
    glVertex3f(1.0, 3.0, -5.0);
    glVertex3f(3.0, 3.0, -5.0);

    glColor3ub(0,255,0);
    glVertex3f( 1.0, 3.0, -7.0);
    glVertex3f( 1.0, 1.0, -7.0);
    glVertex3f( 1.0, 1.0, -5.0);
    glVertex3f( 1.0, 3.0, -5.0);

    glColor3ub(255,255,0);
    glVertex3f(3.0f, 3.0, -7.0);
    glVertex3f(3.0f, 3.0, -5.0);
    glVertex3f(3.0f, 1.0, -5.0);
    glVertex3f(3.0f, 1.0, -7.0);
    glEnd();

    // ----------------------------------------------------------------

    // ----------------------------------------------------------------
    // Affichage d'un repère
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);

    glColor3ub(0,255,0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);

    glColor3ub(0,0,255);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 10.0);
    glEnd();

    // ----------------------------------------------------------------

    // ----------------------------------------------------------------
    // Affichage de la quadrique
    GLUquadric* quadrique = gluNewQuadric(); //On créé l'objet
    gluQuadricDrawStyle(quadrique, GLU_LINE); //On modifie le style d'affichage
    glPushMatrix(); //On stocke le repere d'origine
    glTranslatef(0, 0, -7);
    gluSphere(quadrique, 1, 10, 10); //On dessine la quadrique
    gluDeleteQuadric(quadrique); //On libere l'espace mémoire
    // ----------------------------------------------------------------
}

void MyGLWidget::mouseMoveEvent(QMouseEvent * event){

    theta = event->x()/400*90;
    phi = event->y()/400*90;

    qDebug() <<theta;
    qDebug() <<phi;

    angleX = cos(phi*3.1415/180)*sin(theta*3.1415/180);
    angleY = sin(phi*3.1415/180);
    angleZ = sin(phi*3.1415/180)*cos(theta*3.1415/180);

    event->accept();
    updateGL();
}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    // Activation/Desactivation du zbuffer
    case Qt::Key_Space:
    {
        zBufferActivated = !zBufferActivated;
        break;
    }

    case Qt::Key_Z:
    {
        z++;
        break;
    }

    case Qt::Key_S:
    {
        z--;
        break;
    }

    case Qt::Key_Right:
    {
        phi = phi - 5;
        break;
    }

    case Qt::Key_Left:
    {
         phi = phi + 5;
         break;
    }

        // Sortie de l'application
    case Qt::Key_Escape:
    {
        close();
        break;
    }

        // Cas par defaut
    default:
    {
        // Ignorer l'evenement
        event->ignore();
        return;
    }
    }
    angleX = cos(phi*3.1415/180);
    angleY = sin(phi*3.1415/180);
    //qDebug() <<angleX;

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}
