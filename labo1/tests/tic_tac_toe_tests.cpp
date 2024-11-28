#include "tic_tac_toe.hpp"
#include <gtest/gtest.h>

// ���� ��� �������� ������������� �������� ����
TEST(TicTacToeTest, InitializeBoard) {
    TicTacToe game;
    EXPECT_TRUE(game.isFull() == false);  // ���������, ��� ���� �� ���������
}

// ���� ��� �������� ������������ ����������
TEST(TicTacToeTest, CheckWinner) {
    TicTacToe game;
    std::vector<std::vector<char>> board = {
        {'X', 'X', 'X'},
        {' ', 'O', ' '},
        {'O', ' ', 'O'}
    };
    game.initializeBoardFrom(board);
    EXPECT_TRUE(game.checkWinner('X'));  // ���������, ��� 'X' �������
}