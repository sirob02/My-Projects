#include "lib/tictactoe_Ai.h"
#include<iostream>
using namespace std;

int* TicTacToe_Ai::findBestMove(char** board){
    //0 = row
    //1 = colum
    int *res = new int[2];
    int bestValue = -1000;


    // Traverse all cells, evaluate minimax function for 
    // all empty cells. And return the cell with optimal 
    // value. 
    for (int i = 0; i<3; i++) { 
        for (int j = 0; j<3; j++){

            // Check if cell is empty 
            if (board[i][j]=='.'){ 
                // Make the move 
                board[i][j] = 'O'; 
  
                // compute evaluation function for this move. 
                int moveValue = minimax(board, 0, false); 
  
                // Undo the move 
                board[i][j] = '.'; 
  
                // If the value of the current move is more than the best value, then update 
                // best/ 
                if (moveValue > bestValue){ 
                    this->x = i; 
                    this->y = j; 
                    bestValue = moveValue; 
                } 
            } 
        } 
    } 

    res[0] = this->y;    
    res[1] = this->x;
    return res;
}

int TicTacToe_Ai::minimax(char** board,int depth,bool isMax){
    int score = evaluate(board); 
  
    // If Maximizer has won the game return his/her 
    // evaluated score 
    if (score == 10) 
        return score; 
  
    // If Minimizer has won the game return his/her 
    // evaluated score 
    if (score == -10) 
        return score; 
  
    // If there are no more moves and no winner then 
    // it is a tie 
    if (isMovesLeft(board)==false) 
        return 0; 
  
    // If this maximizer's move 
    if (isMax) 
    { 
        int best = -1000; 
  
        // Traverse all cells 
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]=='.') 
                { 
                    // Make the move 
                    board[i][j] = 'O'; 
  
                    // Call minimax recursively and choose 
                    // the maximum value 
                    best = max( best, 
                        minimax(board, depth+1, !isMax) ); 
  
                    // Undo the move 
                    board[i][j] = '.'; 
                } 
            } 
        } 
        return best; 
    } 
  
    // If this minimizer's move 
    else
    { 
        int best = 1000; 
  
        // Traverse all cells 
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]=='.') 
                { 
                    // Make the move 
                    board[i][j] = 'X'; 
  
                    // Call minimax recursively and choose 
                    // the minimum value 
                    best = min(best,minimax(board, depth+1, !isMax)); 
  
                    // Undo the move 
                    board[i][j] = '.'; 
                } 
            } 
        } 
        return best; 

    }
}


int TicTacToe_Ai::evaluate(char** b){

    // Checking for Rows for X or O victory. 
    for (int row = 0; row<3; row++){ 
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2]){ 
            if (b[row][0]=='O') 
                return +10; 
            else if (b[row][0]=='X') 
                return -10; 
        } 
    } 
  
    // Checking for Columns for X or O victory. 
    for (int col = 0; col<3; col++) { 
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col]){ 
            if (b[0][col]=='O'){ 
                return +10; 
            }else if (b[0][col]=='X'){ 
                return -10; 
            }    
        } 
    } 
  
    // Checking for Diagonals for X or O victory. 
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2]) 
    { 
        if (b[0][0]=='O') 
            return +10; 
        else if (b[0][0]=='X') 
            return -10; 
    } 
  
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0]) 
    { 
        if (b[0][2]=='O') 
            return +10; 
        else if (b[0][2]=='X') 
            return -10; 
    } 
  
    // Else if none of them have won then return 0 
    return 0; 
} 

bool TicTacToe_Ai::isMovesLeft(char** board){
    for (int i = 0; i<3; i++) 
        for (int j = 0; j<3; j++) 
            if (board[i][j]=='.') 
                return true; 
    return false; 

}