#include "model.h"

using namespace std;

Model::Model(vector<Rect> walls, list<Brick> bricks, Rect disk)
{
    walls_ = walls;
    bricks_ = bricks;
    disk_ = new Disk(disk);
}
