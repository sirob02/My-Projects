#include<iostream>
#include "lib/board.h"
using namespace std;

board::board(){
    field = new char*[3];
    for (int i = 0; i < 3; i++){
        field[i] = new char[3];
        for (int j = 0; j < 3; j++){
            field[i][j]='.';
        }
    }
}


void board::cleanBoard(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            this->field[i][j] = '.';
        }
    }
}

//@return a two dima
char** board::getBoard(){ 
    char **tmp = new char*[3];
    for (int i = 0; i < 3; i++){
        tmp[i] = new char[3];
        for (int j = 0; j < 3; j++){
            tmp[i][j]=this->field[i][j];
        }
    }
    return tmp;
}

//check if the game is over
bool board::isFinished(){
    // ---
    if( (field[0][0] == field[1][0])  &&  (field[0][0] == field[2][0]) ){  if(field[2][0]!='.'){return true;}}
    if( (field[0][1] == field[1][1])  &&  (field[0][1] == field[2][1]) ){  if(field[2][1]!='.'){return true;}}
    if( (field[0][2] == field[1][2])  &&  (field[0][2] == field[2][2]) ){  if(field[2][2]!='.'){return true;}}
    // |||
    if( (field[0][0] == field[0][1])  &&  (field[0][0] == field[0][2]) ){  if(field[0][2]!='.'){return true;}}
    if( (field[1][0] == field[1][1])  &&  (field[1][0] == field[1][2]) ){  if(field[1][2]!='.'){return true;}}
    if( (field[2][0] == field[2][1])  &&  (field[2][0] == field[2][2]) ){  if(field[2][2]!='.'){return true;}}
    // /
    if( (field[0][2] == field[1][1])  &&  (field[0][2] == field[2][0]) ){  if(field[0][2]!='.'){return true;}}
    // 
    if( (field[0][0] == field[1][1])  &&  (field[0][0] == field[2][2]) ){  if(field[2][2]!='.'){return true;}}
    return false;
}    

//apply move
// 0 = row 
// 1 = colum
void board::doMove(int* move,char token){
    
    if (token == 'X'){
        cout <<"Player set row: " << (char)move[0]+65 << " and colum: "<< move[1]+1 << "\n";
    }else{
        cout <<"AI set row: " << (char)move[0]+65 << " and colum: "<< move[1]+1 << "\n";
    }

    field[move[1]][move[0]]=token;
    
}

bool board::isFree(int* pos){
    if (field[pos[1]][pos[0]] == '.'){
        return true;
    }
    return false;
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
                cout << " "<< field[i-1][0] << " \n";
                continue;
            }
            cout << " "<< field[i-1][0]  << " |";
            
    }
    //third Line
    for (int i = 0; i < 4; i++){
            if( i == 0 ){
                cout << " B |";
                continue;
            }
            if( i == 3 ){
                cout << " "<< field[i-1][1] << " \n";
                continue;
            }
            cout << " "<< field[i-1][1] << " |";
            
    }
    //fourth Line
    for (int i = 0; i < 4; i++){
            if( i == 0 ){
                cout << " C |";
                continue;
            }
            if( i == 3 ){
                cout << " "<< field[i-1][2] << " \n";
                continue;
            }
            cout << " "<< field[i-1][2] << " |";
            
    }
    cout << "\n";
}