/**
 *  @author Robert Simon
 * 
 *  @title: TicTacToe with AI (MinMax algorithm) 
 * 
 */ 

#include<iostream>
#include"lib/board.h"
#include"lib/manager.h"
using namespace std;

int main(){

    char *playerName = new char;

    cout << "Hello there, \nthis is a TicTacToe game \n" << "Whats your name? \n";       
    cin >> playerName;

    //create classes
    board *newBoard = new board(playerName);
    manager *newManager = new manager();
    
    system("clear");
    cout << "OK "<< newBoard->getPlayerName() << " let's get started...\n\n\n";
    
    while(true){
        newBoard->printField();
        newManager->readInput(newBoard);
        system("clear");
    }
    
    
    //garbage collection
    delete playerName;

    return 0;
}