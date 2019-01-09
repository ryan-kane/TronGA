#include "Evolver.h"

Evolver::Evolver(Generation* g){
    generation = g;
}

Evolver::~Evolver(){
    delete generation;
}

Generation* Evolver::getGeneration(){
    return generation;
}

void Evolver::Evolve(int num_generations){
    Generation* nextG;
    for(int i = 0; i < num_generations; i++){
        Tournament tournament = Tournament(generation);
        tournament.start();
        nextG = generation->breed(NUM_OFFSPRING);
        delete generation;
        generation = nextG;    
    }
};