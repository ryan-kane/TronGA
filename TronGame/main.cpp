// #include "Game.h"
#include "View.h"
#include "Grid.h"
#include "Bike.h"
#include "Game.h"
#include "../Player.h"

#include <iostream>
#include <vector>

int main(){
    Player* p1 = new Player();
    Player* p2 = new Player();
    int winner;
    Game game = Game(p1, p2);
    winner = game.start();
    delete p1;
    delete p2;
    return 0;
}