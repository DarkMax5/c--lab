#include "tic_tac_toe.hpp"

int main() {
    TicTacToe game;
    TicTacToeBoard board;

    board.draw(); // Прорисовка игрового поля
    std::cout << game << std::endl; // Вывод игрового поля

    // Пример использования оператора ввода
    std::cout << "Enter board configuration (9 characters): ";
    std::cin >> game;

    std::cout << "Updated board: " << std::endl;
    std::cout << game << std::endl;

    return 0;
}
