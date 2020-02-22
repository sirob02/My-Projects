#include<iostream>
#include "lib/board.h"
using namespace std;

board::board(char *playername){
    board::playername = playername;
    cleanBoard();
}

char* board::getPlayerName(){
    return playername;
}

void board::cleanBoard(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            this->field[i][j] = '.';
        }
    }
}

board::~board(){
    delete []playername;
}

void board::isFinished(){
    // ---
    if( (field[0][0] == field[1][0])  &&  (field[0][0] == field[2][0]) ){  finishScreen(field[2][0]);}
    if( (field[0][1] == field[1][1])  &&  (field[0][1] == field[2][1]) ){  finishScreen(field[2][1]);}
    if( (field[0][2] == field[1][2])  &&  (field[0][2] == field[2][2]) ){  finishScreen(field[2][2]);}
    // |||
    if( (field[0][0] == field[0][1])  &&  (field[0][0] == field[0][2]) ){  finishScreen(field[0][2]);}
    if( (field[1][0] == field[1][1])  &&  (field[1][0] == field[1][2]) ){  finishScreen(field[1][2]);}
    if( (field[2][0] == field[2][1])  &&  (field[2][0] == field[2][2]) ){  finishScreen(field[2][2]);}
    // /
    if( (field[2][2] == field[1][1])  &&  (field[2][2] == field[0][2]) ){  finishScreen(field[0][2]);}
    // 
    if( (field[0][0] == field[1][1])  &&  (field[0][0] == field[2][0]) ){  finishScreen(field[2][0]);}
}

void board::finishScreen(char winner){
    system("clear");
    cout << "the winner is:  "<< winner;
    cout << "end:   e\nnew:   n\n";
}

void board::printField(){
    //first Line
    for (int y = 0; y < 4; y++){
            if( y == 0 ){
                cout << "   |";
                continue;
            }
            if( y == 3 ){
                cout << " 3 \n";
                continue;
            }
            cout << " "<< y << " |";       
    }
    //second Line
    for (int i = 0; i < 4; i++){
            if( i == 0 ){
                cout << " A |";
                continue;
            }
            if( i == 3 ){
                cout << " "<< field[0][i-1] << " \n";
                continue;
            }
            cout << " "<< field[0][i-1] << " |";
            
    }
    //third Line
    for (int i = 0; i < 4; i++){
            if( i == 0 ){
                cout << " B |";
                continue;
            }
            if( i == 3 ){
                cout << " "<< field[1][i-1] << " \n";
                continue;
            }
            cout << " "<< field[1][i-1] << " |";
            
    }
    //fourth Line
    for (int i = 0; i < 4; i++){
            if( i == 0 ){
                cout << " C |";
                continue;
            }
            if( i == 3 ){
                cout << " "<< field[1][i-1] << " \n";
                continue;
            }
            cout << " "<< field[1][i-1] << " |";
            
    }
    cout << "\n";

    //description
    cout << "end:   e\nnew:   n\nplay:  p\n";
    
      
}