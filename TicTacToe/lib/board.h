#ifndef BOARD_H
#define BOARD_H


class board{
    
    private:
        char** field;
        
    public:
        board();
        void doMove(int* move,char token); 
        bool isFinished();
        void printField();
        char** getBoard();
        void cleanBoard();
        bool isFree(int *pos);

};

#endif