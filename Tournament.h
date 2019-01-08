#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Game/Series.h"

class Tournament{
    public:
        Tournament(Generation* competitors){
            this->competitors = competitors;
        };

        void start(){
            std::cout << NUM_WINNERS;
            while(competitors->getSize() > NUM_WINNERS){
                std::cout << competitors->getSize() << std::endl;
                eliminationRound();
            }
            roundRobin();
        };
    
    private:
        void eliminationRound(){
            Series* series;
            Player* p1;
            Player* p2;
            Player* winner;
            for(int i = 0; i < competitors->getSize(); i++){
                p1 = competitors->getPlayer(i);
                p2 = competitors->getPlayer(i+1);
                series = new Series(p1, p2);
                winner = series->start(1);
                if(p1 == winner){
                    competitors->removePlayer(i + 1);
                    delete p2;
                }else{
                    competitors->removePlayer(i);
                    delete p1;
                }
            }
        };

        void roundRobin(){
            Series* series;
            Player* p1;
            Player* p2;
            Player* winner;
            for(int i = 0; i < competitors->getSize(); i++){
                p1 = competitors->getPlayer(i);
                for(int j = i+1; j < competitors->getSize(); j++){
                    p2 = competitors->getPlayer(j);
                    series = new Series(p1, p2);
                    winner = series->start(4);
                    std::cout << i << " " << j << std::endl;
                    winner->setScore(winner->getScore()+1);                
                }
            }
        };

        Generation* competitors;
};

#endif