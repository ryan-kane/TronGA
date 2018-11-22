#include "Game.h"
#include "View.h"
#include "Grid.h"
#include "Bike.h"

int main(){
    Grid grid = Grid(10, 10);
    View view = View();
    view.displayGrid(grid);

    return 0;
}