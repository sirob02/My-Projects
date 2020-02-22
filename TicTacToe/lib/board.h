#ifndef BOARD_H
#define BOARD_H

class board{
    
    private:
        char field[3][3];
        char *playername;
        void finishScreen(char winner);
    public:
        board(char *playername);
        void showBoard();
        char *getPlayerName();
        void cleanBoard();
        void printField();
        void isFinished();
        ~board();
};

#endif