#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <string>

class Neuron{
    public:
        Neuron(int);
        Neuron(std::vector<double>);
        Neuron(Neuron*, Neuron*);
        int getNumInputs();
        double getWeight(int);
        double Activate(std::vector<double>);
        std::string toString();
    private:
        std::vector<double> weights;
        int num_inputs;
};

#endif