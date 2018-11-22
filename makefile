OBJ = Grid.o View.o Block.o Bike.o main.o

tron_test: $(OBJ)
	g++ -o tron_test $(OBJ) -g
	#rm -f $(OBJ)

main.o: main.cpp 
	g++ -c main.cpp -g

Block.o: Block.cpp Block.h
	g++ -c Block.cpp -g

Bike.o: Bike.cpp Bike.h
	g++ -c Bike.cpp -g

View.o: View.cpp View.h
	g++ -c View.cpp -g

Grid.o: Grid.cpp Grid.h
	g++ -c Grid.cpp -g

clean:
	rm -f $(OBJ) nnetgame*