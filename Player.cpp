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
        std::cout << val;
    }

    // feed inputs to network
    std::vector<double> outputs;
    outputs = network->FeedForward(inputs);

    // convert output to move
    std::cout << std::endl;
    for(int i = 0; i < outputs.size(); i++){
        std::cout << outputs.at(i);
    }
    std::cout << std::endl;

    return STRAIGHT;
}