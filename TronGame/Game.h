#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "../Settings.h"
#include "../Player.h"

class Game{
    private:
        Grid* grid;
        Player* p1;
        Player* p2;
        int moves;
    
    public:
        Game(Player*, Player*);
        ~Game();
        int getMoves();
        Grid* getGrid();
        Player* getPlayer(int);
        Player* start();
};

#endif