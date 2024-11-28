#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

const int SIZE = 3;  

class TicTacToe {
public:
    TicTacToe();               
    void printBoard() const;    
    bool checkWinner(char player) const;  
    bool isFull() const;        
    bool makeMove(int row, int col, char player);  

private:
    char board[SIZE][SIZE];     
    void initializeBoard();     
};

#endif // TIC_TAC_TOE_HPP
