#include "Block.h"

Block::Block(int x, int y, int val): x(x), y(y), val(val){}

int Block::getX(){
    return x;
}

void Block::setX(int newX){
    x = newX;
}

int Block::getY(){
    return y;
}

void Block::setY(int newY){
    y = newY;
}

int Block::getVal(){
    return val;
}

void Block::setVal(int newVal){
    val = newVal;
}