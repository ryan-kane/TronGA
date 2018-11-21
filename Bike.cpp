#include "Bike.h"

using namespace std;

Bike::Bike(int c, Block sp, vector<int> d): color(c){
    // int c is the color of the bike
    // sp (starting position) is a 2d vector representing where
    // the head starts on the board. It must be valid
    head = sp;
    direction = d;
    tailSize = 0;
}

vector<int> getHead(){
    return head;
}

int getTailSize(){
    return tailSize;
}

vector<Block> getTail(){
    return tail;
}

Block move(int move){
    // 0 == go forward
    // 1 == go right
    // 2 == go left
    switch(move){
        case 1:
            direction.at(0) = (-1) * direction.at(1);
            direction.at(1) = direction.at(0);
            break;
        case 2:
            direction.at(0) = direction.at(1);
            direction.at(1) = (-1) * direction.at(0);
            break;
        default:
            break;
    }
    head.setX(head.getX() + direction.at(0));
    head.setY(head.getY() + direction.at(1));

    // move head to new block
    // set old block to val + 4
    
}

int getScore(){
    return tailSize;
}

