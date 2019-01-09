#ifndef GENERATION_H
#define GENERATION_H

#include "Player.h"
#include "Settings.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Generation{
    public:
        Generation();

        ~Generation();

        int getSize();

        Player* getPlayer(int);

        // when adding a player 
        Player* addPlayer(Player*);

        void removePlayer(int);

        Generation* breed(int);

        void writeToFile(char*);

    private:
        std::vector<Player*> players;
};

#endif