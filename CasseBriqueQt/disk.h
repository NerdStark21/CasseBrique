#ifndef DISK_H
#define DISK_H


class Disk : public HardDisk
{
public:
    Disk();
private:
    int angleScale[2];      //Min et max des angles de rebond
};

#endif // DISK_H
