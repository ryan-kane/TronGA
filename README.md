# Tron Genetic Algorithm
attempting to create a simple tron-like game where a genetic algorithm will train neural networks by playing tournament-style games against eachother.
Will also have a simple command line view for the game to visualize the gameplay.
#
Right now it trains a batch of neural networks using a simple genetic algorithm that plays them against themselves. The winners move on while the losers are eliminated. The networks that are left at the end of a generational 'tournament' are then used to create the next generation of networks, by crossing over their weights. Every generation a few random networks are created as well.
#
# Things to add in the future
* A bias can be added to the weights to help make the move decisions more distinct.
* The players are not currently given a fitness score, simply just survive or be eliminated, perhaps in the future some sort of scoring could be added to make the crossover more efficient in creating good networks.

