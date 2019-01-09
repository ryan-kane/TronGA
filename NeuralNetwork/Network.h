#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <string>

#include "Layer.h"

class Network{
    public:
        Network(int, int, int, int);
        Network(Network*, Network*);
        ~Network();
        int getNumInputs();
        int getNumHiddenLayers();
        int  getNumNeurons();
        int getNumOutputs();
        Layer* getLayer(int);
        std::vector<double> FeedForward(std::vector<double>);
        std::string toString();
    private:
        int num_inputs;
        int num_hidden_layers;
        int num_neurons; // Number of neurons in a hidden layer
        int num_outputs;
        std::vector<Layer*> layers;

};

#endif