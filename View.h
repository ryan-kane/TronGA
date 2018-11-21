#ifndef VIEW_H
#define VIEW_H

#include "Grid.h"

class View{

    public:
        View();
        void display(Grid);
        vector<vector<int>> bikeView(Grid, int);

};

#endif