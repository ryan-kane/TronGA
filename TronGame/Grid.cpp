#include "Grid.h"

Grid::Grid(int sx, int sy): sizeX(sx), sizeY(sy){
    // initialize empty grid (values all 0)
    for(int i = 0; i < sizeX; i++){
        vector<int> column(sizeY, EMPTY); 
        grid.push_back(column);
    }

    bike1 = new Bike(CLR_1, SPX_1, SPY_1, SDX_1, SDY_1);
    setVal(bike1->getHeadX(), bike1->getHeadY(), bike1->getColor());

    bike2 = new Bike(CLR_2, SPX_2, SPY_2, SDX_2, SDY_2);
    setVal(bike2->getHeadX(), bike2->getHeadY(), bike2->getColor());
}

Grid::~Grid(){
    // delete bike1;
    // delete bike2;
}

int Grid::getVal(int x, int y){
    int val = OOB; // value on board at x and y coords
    // size check
    if(x < 0 || x >= sizeX || y < 0 || y >= sizeY){
        return val;
    }
    val = grid.at(x).at(y);
}

void Grid::getVals(int x1, int x2, int y1, int y2, vector<int> &vals){
    for(int i = x1; i < x2; i++){
        vector<int> row;
        for(int j = y1; j < y2; j++){
            vals.push_back(getVal(i, j));
        }
    }
}

void Grid::getVals(int player, vector<int> &vals){
    Bike* b = getBike(player);
    int x1 = b->getHeadX() - FOV;
    int x2 = b->getHeadX() + FOV;
    int y1 = b->getHeadY() - FOV;
    int y2 = b->getHeadY() + FOV;
    getVals(x1, x2, y1, y2, vals);
}

void Grid::setVal(int x, int y, int val){
    // check bounds on x and y and
    if(x > 0 && x < sizeX && y > 0 && y < sizeY){    
        int curVal = getVal(x, y);
        if(curVal == EMPTY){
            // empty grid block
            grid.at(x).at(y) = val;
        }
    }
}

int Grid::getSizeY(){
    return sizeY;
}

int Grid::getSizeX(){
    return sizeX;
}

int Grid::move(int player, int move){
    Bike* b = getBike(player);
    int proxy;
    switch(move){
        case RIGHT:
            proxy = b->getDirectionX();
            b->setDirectionX((-1) * b->getDirectionY());
            b->setDirectionY(proxy);
            break;
        case LEFT:
            proxy = b->getDirectionY();
            b->setDirectionY((-1) * b->getDirectionX());
            b->setDirectionX(proxy);
            break;
        default:
            // going straight doesnt change anything
            break;
    }
    int newHeadX = b->getHeadX() + b->getDirectionX();
    int newHeadY = b->getHeadY() + b->getDirectionY();
    // check if the move is valid
    int preVal = getVal(newHeadX, newHeadY);
    if(preVal != 0){
        // collision
        removeBike(b);
        delete bike1;
        delete bike2;
        return preVal; // will be nonzero (invalid)
    }
    // move head to new block
    b->setHeadX(b->getHeadX() + b->getDirectionX());
    b->setHeadY(b->getHeadY() + b->getDirectionY());
    
    setVal(b->getHeadX(), b->getHeadY(), b->getColor());
    return preVal; // will be 0 if the space was valid
}

vector<vector<int> > Grid::getGrid(){
    return grid;
}

void Grid::removeBike(Bike* b){
    // deletes bike and removes all values from the grid
    int val;
    int c = b->getColor();
    for(int x = 0; x < sizeX; x++){
        for(int y = 0; y < sizeY; y++){
            val = getVal(x, y);
            if(val == c || val == c+10){
                setVal(x, y, 0);              
            }
        }   
    }
}

Bike* Grid::getBike(int player){
    if(player == PLAYER_1){
        return bike1;
    }else{
        return bike2;
    }
}