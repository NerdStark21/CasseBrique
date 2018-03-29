#define _USE_MATH_DEFINES

#include "myglwidget.h"

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

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 12.0f;
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();
}

// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);   // Reglage de la couleur de fond

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

    // Definition de la position de la camera
    // Caméra / Cible / Vecteur vertical
    glLoadIdentity();
    gluLookAt(-10, 0, 0,
              0, 0, 0,
              0, 0, 1);
}
