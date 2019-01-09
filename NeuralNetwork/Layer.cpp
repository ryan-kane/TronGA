#include "Layer.h"

#include <stdlib.h>
#include <sstream>
#include <string>

Layer::Layer(int num_inputs, int num_neurons): num_neurons(num_neurons){
    for(int i = 0; i < num_neurons; i++){
        neurons.push_back(new Neuron(num_inputs));
    }
}

Layer::Layer(std::vector<Neuron*> neurons): neurons(neurons), 
                    num_neurons(neurons.size()){}

Layer::Layer(Layer* l1, Layer* l2){
    // it is assumed that the layers are of the same dimension
    Neuron* n1;
    Neuron* n2;
    num_neurons = l1->getNumNeurons();
    for(int i = 0; i < l1->getNumNeurons(); i++){
        n1 = l1->getNeuron(i);
        n2 = l2->getNeuron(i);
        neurons.push_back(new Neuron(n1, n2));
    }
}

Layer::~Layer(){
    for(int i = 0; i < neurons.size(); i++){
        delete neurons.at(i);
    }
}

int Layer::getNumNeurons(){
    return num_neurons;
}

Neuron* Layer::getNeuron(int i){
    return neurons.at(i);
}

std::vector<double> Layer::Feed(std::vector<double> inputs){
    std::vector<double> outs;
    for(int i = 0; i < num_neurons; i++){
        double out = neurons.at(i)->Activate(inputs);
        outs.push_back(out);
    }
    // returns output vector
    return outs;
}

std::string Layer::toString(){
    std::stringstream ss;
    for(int i = 0; i < neurons.size(); i ++){
        ss << neurons[i]->toString();
    }
    std::string layer_string;
    ss >> layer_string;
    return layer_string;
}