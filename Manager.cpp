#include "headerFiles/Manager.h"
#include <iostream>
#include <string>

bool Manager::returnXWin(){
    return xWin;
}

bool Manager::returnOWin(){
    return oWin;
}

bool Manager::checkWin(int count){
    /*
    0 is row 1
    1 is row 2
    2 is row 3
    3 is col 1
    4 is col 2
    5 is col 3
    6 is diag 1
    7 is diag 2
    */

   int score = 0;
   if(count%2 == 0){
       score = 1;
   }else{
       score = -1;
   }

    switch(lastPos){
        case 1:
            scoreKeeper[0] += score;
            scoreKeeper[3] += score;
            scoreKeeper[6] += score;
        break;
        case 2:
            scoreKeeper[1] += score;
            scoreKeeper[3] += score;
        break;
        case 3:
            scoreKeeper[2] += score;
            scoreKeeper[3] += score;
            scoreKeeper[7] += score;
        break;
        case 4:
            scoreKeeper[0] += score;
            scoreKeeper[4] += score;
        break;
        case 5:
            scoreKeeper[1] += score;
            scoreKeeper[4] += score;
            scoreKeeper[6] += score;
            scoreKeeper[7] += score;
        break;
        case 6:
            scoreKeeper[2] += score;
            scoreKeeper[4] += score;
        break;
        case 7:
            scoreKeeper[0] += score;
            scoreKeeper[5] += score;
            scoreKeeper[7] += score;
        break;
        case 8:
            scoreKeeper[1] += score;
            scoreKeeper[5] += score;
        break;
        case 9:
            scoreKeeper[2] += score;
            scoreKeeper[5] += score;
            scoreKeeper[6] += score;
        break;
       };

       for(int i = 0; i < sizeof(scoreKeeper); i++){
           if(scoreKeeper[i] == 3){
               xWin = true;
           }else if(scoreKeeper[i] == -3){
               oWin = true;
           }
       }

       return (oWin || xWin);
   
}

Manager::Manager(){
    
    for(int i = 0; i < sizeof(xPos); i++){
        xPos[i] = 0;
    }

    for(int i = 0; i < sizeof(oPos); i++){
        oPos[i] = 0;
    }

    int lastPos = 0;

    xWin = false;
    oWin = false;

    for(int i = 0; i < sizeof(scoreKeeper); i++){
        scoreKeeper[i] = 0;
    }
}

void Manager::userInput(int count, Grid *grid){

    if(count%2 == 0){

        bool notAlreadyTaken = false;
        bool isNumber = false;

        while(!notAlreadyTaken || !isNumber){
            std::string userInput = "";
            std::cout << "X's turn, enter a position: ";
            std::cin >> userInput;

            isNumber = true;
            for(int i = 0; i < userInput.length(); i++){
                if(!std::isdigit(userInput[i])){
                    isNumber = false;
                }
            }

            if(isNumber){
                int num = std::stoi(userInput);

                if(num < 10 && num > 0){
                    notAlreadyTaken = true;
                    for(int i = 0; i < sizeof(xPos); i++){
                        if(num == xPos[i]){
                            notAlreadyTaken = false;
                        }
                    }

                    for(int i = 0; i < sizeof(oPos); i++){
                        if(num == oPos[i]){
                            notAlreadyTaken = false;
                        }
                    }

                    if(notAlreadyTaken){
                        xPos[count / 2] = num;
                        (*grid).addX(num);
                        lastPos = num;
                    }else{
                        std::cout << "Position already taken" << std::endl;
                    }
                }else{
                    std::cout << "Invalid number range" << std::endl;
                }

            }else{
                std::cout << "Please enter a valid entry" << std::endl;
            }

            
        }
            


    }else{
        bool notAlreadyTaken = false;
        bool isNumber = false;

        while(!notAlreadyTaken || !isNumber){
            std::string userInput = "";
            std::cout << "O's turn, enter a position: ";
            std::cin >> userInput;

            isNumber = true;
            for(int i = 0; i < userInput.length(); i++){
                if(!std::isdigit(userInput[i])){
                    isNumber = false;
                }
            }

            if(isNumber){
                int num = std::stoi(userInput);

                if(num < 10 && num > 0){
                    notAlreadyTaken = true;
                    for(int i = 0; i < sizeof(xPos); i++){
                        if(num == xPos[i]){
                            notAlreadyTaken = false;
                        }
                    }

                    for(int i = 0; i < sizeof(oPos); i++){
                        if(num == oPos[i]){
                            notAlreadyTaken = false;
                        }
                    }

                    if(notAlreadyTaken){
                        oPos[count / 2] = num;
                        (*grid).addO(num);
                        lastPos = num;
                    }else{
                        std::cout << "Position already taken" << std::endl;
                    }
                }else{
                    std::cout << "Invalid number range" << std::endl;
                }
                

            }else{
                std::cout << "Please enter a valid number" << std::endl;
            }

            
        }
    }
    

}
