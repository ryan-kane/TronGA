#include "Network.h"

#include <stdlib.h>
#include <sstream>

Network::Network(int ni, int nhl, int nn, int no): num_inputs(ni), 
                num_hidden_layers(nhl), num_neurons(nn), num_outputs(no)
{    
    // first layer
    if(num_hidden_layers == 0){
        layers.push_back(new Layer(num_inputs, num_outputs));
    }else{
        layers.push_back(new Layer(num_inputs, num_neurons));
    }
    for(int i = 0; i < num_hidden_layers; i++){
        
        if(i == num_hidden_layers - 1){
            // last layer
            layers.push_back(new Layer(num_neurons, num_outputs));
        }else{
            // middle hidden layer
            layers.push_back(new Layer(num_neurons, num_neurons));
        }
    }
}

Network::Network(Network* n1, Network* n2, int score1, int score2){
    // it is assumed that the networks are of the exact same dimensions
    num_inputs = n1->getNumInputs();
    num_hidden_layers = n1->getNumHiddenLayers();
    num_neurons = n1->getNumNeurons();
    num_outputs = n1->getNumOutputs();
    Layer* l1;
    Layer* l2;
    for(int i = 0; i < num_hidden_layers + 1; i++){
        l1 = n1->getLayer(i);
        l2 = n2->getLayer(i);
        layers.push_back(new Layer(l1, l2, score1, score2));   
    }
}

Network::~Network(){
    for(int i = 0; i < layers.size(); i++){
        delete layers[i];
    }
}

int Network::getNumInputs(){
    return num_inputs;
}

int Network::getNumHiddenLayers(){
    return num_hidden_layers;
}

int Network::getNumNeurons(){
    return num_neurons;
}

int Network::getNumOutputs(){
    return num_outputs;
}

Layer* Network::getLayer(int i){
    return layers[i];
}

std::vector<double> Network::FeedForward(std::vector<double> input){
    //There are (num_hidden_layers + 1) total layers
    std::vector<double> inputs = input;
    std::vector<double> out;
    for(int i = 0; i < num_hidden_layers + 1; i++){
        if(i > 0){
            inputs = out;
        }
        out = layers.at(i)->Feed(inputs);
    }
    return out;
}

std::string Network::toString(){
    std::stringstream ss;
    for(int i = 0; i < layers.size(); i++){
        ss << " // " << layers[i]->toString();
    }
    std::string network_string;
    ss >> network_string;
    return network_string;
}