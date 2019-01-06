#include "Bike.h"

using namespace std;

Bike::Bike(int c, int hx, int hy, int dx, int dy){
    headX = hx;
    headY = hy;
    directionX = dx;
    directionY = dy;
    color = c;
}

int Bike::getColor(){
    return color;
}

int Bike::getHeadY(){
    return headY;
}

void Bike::setHeadY(int hy){
    headY = hy;
}

int Bike::getHeadX(){
    return headX;
}

void Bike::setHeadX(int hx){
    headX = hx;
}

int Bike::getDirectionX(){
    return directionX;
}

void Bike::setDirectionX(int dx){
    directionX = dx;
}

int Bike::getDirectionY(){
    return directionY;
}

void Bike::setDirectionY(int dy){
    directionY = dy;
}