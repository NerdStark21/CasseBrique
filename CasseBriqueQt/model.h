#ifndef MODEL_H
#define MODEL_H

#include "brick.h"
#include "disk.h"
#include "player.h"
#include "wall.h"

#include <vector>
#include <List>

using namespace std;

class Model
{
private:
    vector<Wall> walls_; // Contient les 4 murs du jeu
    list<Brick> bricks_; // Contient toutes les briques du jeu
    Disk disk_; // Contient le disque du jeu
    Ball ball_; // Contient la balle du jeu
    Player player_; // Contient les informations sur le joueur

public:
    Model(vector<Rect> walls, list<Brick> bricks, Rect disk);

    /**
     * @brief updateGame
     *  Cette fonction actualise le jeu après un certain temps sans actualisation
     * @param time
     *  temps écoulé depuis la dernière actualisation
     */
    void updateGame(const float time);
    void createWall(Rect rect, bool isdestructive){walls_.push_back(Wall(rect, isdestructive));}
    Wall getWall(unsigned int k){return walls_.at(k);}
};

#endif // MODEL_H
