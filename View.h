#ifndef VIEW_H
#define VIEW_H

#include "Grid.h"

#include <vector>

using namespace std;


class View{

    public:
        View();
        void displayGrid(Grid);
        vector<vector<int>> bikeView(Grid, int);

};

#endif