#include "tic_tac_toe.hpp"
#include <gtest/gtest.h>

// Тест для проверки инициализации игрового поля
TEST(TicTacToeTest, InitializeBoard) {
    TicTacToe game;
    EXPECT_TRUE(game.isFull() == false);  // Проверяем, что поле не заполнено
}

// Тест для проверки корректности победителя
TEST(TicTacToeTest, CheckWinner) {
    TicTacToe game;
    std::vector<std::vector<char>> board = {
        {'X', 'X', 'X'},
        {' ', 'O', ' '},
        {'O', ' ', 'O'}
    };
    game.initializeBoardFrom(board);
    EXPECT_TRUE(game.checkWinner('X'));  // Проверяем, что 'X' победил
}