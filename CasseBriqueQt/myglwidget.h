#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QDesktopWidget>
#include <QtOpenGL>
#include <QDebug>

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
}


#endif // MYGLWIDGET_H
