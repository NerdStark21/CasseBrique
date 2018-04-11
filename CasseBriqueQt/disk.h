#ifndef DISK_H
#define DISK_H

#include "hardstuff.h"

class Disk : public HardStuff
{
private:
    int minAngle_; // Minimum des angles de rebond
    int maxAngle_; // Maximum des angles de rebond

public:
    Disk(Rect stuff, int minAngle, int maxAngle);

    // Les fonctions abstraites de HardStuff
    virtual bool isTouched(const Ball *) const;
    virtual void updateAngle(Ball *) const;
    virtual void updatePosition(Ball *) const;
};

#endif // DISK_H
