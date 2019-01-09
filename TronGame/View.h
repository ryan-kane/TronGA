#ifndef VIEW_H
#define VIEW_H

#include "Grid.h"
#include "Game.h"
#include "../Player.h"

#include <vector>

class View{
    private:
        char convertVal(int);

    public:
        View();
        void displayGrid(Grid*);
        void displayGame(Game*, int);
        void displayPlayer(Player*);
};

#endif