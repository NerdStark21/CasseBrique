#include "wall.h"

Wall::Wall(Rect stuff, bool isDestructive) : HardStuff(stuff)
{
    isDestructive_ = isDestructive;
}

GLfloat* Wall::getVertices(){
    GLfloat listVertices[72];
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

    return listVertices;
}
