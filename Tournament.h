#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Generation.h"
#include "Player.h"
#include "TronGame/Game.h"
#include "TronGame/View.h"

static int next_tid = 0;

class Tournament{
    public:
        Tournament(Generation*);
        void start();
    
    private:
        void eliminationRound();
        void roundRobin();
        Generation* competitors;
        View view;
        int tid;
};

#endif