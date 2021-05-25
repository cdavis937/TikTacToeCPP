#include <iostream>
#include "headerFiles/Grid.h"

void Grid::printGrid(){

    for(int i = 1; i < 18; i++){
        for(int j = 1; j < 18; j++){
            std::cout << printArray[i-1][j-1];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

}

void Grid::initializeGrid(){

    for(int i = 1; i < 18; i++){
        for(int j = 1; j < 18; j++){
            if(i%6 == 0){
                printArray[i-1][j-1] = '-';
            }else if(j%6 == 0){
                printArray[i-1][j-1] = '|';
            }else{
                printArray[i-1][j-1] = ' ';
            }
        }
    }

    printArray[2][2] = '1';
    printArray[2][8] = '4';
    printArray[2][14] = '7';

    printArray[8][2] = '2';
    printArray[8][8] = '5';
    printArray[8][14] = '8';

    printArray[14][2] = '3';
    printArray[14][8] = '6';
    printArray[14][14] = '9';
    
}

void Grid::addX(int pos){

    int xPos = 0;
    int yPos = 0;

    switch (pos)
    {
    case 1:
        xPos = 1;
        yPos = 1;
    break;
    case 2:
        xPos = 7;
        yPos = 1;
    break;
    case 3:
        xPos = 13;
        yPos = 1;
    break;
    case 4:
        xPos = 1;
        yPos = 7;
    break;
    case 5:
        xPos = 7;
        yPos = 7;
    break;
    case 6:
        xPos = 13;
        yPos = 7;
    break;
    case 7:
        xPos = 1;
        yPos = 13;
    break;
    case 8:
        xPos = 7;
        yPos = 13;
    break;
    case 9:
        xPos = 13;
        yPos = 13;
    break;
    }

    int count = 0;

    while(count < 3){
        
        if(count%2 == 0){
            printArray[xPos][yPos] = 'X';
            printArray[xPos + 1][yPos] = ' ';
            printArray[xPos + 2][yPos] = 'X';
        }else{
            printArray[xPos][yPos] = ' ';
            printArray[xPos + 1][yPos] = 'X';
            printArray[xPos + 2][yPos] = ' ';
        }

        yPos++;
        count++;
        
    }

}

void Grid::addO(int pos){

    int xPos = 0;
    int yPos = 0;

    switch (pos)
    {
    case 1:
        xPos = 1;
        yPos = 1;
    break;
    case 2:
        xPos = 7;
        yPos = 1;
    break;
    case 3:
        xPos = 13;
        yPos = 1;
    break;
    case 4:
        xPos = 1;
        yPos = 7;
    break;
    case 5:
        xPos = 7;
        yPos = 7;
    break;
    case 6:
        xPos = 13;
        yPos = 7;
    break;
    case 7:
        xPos = 1;
        yPos = 13;
    break;
    case 8:
        xPos = 7;
        yPos = 13;
    break;
    case 9:
        xPos = 13;
        yPos = 13;
    break;
    }

    int count = 0;

    while(count < 3){
        
        if(count%2 == 0){
            printArray[xPos][yPos] = 'O';
            printArray[xPos + 1][yPos] = 'O';
            printArray[xPos + 2][yPos] = 'O';
        }else{
            printArray[xPos][yPos] = 'O';
            printArray[xPos + 1][yPos] = ' ';
            printArray[xPos + 2][yPos] = 'O';
        }

        yPos++;
        count++;
        
    }

}
