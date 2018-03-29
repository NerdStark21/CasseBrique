#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QApplication>
#include <QDesktopWidget>
#include <QtOpenGL/QGLWidget>
#include <QDebug>
#include <GL/glu.h>

class MyGLWidget : public QGLWidget{
    Q_OBJECT

public:
    MyGLWidget(QWidget * parent = nullptr);

protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

private:
    int width_;
    int height_;
};


#endif // MYGLWIDGET_H
