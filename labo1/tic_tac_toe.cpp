#include "tic_tac_toe.hpp"
#include <iostream>

using namespace std;

// Конструктор — инициализация поля
TicTacToe::TicTacToe() {
    initializeBoard();
}

// Инициализация игрового поля
void TicTacToe::initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';  // Пустые клетки
        }
    }
}

// Печать игрового поля
void TicTacToe::printBoard() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--|---|--" << endl;
    }
}

// Проверка на победу
bool TicTacToe::checkWinner(char player) const {
    // Проверка горизонталей и вертикалей
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    // Проверка диагоналей
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

// Проверка на заполненность поля
bool TicTacToe::isFull() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// Совершение хода
bool TicTacToe::makeMove(int row, int col, char player) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
        return false;  // Неверный ход
    }

    board[row][col] = player;  // Совершение хода
    return true;
}
