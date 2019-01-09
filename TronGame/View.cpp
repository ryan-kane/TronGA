#include "View.h"

#include <iostream>

View::View(){}

void View::displayGrid(Grid* grid){
    vector<vector<int> > displayGrid;
    for(int i = -1; i < grid->getSizeY() + 1; i++){
        vector<int> row;
        for(int j = -1; j < grid->getSizeX() + 1; j++){
            //row.push_back(grid.getVal(j, i));
            std::cout << convertVal(grid->getVal(j, i)) << " ";
        }
        //displayGrid.push_back(row);
        std::cout << std::endl;
    }
}

void View::displayGame(Game* game, int id){
    //system("clear");
    std::cout << id << std::endl;
    displayGrid(game->getGrid());
    displayPlayer(game->getPlayer(PLAYER_1));
    displayPlayer(game->getPlayer(PLAYER_2));
    std::cout << std::endl << "Number of moves: " 
        << game->getMoves() << std::endl << std::endl;
}

void View::displayPlayer(Player* p){
    std::cout << "Player: " << p->get_id() << std::endl;
}

char View::convertVal(int val){
    char converted_val;
    if(val == BLUE){
        return '1';
    }else if(val == RED){
        return '2';
    }else if(val == EMPTY){
        return '.';
    }else if(val == OOB){
        return '*';
    }
}
