#ifndef DISK_H
#define DISK_H

#include "hardstuff.h"

class Disk : public HardStuff
{
private:
    int minAngle_;    // Minimum des angles de rebond
    int maxAngle_;    // Maximum des angles de rebond

public:
    Disk(Rect stuff, int minAngle, int maxAngle);

    // Les fonctions abstraites de HardStuff
    void updateBall(Ball * ball, const float time) const override;
};

#endif // DISK_H
