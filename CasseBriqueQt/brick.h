#ifndef BRICK_H
#define BRICK_H


class Brick : public HardStuff
{
public:
    Brick();
    bool isTouched(Ball* ball);
    void updateAngle()
};

#endif // BRICK_H
