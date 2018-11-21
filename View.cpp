View::View(){};

void View::displayGrid(Grid grid){
    // display the entire grid empty grid cells are 0
    // bikes represented as their colors (numbered as described in Grid.cpp)
    // Obstacles displayed by -1
    vector<vector<int>> displayGrid;
    
    for(int i = 0; i < grid.getSizeY(); i++){
        vector<int> row;
        for(int j = 0; j < grid.getSizeX(); j++){
            row.push_back(0);
        }
        displayGrid.push_back(row);
    }
    Bike currBike;
    for(int i = 0; i < grid.getNumBikes(); i++){
        currBike = grid.getBike(i);
        // place head in displayGrid
        head = currBike.getHead();
        displayGrid.at(head.at(0)).at(head.at(1)) = currBike.getColor();
        // display the tail points
        tail = currBike.getTail();
        for(int i = 0; i < currBike.getTailSize(); i++){
            tail_point = tail.at(i)
            displayGrid.at(tail_point.at(0)).at(tail_point.at(1)) = currBike.getColor() + 4;
        }
    }

    // Do same for obstacles.

}

vector<Block*> View::bikeView(Grid grid, int c){
    // return the surroundings of the bike
    /*
    0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 B 0 0 0 0 0
    0 0 0 0 0 b 0 0 0 0 0

    The capital B above is the Bikes head
    The lowercase b behind it is the tail. 
    The array is the 5X5 grid around the bikes head,
    with the other bikes being displayed as their numbered colors,
    and obstacles/out of bounds being displayed as -1
    */
    Bike bike = grid.getBike(c);
    Block* bikeHead = bike.getHead();
    int x1 = bikeHead.getX() - 2;
    int x2 = bikeHead.getX() + 2;
    int y1 = bikeHead.getY() - 1;
    int y2 = bikeHead.getY() + 3;
    vector<Block*> blocksInView = grid.getBlocks(x1, x2, y1, y2);
        
}