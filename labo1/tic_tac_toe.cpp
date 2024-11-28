#include "tic_tac_toe.hpp"

// ����������� �� ���������
TicTacToe::TicTacToe() : board(SIZE, std::vector<char>(SIZE, ' ')) {}

// ����������� �����������
TicTacToe::TicTacToe(const TicTacToe& other) : board(other.board) {}

// ����������� � �����������
TicTacToe::TicTacToe(std::vector<std::vector<char>> initialBoard) : board(initialBoard) {}

// �������� ������������
TicTacToe& TicTacToe::operator=(const TicTacToe& other) {
    if (this != &other) {
        board = other.board; // ���������� �������� ����������� ��� �������
    }
    return *this;
}

// �������� ���������
bool TicTacToe::operator==(const TicTacToe& other) const {
    return board == other.board; // �������� ��������� ��� ��������
}

// �������� �����
std::istream& operator>>(std::istream& is, TicTacToe& game) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            is >> game.board[i][j];
    return is;
}

// �������� ������
std::ostream& operator<<(std::ostream& os, const TicTacToe& game) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            os << game.board[i][j];
            if (j < SIZE - 1) os << " | ";
        }
        os << std::endl;
        if (i < SIZE - 1) os << "--|---|--" << std::endl;
    }
    return os;
}

// ������������� ����
void TicTacToe::initializeBoard() {
    board = std::vector<std::vector<char>>(SIZE, std::vector<char>(SIZE, ' '));
}

// ������������� ���� � �������
void TicTacToe::initializeBoardFrom(const std::vector<std::vector<char>>& initialBoard) {
    board = initialBoard;
}

// ��������, ���� ���� ���������
bool TicTacToe::isFull() const {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// �������� ����������
bool TicTacToe::checkWinner(char player) const {
    // �������� ������������ � ����������
    for (int i = 0; i < SIZE; ++i) {
        if (std::all_of(board[i].begin(), board[i].end(), [player](char c) { return c == player; }))
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // �������� ����������
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// ���������� ������ ��������� ��� ������ TicTacToeBoard
void TicTacToeBoard::draw() const {
    std::cout << "Drawing Tic-Tac-Toe board..." << std::endl;
}
