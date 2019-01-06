OBJ = Network.o Layer.o Neuron.o main.o

test: $(OBJ)
	g++ -o test $(OBJ) -g

main.o: main.cpp
	g++ -c main.cpp -g

#Network
Layer.o: Layer.cpp Layer.h
	g++ -c Layer.cpp -g

Network.o: Network.cpp Network.h 
	g++ -c Network.cpp -g

Neuron.o: Neuron.cpp Neuron.h
	g++ -c Neuron.cpp -g

clean:
	rm -f $(OBJ) test