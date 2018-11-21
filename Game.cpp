Game::Game(int np, int sx, int sy):numPlayers(np){
    if( nb > 4 || nb < 1){
        // invalid number of bikes
        return NULL;
    }
    if(sx > 25 || sx < 5){
        // invalid board width
        return NULL;
    }
    if(sy > 25 || sy < 5){
        // invalid board length
        return NULL;
    }
    grid = Grid(sx, sy);
    
    for(int i = 0; i < numBikes){
        grid.addBike(i);
        
    }

    view = new View();
}

void Game::start(){
    while(numBikes > 1){
        // draw grid
        view.displayGrid(grid);
        // collect and make moves
        int move;
        for(int i = 0; i < players.size(); i++){
            move = players.at(i).makeMove(view.bikeView(grid, i));
            if(grid.getBike(i).move(move)){
                // then there was a collision as move() returned a non-zero value
                // give the player their score
                player.setScore(grid.getBike(i).getScore());
                // remove the bike
                grid.removeBike(i);
            }
        }
    }
    
    // declare the winner as the last bike still existing
    // 
    
}
