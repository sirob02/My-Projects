#ifndef MANAGER_H
#define MANAGER_H

#include "board.h"
#include "tictactoe_Ai.h"
class manager{
    
    private:
        board *newBoard = new board();
        TicTacToe_Ai * Ai = new TicTacToe_Ai();
        bool playerMove = false;
        const char* playerName;
        char readInput();
        int* readUserInputMove();
        void askForMove();
        void description();

        
    public:
        manager(const char* playerName, char playerStart);
        void startGame();
};

#endif