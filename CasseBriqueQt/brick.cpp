#include "brick.h"

Brick::Brick(Rect stuff) : HardStuff(stuff)
{
    points_ = 1;
    isDestroyed_ = false;
}

void Brick::drawBrick(){

    glPushMatrix();
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(15, 15, 15);
    /*
    for (short f = 0; f < 6; f++) { // Les faces du parallélépipède rectangle
        for (short s = 0; s < 4; s++) { // Les sommets de la face
            glVertex3f(vertices[6 * f + 4 * s], vertices[6 * f + 4 * s + 1], vertices[6 * f + 4 * s + 2]);
        }
    }*/

    glVertex3f(stuff_.x,stuff_.y, 0);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y, 0);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, 0);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, 0);

    glVertex3f(stuff_.x + stuff_.width,stuff_.y, 0);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, 0);

    glVertex3f(stuff_.x + stuff_.width,stuff_.y, depth_);
    glVertex3f(stuff_.x,stuff_.y, depth_);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, depth_);

    glVertex3f(stuff_.x,stuff_.y, depth_);
    glVertex3f(stuff_.x,stuff_.y, 0);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, 0);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, depth_);

    glVertex3f(stuff_.x,stuff_.y + stuff_.height, 0);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, 0);

    glVertex3f(stuff_.x,stuff_.y, 0);
    glVertex3f(stuff_.x,stuff_.y, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y, 0);

    glEnd();
    glPopMatrix();

    /*
    //Vertices avec array
    glEnableClientState(GL_VERTEX_ARRAY); // Active le tableau permettant de définir les vertices
    GLfloat vertices[72];
    getVertices(vertices);
    glVertexPointer(3, GL_FLOAT, 0, vertices); // 3 coordonnées pour chaque vertex
    glEnableClientState(GL_COLOR_ARRAY);
    //Générateur de couleur aléatoire pour chaque vertice
    GLfloat colors[8];
    for(int k=0;k<8;k++){
        colors[k] = rand()/(float)RAND_MAX;
    }
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_LINE_LOOP, 0, 4); // Dessine 6 triangles ayant 4 vertices chacun
    glDisableClientState(GL_COLOR_ARRAY); // Désactive le tableau
    glDisableClientState(GL_VERTEX_ARRAY); // Désactive le tableau
    */
}

void Brick::getVertices(GLfloat listVertices[72]){
    // Les groupes de 3 sont les coord xyz
    // Carré 1
    listVertices[0] = stuff_.x;
    listVertices[1] = stuff_.y;
    listVertices[2] = 0;

    listVertices[3] = stuff_.x + stuff_.width;
    listVertices[4] = stuff_.y;
    listVertices[5] = 0;

    listVertices[6] = stuff_.x + stuff_.width;
    listVertices[7] = stuff_.y + stuff_.height;
    listVertices[8] = 0;

    listVertices[9] = stuff_.x;
    listVertices[10] = stuff_.y + stuff_.height;
    listVertices[11] = 0;

    // Carré 2
    listVertices[12] = stuff_.x + stuff_.width;
    listVertices[13] = stuff_.y;
    listVertices[14] = 0;

    listVertices[15] = stuff_.x + stuff_.width;
    listVertices[16] = stuff_.y;
    listVertices[17] = depth_;

    listVertices[18] = stuff_.x + stuff_.width;
    listVertices[19] = stuff_.y + stuff_.height;
    listVertices[20] = depth_;

    listVertices[21] = stuff_.x;
    listVertices[22] = stuff_.y + stuff_.height;
    listVertices[23] = 0;

    // Carré 3
    listVertices[24] = stuff_.x + stuff_.width;
    listVertices[25] = stuff_.y;
    listVertices[26] = depth_;

    listVertices[27] = stuff_.x;
    listVertices[28] = stuff_.y;
    listVertices[29] = depth_;

    listVertices[30] = stuff_.x;
    listVertices[31] = stuff_.y + stuff_.height;
    listVertices[32] = depth_;

    listVertices[33] = stuff_.x + stuff_.width;
    listVertices[34] = stuff_.y + stuff_.height;
    listVertices[35] = depth_;

    // Carré 4
    listVertices[36] = stuff_.x;
    listVertices[37] = stuff_.y;
    listVertices[38] = depth_;

    listVertices[39] = stuff_.x;
    listVertices[40] = stuff_.y;
    listVertices[41] = 0;

    listVertices[42] = stuff_.x;
    listVertices[43] = stuff_.y + stuff_.height;
    listVertices[44] = 0;

    listVertices[45] = stuff_.x;
    listVertices[46] = stuff_.y + stuff_.height;
    listVertices[47] = depth_;

    // Carré 5
    listVertices[48] = stuff_.x;
    listVertices[49] = stuff_.y + stuff_.height;
    listVertices[50] = 0;

    listVertices[51] = stuff_.x;
    listVertices[52] = stuff_.y + stuff_.height;
    listVertices[53] = depth_;

    listVertices[54] = stuff_.x + stuff_.width;
    listVertices[55] = stuff_.y + stuff_.height;
    listVertices[56] = depth_;

    listVertices[57] = stuff_.x + stuff_.width;
    listVertices[58] = stuff_.y + stuff_.height;
    listVertices[59] = 0;

    // Carré 6
    listVertices[60] = stuff_.x;
    listVertices[61] = stuff_.y;
    listVertices[62] = 0;

    listVertices[63] = stuff_.x;
    listVertices[64] = stuff_.y;
    listVertices[65] = depth_;

    listVertices[66] = stuff_.x + stuff_.width;
    listVertices[67] = stuff_.y;
    listVertices[68] = depth_;

    listVertices[69] = stuff_.x + stuff_.width;
    listVertices[70] = stuff_.y;
    listVertices[71] = 0;
}
