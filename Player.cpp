#include "Player.h"

Player::Player(){
    network = new Network(NUM_INPUTS, NUM_HIDDEN_LAYERS, NUM_NEURONS, NUM_OUTPUTS);
}

Player::~Player(){
    delete network;
}

int Player::move(std::vector<int> &view){
    // convert ints to doubles
    std::vector<double> inputs;
    for(int i = 0; i < view.size(); i++){
        double val = (double)view.at(i);
        inputs.push_back(val);
        // std::cout << val;
    }

    // feed inputs to network
    std::vector<double> outputs;
    outputs = network->FeedForward(inputs);

    // convert output to move
    std::cout << "Player::move" << std::endl;
    for(int i = 0; i < outputs.size(); i++){
        std::cout << outputs.at(i);
    }
    std::cout << " ";

    // return the most confident move
    int move = -1; // all outputs will be greater than 0
    int confident;
    for (int i = 0; i < outputs.size(); i++){
        if(outputs.at(i) > move){
            move = outputs.at(i);
            confident = i;
        }
    }
    return convertToDir(confident);
}

int Player::convertToDir(int i){
    if(i == 0){
        return LEFT;
    }else if(i == 1){
        return STRAIGHT;
    }else{
        return RIGHT;
    }
}