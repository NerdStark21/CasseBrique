#ifndef DISK_H
#define DISK_H

#include "hardstuff.h"

class Disk : public HardStuff
{
private:
    int angleScale[2]; // Minimum et maximum des angles de rebond

public:
    Disk();

    virtual bool isTouched(const Ball * ball) const;
    virtual void updateAngle(Ball * ball) const;
    virtual void updatePosition(Ball * ball) const;
};

#endif // DISK_H
