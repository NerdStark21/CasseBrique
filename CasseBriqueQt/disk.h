#ifndef DISK_H
#define DISK_H

#include "hardstuff.h"

class Disk : public HardStuff
{
private:
    int minAngle_;    // Minimum des angles de rebond
    int maxAngle_;    // Maximum des angles de rebond

public:
    Disk();
    Disk(Rect stuff, int minAngle, int maxAngle);

    // Les fonctions abstraites de HardStuff
    bool isTouched(Ball * ball) const override;
    void move(int deplacement);
    void drawDisk();
};

#endif // DISK_H
