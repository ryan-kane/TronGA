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
    Generation* generation;
    public:
        Evolver(Generation*);
        ~Evolver();
        Generation* getGeneration();
        void Evolve(int);
};

#endif