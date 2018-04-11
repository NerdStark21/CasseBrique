#ifndef DISK_H
#define DISK_H

#include "hardstuff.h"

class Disk : public HardStuff
{
private:
    int angleScale[2]; // Minimum et maximum des angles de rebond

public:
    Disk();

    // Les fonctions abstraites de HardStuff
    virtual bool isTouched(const Ball *) const;
    virtual void updateAngle(Ball *) const;
    virtual void updatePosition(Ball *) const;
};

#endif // DISK_H
