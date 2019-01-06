#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "View.h"
#include "../Settings.h"
#include "../Player.h"

class Game{
    Grid* grid;
    View* view;
    Player* p1;
    Player* p2;
    
    public:
        Game(Player*, Player*);
        int start();
};

#endif