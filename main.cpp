#include <iostream>
#include "headerFiles/Manager.h"

int main() {

    
    Manager man;
    Grid grid;

    int count = 0;

    grid.initializeGrid();
    grid.printGrid();

    bool winner = false;

    while(count < 9 && !winner){
        man.userInput(count, &grid);
        grid.printGrid();

        winner = man.checkWin(count);

        count++;
}

if(winner){
    if(man.returnOWin()){
        std::cout << "Player O won!" << std::endl;
    }else if(man.returnXWin()){
        std::cout << "Player X won!" << std::endl;
    }
}else{
    std::cout << "Its a tie" << std::endl;
}

}