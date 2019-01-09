#include "Game.h"

Game::Game(Player* player1, Player* player2){
    p1 = player1;
    p2 = player2;
    grid = new Grid(GRID_SIZEX, GRID_SIZEY);
    moves = 0;
}

Game::~Game(){
    delete grid;
}

Grid* Game::getGrid(){
    return grid;
}

Player* Game::getPlayer(int p){
    if(p == PLAYER_1){
        return p1;
    }else{
        return p2;
    }
}

int Game::getMoves(){
    return moves;
}

Player* Game::start(){
    Player* won;
    int winner = PLAYER_NULL;
    int invalid;
    vector<int> p1v;
    vector<int> p2v;
    int p1m;
    int p2m;
    
    while(winner == PLAYER_NULL){
        // collect player views
        p1v.clear();
        p2v.clear();
        grid->getVals(PLAYER_1, p1v);
        grid->getVals(PLAYER_1, p2v);

        // make moves from both players
        p1m = p1->move(p1v);
        p2m = p2->move(p2v);
        
        invalid = grid->move(PLAYER_1, p1m);
        moves++;
        if(invalid){
            // player 1 loses
            winner = PLAYER_2;
            won = p2;
        }else{
            invalid = grid->move(PLAYER_2, p2m);
            moves++;
            if(invalid){
                // player 2 loses
                winner = PLAYER_1;
                won = p1;
            }
        }
        
    }
    // return winning player
    return won;
}
