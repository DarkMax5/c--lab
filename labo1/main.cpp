#include "tic_tac_toe.hpp"
#include <iostream>

using namespace std;

int main() {
    TicTacToe game;
    char players[2] = { 'X', 'O' };
    int turn = 0;
    int row, col;

    while (true) {
        game.printBoard();
        char currentPlayer = players[turn % 2];
        cout << "Ход игрока " << currentPlayer << ": Введите строку и столбец (0, 1 или 2): ";
        cin >> row >> col;

        // Совершение хода
        if (!game.makeMove(row, col, currentPlayer)) {
            cout << "Некорректный ход. Попробуйте снова." << endl;
            continue;
        }

        // Проверка на победу
        if (game.checkWinner(currentPlayer)) {
            game.printBoard();
            cout << "Игрок " << currentPlayer << " выиграл!" << endl;
            break;
        }

        // Проверка на ничью
        if (game.isFull()) {
            game.printBoard();
            cout << "Ничья!" << endl;
            break;
        }

        turn++;
    }

    return 0;
}
