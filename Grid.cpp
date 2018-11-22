#include "Grid.h"

Grid::Grid(int sx, int sy): sizeX(sx), sizeY(sy){
    numBikes = 0;
    for(int i = 0; i < sizeY; i++){
        for(int j = 0; j < sizeX; j++){
            Block* block = new Block(j, i, 0);
            grid.push_back(block);
            if(i == (int) sy/2 && j == (int) sx/2){
                center = block;
            }
        }
    }
}

Block* Grid::getBlock(int x, int y){
    Block* block;
    for(int i = 0; i < grid.size(); i++){
        block = grid.at(i);
        if(block->getX() == x && block->getY() == y){
            return block;
        }
    }
} 

int Grid::getSizeY(){
    return sizeY;
}

int Grid::getSizeX(){
    return sizeX;
}

// Bike Grid::addBike(int color){
//     vector<int> sp; // starting postion
//     int d; // d
//     Bike b;
//     if(numBikes == 4){
//         return NULL;
//     }
//     switch(numBikes){
//         case 0:
//             sp.at(0) = center. + 2;
//             sp.at(1) = center.at(1) + 2;
//             d.at(0) = 0;
//             d.at(1) = 1;
//         case 1:
//             sp.at(0) = center.at(0) - 2;
//             sp.at(1) = center.at(1) + 2;
//             d.at(0) = -1;
//             d.at(1) = 0;
//         case 2:
//             sp.at(0) = center.at(0) + 2;
//             sp.at(1) = center.at(1) - 2;
//             d.at(0) = 1;
//             d.at(1) = 0;
//         case 3:
//             sp.at(0) = center.at(0) - 2;
//             sp.at(1) = center.at(1) - 2;
//             d.at(0) = 0;
//             d.at(1) = -1;
//         default:
//             break;
//     }
//     b = Bike(color, sp, d);
//     numBikes++;
//     bikes.push_back(b);
//     return b;
// }

vector<Block*> Grid::getGrid(){
    return grid;
}

// Bike Grid::removeBike(int c){
//     Bike rmBike;
//     for(int i = 0; i < bikes.size(); i++){
//         rmBike = bike.at(i);
//         if(rmBike.getColor() == c){
//             bikes.erase(bikes.begin()+i);
//         }
//         return rmBike;
//     }
//     int val;
//     for(int i = 0; i < blocks.size(); i++){
//         val = blocks.at(i).getVal();
//         if(val == c || val == c+4){
//             blocks.at(i).setVal(0);
//         }
//     }
// }

int Grid::getNumBikes(){
    return numBikes;
}

// Bike Grid::getBike(int c){
//     for(int i = 0; i < numBikes(); i++){
//         if(bikes.at(i).getColor() == c){
//             return bikes.at(i);
//         }
//     }
// }

// Block* Grid::moveBike(Bike b, int d){
//     switch(d){
//        case 1:
//             b.setDirection((-1) * b.getDirection().at(1), b.getDirection().at(0));
//             break;
//         case 2:
//             b.setDirection(b.getDirection().at(1), (-1) * b.getDirection().at(0));
//             break;
//         default:
//             break;
//     }
//     Block prevHeadBlock = grid.getBlock(b.getHead());
//     prevHeadBlock.setVal(prevHeadBlock.getVal() + 4);
//     b.move();
//     Block currHeadBlock = b.getHead();
//     currHeadBlock.setVal(b.getColor());
// }