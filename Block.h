#ifndef BLOCK_H
#define BLOCK_H

class Block{
    int x;
    int y;
    int val;
    // 0 == empty
    // 1-4 == head of bike (different numbers are for the 4 colors)
    // 5-8 == tail of bike (different numbers are for the 4 colors)
    // -1 == obstacle or wall
    public:
        Block(int, int, int);
        int getX();
        void setX(int);
        int getY();
        void setY(int);
        int getVal();
        void setVal(int);
};

#endif