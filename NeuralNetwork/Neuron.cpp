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
        weights.push_back(((double) rand() / (RAND_MAX)) * 2 - 1);
    }
}

Neuron::Neuron(std::vector<double> weights) : weights(weights), num_inputs(weights.size()){}

Neuron::Neuron(Neuron* n1, Neuron* n2){
    // it is assumed that the neurons passed in are of the same size
    num_inputs = n1->getNumInputs();
    double crossover_p = ((double) rand() / (RAND_MAX));
    double mutation_p = ((double) rand() / (RAND_MAX));
    for(int i = 0; i < n1->getNumInputs(); i++){
        // create a new weight that is a number created from the
        // two neurons weights
        double w1 = n1->getWeight(i);
        double w2 = n2->getWeight(i);
        
        double new_weight;
        // TODO: determine the new weights 
        double crossover = ((double) rand() / (RAND_MAX));
        if(crossover > crossover_p){
            new_weight = w1;
        }else{
            new_weight = w2;
        }
        double mutate = ((double) rand() / (RAND_MAX));
        if(mutate > mutation_p){
            new_weight = new_weight * mutate;
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
    // std::cout << "Neuron::Activate inputs:" << std::endl;
    // for(int i = 0; i < inputs.size(); i++){
    //     std::cout << inputs.at(i);
    // }
    // std::cout << std::endl;
    double out = 1 / (1 + exp((-1) * total));
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