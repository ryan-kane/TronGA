#ifndef BLOCK_H
#define BLOCK_H

class Block{
    int x;
    int y;
    int val;
    public:
        Block();
        int getX();
        void setX();
        int getY();
        void setY();
        int getVal();
        void setVal();
};

#endif