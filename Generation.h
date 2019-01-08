#ifndef GENERATION_H
#define GENERATION_H

#include "Player.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Generation{
    public:
        Generation(){};

        int getSize(){
            return players.size();
        };

        Player* getPlayer(int i){
            return players[i];
        };

        // when adding a player 
        Player* addPlayer(Player* p){
            players.push_back(p);
        };

        void removePlayer(int i){
            players.erase(players.begin() + i);        
        };

        void display(){
            Player* p;
            std::cout << std::endl << std::endl;
            std::cout << "Generation" << std::endl;
            for(int i = 0; i < getSize(); i++){
                p = getPlayer(i);
                p->display();
            }
        };

        Generation* breed(int num_offspring){
            // This function doubles the offspring until meets the population setting
            Generation* offspring = new Generation();
            Player* p1;
            Player* p2;
            PlayerFactory pf;
            
            for(int i = 0; i < getSize(); i++){
                p1 = getPlayer(i);
                for(int j = i+1; j < getSize(); j++){
                    p2 = getPlayer(j);
                    // generate num_offspring children from the pair of players
                    for(int n = 0; n < num_offspring; n++){
                        offspring->addPlayer(pf.makeNetworkPlayer(p1,p2));
                    }
                }
                // add p1 back into the next generation
                offspring->addPlayer(p1);
            }
            
            // fill the remaining spaces with randomly generated players
            while(offspring->getSize() < POPULATION){
                offspring->addPlayer(pf.makeNetworkPlayer());
            }
            return offspring;
        };

        void writeToFile(char* filename){
            // basically this function opens a file and writes the best players 
            // into the file
            std::ofstream genfile;
            genfile.open (filename);
            for(int i = 0; i < getSize(); i++){
                genfile << getPlayer(i)->toString() << std::endl;
            }
            genfile.close();
        };

    private:
        std::vector<Player*> players;
};

#endif