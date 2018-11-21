#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "View.h"

class Game{
    int numPlayers;
    Grid grid;
    View view;

    public:
        Game();
        void start();
};

#endif