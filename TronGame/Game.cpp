#include "Game.h"

Game::Game(Player* p1, Player* p2){
    p1 = p1;
    p2 = p2;
    view = new View();
    grid = new Grid(GRID_SIZEX, GRID_SIZEY);
}

int Game::start(){
    int winner = PLAYER_NULL;
    int invalid;
    vector<int> p1v;
    vector<int> p2v;
    int p1m;
    int p2m;
    
    while(winner == PLAYER_NULL){

        // draw grid for visual analysis
        view->displayGrid(*grid);

        // collect player views
        view->playerView(*grid, PLAYER_1, p1v);
        view->playerView(*grid, PLAYER_2, p2v);

        // make moves from both players
        p1m = p1->move(p1v);
        p2m = p2->move(p2v);
        
        invalid = grid->move(PLAYER_1, p1m);
        if(invalid){
            // player 1 loses
            winner = PLAYER_2;
        }

        invalid = grid->move(PLAYER_2, p2m);
        if(invalid){
            // player 2 loses
            winner = PLAYER_1;
        }
    }
    // return winning player
    delete view;
    delete grid;
    return winner;
}