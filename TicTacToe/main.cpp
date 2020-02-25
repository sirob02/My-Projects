/**
 *  @author Robert Simon
 * 
 *  @title: TicTacToe with AI (MinMax algorithm) 
 * 
 */ 

#include<iostream>
#include"lib/manager.h"

using namespace std;

int main(){

    //Var
    char *playerName = new char;
    char startGame;

    //greetings
    cout << "Hello there, \nthis is a TicTacToe game \n" << "Whats your name? \n";       
    cin >> playerName;
    cout << "yes   y\nno    n\nFirst Move? ";
    cin >> startGame;

    while(startGame != 'y' && startGame != 'n'){
        system("clear");
        cout << "\nyes   y\nno    n\nFirst Move? ";
        cin >> startGame;
    }
    system("clear");
    cout << "OK "<< playerName << " let's get started...\n\n\n";
    

    //create Manager
    manager *newManager = new manager(playerName,startGame);

    while (true){
        newManager->startGame();
    }
    

    return 0;
}