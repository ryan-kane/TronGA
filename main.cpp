#include "Player.h"
#include "Generation.h"
#include "Evolver.h"

#include <iostream>
#include <vector>

int main(){
    Generation* g = new Generation();
    
    // fill generation with players
    Player* p;
    for(int i = 0; i < POPULATION; i++){
        p = new Player();
        g->addPlayer(p);
    }
    
    Evolver e = Evolver(g);
    e.Evolve(NUM_GENERATIONS);
    // delete t;
    // return 0;
}