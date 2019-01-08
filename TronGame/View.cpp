#include "View.h"

#include <iostream>

View::View(){}

void View::displayGrid(Grid grid){
    vector<vector<int> > displayGrid;
    // system("cls");
    for(int i = 0; i < grid.getSizeY(); i++){
        vector<int> row;
        for(int j = 0; j < grid.getSizeX(); j++){
            //row.push_back(grid.getVal(j, i));
            std::cout << convertVal(grid.getVal(j, i));
        }
        //displayGrid.push_back(row);
        std::cout << std::endl;
    }
}

char View::convertVal(int val){
    char converted_val;
    if(val == BLUE){
        return 'B';
    }else if(val == RED){
        return 'R';
    }else if(val == EMPTY){
        return '.';
    }else if(val == OOB){
        return '|';
    }
}

void View::playerView(Grid grid, int player, vector<int>& p_view){
    grid.getVals(PLAYER_1, p_view);
}