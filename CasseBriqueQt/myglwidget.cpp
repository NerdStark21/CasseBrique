#define _USE_MATH_DEFINES

#include "myglwidget.h"

using namespace cv;

// Declarations des constantes
const unsigned int WIN_WIDTH  = 700;
const unsigned int WIN_HEIGHT = 700;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 12.0f;
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();

    model_ = new Model();
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
    glViewport(	0, 0, WIN_WIDTH, WIN_HEIGHT);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(80.0, (GLdouble)WIN_WIDTH/(GLdouble)WIN_WIDTH, 0.1, 12.0);
    glFrustum(-2, 2, -2, 2, 4, 150);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Fonction d'affichage
void MyGLWidget::paintGL()
{
<<<<<<< HEAD
=======
    qDebug()<<"Paint !"<<endl;
>>>>>>> De la merde
    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definition de la matrice modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Caméra / Cible / Vecteur vertical
<<<<<<< HEAD
    gluLookAt(-5, -5, -13,
=======
    glPushMatrix();
    gluLookAt(0, 0, -10,
>>>>>>> De la merde
              0, 0, 0,
              0, 1, 0);

    bool affichageRepere = true;
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

    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(0,0,255); glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    glColor3ub(255,0,255); glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glColor3ub(255,0,0); glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glColor3ub(0,255,255); glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);

    glColor3ub(0,255,0); glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glColor3ub(255,255,0); glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    //model_->drawWall();
    //model_->drawBrick();
}
