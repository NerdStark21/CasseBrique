# configuration Qt
QT       += core gui opengl widgets
TEMPLATE  = app

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}

TARGET = CasseBriqueQt

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    hardstuff.cpp \
    brick.cpp \
    disk.cpp \
    wall.cpp \
    ball.cpp \
    player.cpp \
    myglwidget.cpp \
    model.cpp

HEADERS += \
    hardstuff.h \
    brick.h \
    disk.h \
    wall.h \
    ball.h \
    player.h \
    myglwidget.h \
    model.h

FORMS +=

INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include
