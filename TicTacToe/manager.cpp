#include "lib/manager.h"
#include "lib/board.h"
#include <iostream>
using namespace std; 

void manager::readInput(board *newBoard){
    char input;
    int row,colum;

    cin >> input;

    if (input == 'e'){
        exit(0);
    }
    if (input == 'n'){
        newBoard->cleanBoard();
    }
    if (input == 'p'){
        cout << "row:  ";
        cin >> row;
        
        while(row != (65 || 66)){
            perror("ERROR Please enter Row");
            cin >> row;
        }
        cout << "colum:  ";
        cin >> colum;


    }
    
    



}
