#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <iostream>

const int SIZE = 3;

// Абстрактный базовый класс для прорисовки
class Drawable {
public:
    virtual void draw() const = 0; // Чисто виртуальная функция
    virtual ~Drawable() {} // Виртуальный деструктор
};

// Класс игры "Крестики-нолики"
class TicTacToe {
private:
    char board[SIZE][SIZE]; // Игровое поле

public:
    // Конструкторы
    TicTacToe();
    TicTacToe(const TicTacToe& other);
    TicTacToe(char initialBoard[SIZE][SIZE]);

    // Операторы
    TicTacToe& operator=(const TicTacToe& other);
    bool operator==(const TicTacToe& other) const;
    friend std::istream& operator>>(std::istream& is, TicTacToe& game);
    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);

    // Методы
    void initializeBoard();
    void initializeBoardFrom(char initialBoard[SIZE][SIZE]);
};

// Класс, который отвечает за прорисовку игрового поля
class TicTacToeBoard : public Drawable {
public:
    void draw() const override; // Реализация функции отрисовки
};

#endif // TIC_TAC_TOE_HPP

