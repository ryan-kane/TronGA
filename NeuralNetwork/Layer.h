#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"

#include <vector>
#include <string>


class Layer{
    public:
        Layer(int, int);
        Layer(std::vector<Neuron*>);
        Layer(Layer*, Layer*);
        ~Layer();
        int getNumNeurons();
        Neuron* getNeuron(int);
        std::vector<double> Feed(std::vector<double>);
        std::string toString();
    private:
        int num_neurons;
        std::vector<Neuron*> neurons;

};

#endif
