#ifndef PLAYER_H
#define PLAYER_H

#include "Settings.h"
#include "NeuralNetwork/Network.h"
#include "NeuralNetwork/NetworkSettings.h"

#include <iostream>
#include <vector>

static int next_id = 0;

class Player{
    Network* network;
    int id;
    public:
        Player();
        Player(Player*, Player*);
        ~Player();
        Network* getNetwork();
        int get_id();
        int move(std::vector<int>&);
        int convertToDir(int);
};

#endif