#ifndef MODEL_H
#define MODEL_H

#include "brick.h"
#include "disk.h"
#include "player.h"
#include "wall.h"

#include <vector>
#include <List>
#include <qdebug.h>

using namespace std;

class Model
{
private:
    vector<Wall> walls_;    // Contient les 4 murs du jeu
    vector<Brick> bricks_;  // Contient toutes les briques du jeu
    Disk disk_;             // Contient le disque du jeu
    Ball ball_;             // Contient la balle du jeu
    Player player_;         // Contient les informations sur le joueur
    short state_;           // Décrit l'état du jeu (en cours, perdu, gagné)

public:
    Model();

    /**
     * @brief updateGame
     *  Cette fonction actualise le jeu après un certain temps sans actualisation
     * @param time
     *  temps écoulé depuis la dernière actualisation
     */
    void move(int deplacement){disk_.move(deplacement);}
    void updateGame(const float time);
    void ballLost();
    void gameLost();
    void createWall(Rect stuff, bool isDestructive) { walls_.push_back(Wall(stuff, isDestructive)); }
    void createBrick(Rect stuff) { bricks_.push_back(Brick(stuff)); }
    Wall getWall(unsigned int k) { return walls_.at(k); }
    void drawDisk() { disk_.drawDisk(); }
    void drawWall();
    void drawBrick();
    void drawBall();
};

#endif // MODEL_H
