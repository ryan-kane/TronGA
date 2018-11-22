#ifndef GRID_H
#define GRID_H

#include "Bike.h"
#include "Block.h"

#include <vector>
using namespace std;

class Grid{
    vector<Bike> bikes;
    // vector<Obstacle> obstacles;
    vector<Block*> grid; // collection of block objects
    int sizeX;
    int sizeY;
    int numBikes;
    Block* center; // coords of 'center' of grid (best approx)
    // 0 == empty
    // 1-4 == head of bike (different numbers are for the 4 colors)
    // 5-8 == tail of bike (different numbers are for the 4 colors)
    // -1 == obstacle or wall

    public: 
        Grid(int, int); // Constructor

        vector<Block*> getGrid();

        int getSizeX();

        int getSizeY();
        
        Bike addBike(int); // creates and returns a bike object of color

        // Obstacle addObstacle(); // create and add an obstacle to the grid

        vector<Bike> getBikes(); // get all the bikes on the grid

        Bike removeBike(int); // give colour of the bike

        int getNumBikes(); // get the number of bikes on the grid

        Block* moveBike(Bike, int);

        Block* getBlock(int, int); // get block with x, y val
        
        vector<Block*> getBlocks(int, int, int, int); //get blocks between x1, x2 and y1, y2
};

#endif