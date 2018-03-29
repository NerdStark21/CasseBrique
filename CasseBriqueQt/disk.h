#ifndef DISK_H
#define DISK_H

#include "hardstuff.h"

class Disk : public HardStuff
{
public:
    Disk();
private:
    int angleScale[2];      //Min et max des angles de rebond
};

#endif // DISK_H
