#include "Generation.h"

Generation::Generation(){}

Generation::~Generation(){
    for(int i = 0; i < players.size(); i++){
        delete players.at(i);
    }
}

int Generation::getSize(){
    return players.size();
};

Player* Generation::getPlayer(int i){
    return players.at(i);
};

// when adding a player 
Player* Generation::addPlayer(Player* p){
    players.push_back(p);
};

void Generation::removePlayer(int i){
    players.erase(players.begin() + i);        
};

Generation* Generation::breed(int num_offspring){
    // This function doubles the offspring until meets the population setting
    Generation* offspring = new Generation();
    Player* p1;
    Player* p2;
    
    for(int i = 0; i < getSize(); i++){
        p1 = getPlayer(i);
        for(int j = i; j < getSize(); j++){
            p2 = getPlayer(j);
            // generate num_offspring children from the pair of players
            for(int n = 0; n < num_offspring; n++){
                offspring->addPlayer(new Player(p1, p2));
            }
        }
    }
    
    // fill the remaining spaces with randomly generated players
    while(offspring->getSize() < POPULATION){
        offspring->addPlayer(new Player());
    }
    return offspring;
};

void Generation::writeToFile(char* filename){
    // basically this function opens a file and writes the best players 
    // into the file
    // std::ofstream genfile;
    // genfile.open (filename);
    // for(int i = 0; i < getSize(); i++){
    //     genfile << getPlayer(i)->toString() << std::endl;
    // }
    // genfile.close();
};