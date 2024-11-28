#include "tic_tac_toe.hpp"

// Конструктор по умолчанию
TicTacToe::TicTacToe() : board(SIZE, std::vector<char>(SIZE, ' ')) {}

// Конструктор копирования
TicTacToe::TicTacToe(const TicTacToe& other) : board(other.board) {}

// Конструктор с параметрами
TicTacToe::TicTacToe(std::vector<std::vector<char>> initialBoard) : board(initialBoard) {}

// Оператор присваивания
TicTacToe& TicTacToe::operator=(const TicTacToe& other) {
    if (this != &other) {
        board = other.board; // Используем оператор копирования для вектора
    }
    return *this;
}

// Оператор сравнения
bool TicTacToe::operator==(const TicTacToe& other) const {
    return board == other.board; // Алгоритм сравнения для векторов
}

// Оператор ввода
std::istream& operator>>(std::istream& is, TicTacToe& game) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            is >> game.board[i][j];
    return is;
}

// Оператор вывода
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

// Инициализация поля
void TicTacToe::initializeBoard() {
    board = std::vector<std::vector<char>>(SIZE, std::vector<char>(SIZE, ' '));
}

// Инициализация поля с данными
void TicTacToe::initializeBoardFrom(const std::vector<std::vector<char>>& initialBoard) {
    board = initialBoard;
}

// Проверка, если поле заполнено
bool TicTacToe::isFull() const {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// Проверка победителя
bool TicTacToe::checkWinner(char player) const {
    // Проверка горизонталей и вертикалей
    for (int i = 0; i < SIZE; ++i) {
        if (std::all_of(board[i].begin(), board[i].end(), [player](char c) { return c == player; }))
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Проверка диагоналей
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Реализация метода отрисовки для класса TicTacToeBoard
void TicTacToeBoard::draw() const {
    std::cout << "Drawing Tic-Tac-Toe board..." << std::endl;
}
