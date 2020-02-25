#ifndef TICTACTOE_AI_H
#define TICTACTOE_AI_H

class TicTacToe_Ai{
    
    private:
        int x = -1;
        int y = -1;
        int minimax(char** board,int depth,bool isMax);
        int evaluate(char** b);
        bool isMovesLeft(char** board);  
    
    public:
        int* findBestMove(char** board);
        
};

#endif

