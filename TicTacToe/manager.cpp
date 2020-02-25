#include "lib/manager.h"
#include "lib/board.h"
#include "lib/tictactoe_Ai.h"
#include <iostream>
using namespace std; 

//initalize playerName and start dependencies
manager::manager(const char* playerName, char playerStart){
    this->playerName = playerName;
    if (playerStart == 'y'){
        this->playerMove = true;
    }
}

//read input, decide if PlayerMove or Ai Move
void manager::startGame(){
    //variables
    char decision = readInput();
    char startGame;

    system("clear");

    //stop game
    if (decision == 'e'){
        cout << "Thanks for playing\n";
        exit(0);
    }
    //new game
    if (decision == 'n'){
        system("clear");
        cout << "yes   y\nno    n\nFirst Move? ";
        cin >> startGame;

        while(startGame != 'y' && startGame != 'n'){
            system("clear");
            cout << "\nyes   y\nno    n\nFirst Move? ";
            cin >> startGame;
        }
        system("clear");
        newBoard->cleanBoard();
        if (startGame == 'y'){
            this->playerMove = true;
        }
    }
    askForMove();
}

// reading input 
// @return: e,n,p  
char manager::readInput(){
    //var
    char input;
    
    //print choices
    newBoard->printField();
    description();
    cin >> input;
    
    //wait for valid input
    while(true){
        //End game
        if (input == 'e'){
            return input;
        }
        //new Game
        if (input == 'n'){
            return input;
        }
        //play
        if (input == 'p'){
            return input;
        }
        system("clear");
        //print choices
        cout << "Novalid input!\n";
        cout << "end:   e\nnew:   n\nplay:  p\nEnter:";
        cin >> input;
    }    
}

// doing the actual Player or Ai move
void manager::askForMove(){
    int *hold;

    newBoard->printField();
    description();

    //player Move
    if (playerMove){
        hold = readUserInputMove();
        while(!(newBoard->isFree(hold))){
            cout << "This field is already used!\n";
            newBoard->printField();
            hold = readUserInputMove();
        }


        newBoard->doMove(hold,'X');
        if (newBoard->isFinished()){
            cout << "The game is finished!";
        }
        playerMove = false;
    }
    //AI Move
    if (!playerMove){
        hold = Ai->findBestMove(newBoard->getBoard());
        newBoard->doMove(hold,'O');
        playerMove = true;
    }

}

//read user Input for movement
// @return 2 dimensional array with row and colum 
int* manager::readUserInputMove(){
        //0 = row   = y
        //1 = colum = x
        int *move = new int[2];
        char row,colum;

        //check row
        cout << "row:  ";
        cin >> row;
        while((row != 'A')  && (row != 'B') && (row != 'C')){
            cout << "Not a row! Please try again:  ";
            cin >> row;
        }
        //check colum
        cout << "colum:  ";
        cin >> colum;
        while((colum != '1')  && (colum != '2') && (colum != '3')){
            cout << "Not a colum! Please try again:  ";
            cin >> colum;
        }
        //save results
        move[0] = (int)row-65;
        move[1] = (int)colum-49;

        system("clear");

        return move;
}

void manager::description(){

    //description
    cout << "end:   e\nnew:   n\nplay:  p\nWhat do you want?\n" ;
}
     

