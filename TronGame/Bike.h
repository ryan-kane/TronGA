#ifndef BIKE_H
#define BIKE_H

#include <vector>

using namespace std;

class Bike{
    int color;
    int directionX;
    int directionY;
    int headX;
    int headY;
    int tailSize;

    public:
        Bike(int, int, int, int, int);
        int getColor();
        int getHeadX();
        void setHeadX(int);
        int getHeadY();
        void setHeadY(int);
        int getDirectionX();
        void setDirectionX(int);
        int getDirectionY();
        void setDirectionY(int);
};

#endif