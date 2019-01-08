#ifndef EVOLVER_H
#define EVOLVER_H

#include "Generation.h"
#include "Tournament.h"

class Evolver{
    /*
    The evolver will run a generation of size POPULATION through
    a tournament, and after that tournament, there will remain 
    NUM_WINNERS players in the generation, which will then create
    (POPULATION - NUM_WINNERS) new Players through mutating the 
    themselves.
    0 1 2 3  4  5  6   7   8 
    1 2 4 8 16 32 64 128 256
    POPULATION = (2^n)
    NUM_WINNERS = (2^(n-5))
    NUM_OFFSPRING = (2^(n-3))-1
    */
    public:
        Evolver(Generation* g): generation(g){};
        Generation* Evolve(int num_generations){
            Generation* nextGeneration;
            for(int i = 0; i < num_generations; i++){
                Tournament tournament = Tournament(generation);
                tournament.start();
                generation->display();
                nextGeneration = generation->breed(NUM_OFFSPRING);
                generation = nextGeneration;    
            }
            return generation;
        };
    private:
        Generation* generation;
};

#endif