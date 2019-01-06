#ifndef VIEW_H
#define VIEW_H

#include "Grid.h"

#include <vector>

using namespace std;


class View{
    char convertVal(int);
    public:
        View();
        void displayGrid(Grid);
        void playerView(Grid, int, vector<int>&);
};

#endif