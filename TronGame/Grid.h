#ifndef GRID_H
#define GRID_H

#include "Bike.h"
#include "../Settings.h"

#include <vector>
#include <iostream>
using namespace std;

class Grid{
    
    private:
        Bike* bike1;
        Bike* bike2;
        // vector<Obstacle> obstacles;
        vector<vector<int> > grid; // collection of block objects
        int sizeX;
        int sizeY;

    public: 
        Grid(int, int); // Constructor   

        int getVal(int, int);

        void setVal(int, int, int);

        vector<vector<int> > getGrid();

        int getSizeX();

        int getSizeY();

        Bike* getBike(int);

        void removeBike(Bike*); 

        int move(int, int);
        
        void getVals(int, int, int, int, vector<int>&);
        
        void getVals(int, vector<int>&);
};

#endif