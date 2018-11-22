#ifndef BIKE_H
#define BIKE_H

#include "Block.h"

#include <vector>

using namespace std;

class Bike{
    int color; // 0 == yellow, 1 == red, 2 == blue, 3 == green
    vector<int> direction; // 2d vector that can have one of 4 values (UDRL)
    Block* head; //2d vector for coords of head in grid
    int tailSize; //length of tail

    public:
        Bike(int, Block*, vector<int>);
        int getColor();
        Block* getHead();
        int getTailSize();
        Block* move(int);
        int getScore();
};

#endif