#ifndef DISK_H
#define DISK_H

#include "hardstuff.h"

class Disk : public HardStuff
{
private:
    int angleScale[2]; // Minimum et maximum des angles de rebond

public:
    Disk();
};

#endif // DISK_H
