#include "Grid.h"

class Manager {

    private:
    int xPos[5];
    int oPos[4];
    int lastPos;
    bool xWin;
    bool oWin;

    int scoreKeeper[8];

    public:
    bool checkWin(int count);
    bool returnXWin();
    bool returnOWin();
    void userInput(int count, Grid *grid);
    Manager();

};