#ifndef SETTINGS_H
#define SETTINGS_H

const int BLUE = 1;
const int RED = 2;
const int EMPTY = 0;
const int OOB = -1; 

const int RIGHT = 30;
const int LEFT = 20;
const int STRAIGHT = 10;

const int GRID_SIZEX = 40;
const int GRID_SIZEY = 40;
const int FOV = 4;

const int PLAYER_1 = 1001;
const int PLAYER_2 = 1002;
const int PLAYER_NULL = 1005;

const int CLR_1 = BLUE;
const int SPX_1 = 20;
const int SPY_1 = 30;
const int SDX_1 = 1;
const int SDY_1 = 0;

const int CLR_2 = RED;
const int SPX_2 = 20;
const int SPY_2 = 10;
const int SDX_2 = -1;
const int SDY_2 = 0;

// GA Settings
const int POPULATION = 128;
const int NUM_WINNERS = 10;
const int NUM_OFFSPRING = 2;
const int NUM_GENERATIONS = 10;

const int INTERESTING = 50;

#endif