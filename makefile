OBJ = Grid.o View.o Bike.o Game.o Player.o Network.o Layer.o Neuron.o Generation.o Tournament.o Evolver.o  main.o

tron_test: $(OBJ)
	g++ -o tron_test $(OBJ) -g
	rm $(OBJ)

main.o: main.cpp 
	g++ -c main.cpp -g

Bike.o: TronGame/Bike.cpp TronGame/Bike.h
	g++ -c TronGame/Bike.cpp -g

Grid.o: TronGame/Grid.cpp TronGame/Grid.h
	g++ -c TronGame/Grid.cpp -g

Game.o: TronGame/Game.cpp TronGame/Game.h
	g++ -c TronGame/Game.cpp -g

View.o: TronGame/View.cpp TronGame/View.h
	g++ -c TronGame/View.cpp -g

Layer.o: NeuralNetwork/Layer.cpp NeuralNetwork/Layer.h
	g++ -c NeuralNetwork/Layer.cpp -g

Network.o: NeuralNetwork/Network.cpp NeuralNetwork/Network.h 
	g++ -c NeuralNetwork/Network.cpp -g

Neuron.o: NeuralNetwork/Neuron.cpp NeuralNetwork/Neuron.h
	g++ -c NeuralNetwork/Neuron.cpp -g

Player.o: Player.cpp Player.h
	g++ -c Player.cpp -g

Generation.o: Generation.h Generation.cpp 
	g++ -c Generation.cpp -g

Tournament.o: Tournament.h Tournament.cpp
	g++ -c Tournament.cpp -g

Evolver.o: Evolver.h Evolver.cpp
	g++ -c Evolver.cpp -g

clean:
	rm -f $(OBJ) tron_test*