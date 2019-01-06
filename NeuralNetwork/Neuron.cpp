#include "Neuron.h"

#include <stdlib.h>
#include <iostream>
#include <math.h>       /* exp */
#include <sstream>


Neuron::Neuron(int num_inputs): num_inputs(num_inputs){
    weights.reserve(num_inputs);
    /*double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
*/
    for(int i = 0; i < num_inputs; i++){
        weights.push_back(((double) std::rand() / (RAND_MAX)) * 2 - 1);
    }
}

Neuron::Neuron(std::vector<double> weights) : weights(weights), num_inputs(weights.size()){}

Neuron::Neuron(Neuron* n1, Neuron* n2, int score1, int score2){
    // it is assumed that the neurons passed in are of the same size
    num_inputs = n1->getNumInputs();
    for(int i = 0; i < n1->getNumInputs(); i++){
        // create a new weight that is a number created from the
        // two neurons weights
        double w1 = n1->getWeight(i);
        double w2 = n2->getWeight(i);
        double mutation = ((double) std::rand() / (RAND_MAX)) * 2 - 1;
        int total = score1 + score2;
        double new_weight;
        if(mutation < (score1/total)-1){
            new_weight = w1 + mutation;
        }else{
            new_weight = w2 + mutation;
        }
        weights.push_back(new_weight);
    }
}

int Neuron::getNumInputs(){
    return num_inputs;
}

double Neuron::getWeight(int i){
    return weights[i];
}

double Neuron::Activate(std::vector<double> inputs){
    double total = 0;
    for(int i = 0; i < inputs.size(); i++){
        total += (inputs[i] * weights[i]);
    }

    //reduce it to between 0 and 1
    //f(x) = 1/(1+exp(-x))

    double out = 1 / (1 + exp((-1) * total));
    std::cout << out;
    return out;
}

std::string Neuron::toString(){
    std::stringstream ss;
    for(int i = 0; i < weights.size(); i++){
        ss << weights[i] << " ";
    }
    std::string neuron_string;
    ss >> neuron_string;
    return neuron_string;
}