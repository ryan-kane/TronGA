#include "Tournament.h"

Tournament::Tournament(Generation* c){
    competitors = c;
    view = View();
    tid = next_tid++;
};

void Tournament::start(){
    // std::cout << NUM_WINNERS;
    while(competitors->getSize() > NUM_WINNERS){
        // std::cout << competitors->getSize() << std::endl;
        eliminationRound();
    }
    // roundRobin(); 
    // maybe add back later
};

void Tournament::eliminationRound(){
    Game* game;
    Player* p1;
    Player* p2;
    Player* winner;
    for(int i = 0; i + 1 < competitors->getSize(); i++){
        p1 = competitors->getPlayer(i);
        p2 = competitors->getPlayer(competitors->getSize() - 1);
        game = new Game(p1, p2);
        winner = game->start();
        if(game->getMoves() > INTERESTING){
            view.displayGame(game, tid);
        }
        delete game;
        if(p1 == winner){
            competitors->removePlayer(competitors->getSize() - 1);
            delete p2;
        }else{
            competitors->removePlayer(i);
            delete p1;
        }
    }
};

void Tournament::roundRobin(){
    Game* game;
    Player* p1;
    Player* p2;
    Player* winner;
    for(int i = 0; i < competitors->getSize(); i++){
        p1 = competitors->getPlayer(i);
        for(int j = i+1; j < competitors->getSize(); j++){
            p2 = competitors->getPlayer(j);
            game = new Game(p1, p2);
            winner = game->start();
            // winner->setScore(winner->getScore()+1);                
            delete game;
        }
    }
};