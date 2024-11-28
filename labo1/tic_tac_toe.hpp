#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <iostream>

const int SIZE = 3;

// ����������� ������� ����� ��� ����������
class Drawable {
public:
    virtual void draw() const = 0; // ����� ����������� �������
    virtual ~Drawable() {} // ����������� ����������
};

// ����� ���� "��������-������"
class TicTacToe {
private:
    char board[SIZE][SIZE]; // ������� ����

public:
    // ������������
    TicTacToe();
    TicTacToe(const TicTacToe& other);
    TicTacToe(char initialBoard[SIZE][SIZE]);

    // ���������
    TicTacToe& operator=(const TicTacToe& other);
    bool operator==(const TicTacToe& other) const;
    friend std::istream& operator>>(std::istream& is, TicTacToe& game);
    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);

    // ������
    void initializeBoard();
    void initializeBoardFrom(char initialBoard[SIZE][SIZE]);
};

// �����, ������� �������� �� ���������� �������� ����
class TicTacToeBoard : public Drawable {
public:
    void draw() const override; // ���������� ������� ���������
};

#endif // TIC_TAC_TOE_HPP

