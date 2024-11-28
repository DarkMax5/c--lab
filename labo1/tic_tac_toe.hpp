#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

const int SIZE = 3;

// ����������� ������� ����� ��� ����������
class Drawable {
public:
    virtual void draw() const = 0; // ����� ����������� �������
    virtual ~Drawable() {}
};

// ����� ���� "��������-������"
class TicTacToe {
private:
    std::vector<std::vector<char>> board; // ������� ����

public:
    // ������������
    TicTacToe();
    TicTacToe(const TicTacToe& other);
    TicTacToe(std::vector<std::vector<char>> initialBoard);

    // ���������
    TicTacToe& operator=(const TicTacToe& other);
    bool operator==(const TicTacToe& other) const;
    friend std::istream& operator>>(std::istream& is, TicTacToe& game);
    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);

    // ������
    void initializeBoard();
    void initializeBoardFrom(const std::vector<std::vector<char>>& initialBoard);
    bool isFull() const;
    bool checkWinner(char player) const;
};

// �����, ������� �������� �� ���������� �������� ����
class TicTacToeBoard : public Drawable {
public:
    void draw() const override; // ���������� ������� ���������
};

#endif // TIC_TAC_TOE_HPP

