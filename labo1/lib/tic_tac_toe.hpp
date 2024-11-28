/**
 * @file tic_tac_toe.hpp
 * @brief ������������ ���� ��� ���� "��������-������"
 *
 * ��������������:
 * - ������: ��������-������
 * - �����: �������� ������
 * - ���: 2024
 *
 * ��������:
 * ���� ���� �������� ���������� �������, �������������� ������� ���� � ������ ����.
 * ����� TicTacToe ������������ ������ ����, � TicTacToeBoard �������� �� ����������.
 *
 * @version 1.0
 * @date 2024-11-29
 */

#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int SIZE = 3;

/**
 * @class Drawable
 * @brief ����������� ������� ����� ��� ��������, ������� ����� ���� ����������.
 *
 * ���� ����� ������������� ����� ����������� ������� ��� ��������� ������� �� ������.
 */
class Drawable {
public:
    /**
     * @brief ������ ������ �� ������.
     *
     * @param window ����, � ������� ����� ���������� ������.
     */
    virtual void draw(sf::RenderWindow& window) const = 0;

    virtual ~Drawable() {}
};

/**
 * @class TicTacToe
 * @brief ����� ��� ������ ���� "��������-������".
 *
 * ����� �������� ������ ��� ������������� ����, �������� �����������, �������������
 * ���� � ������ ������ ������� ����.
 */
class TicTacToe {
private:
    std::vector<std::vector<char>> board; ///< ������� ����

public:
    /**
     * @brief ����������� �� ���������.
     * �������������� ������� ���� ������� ����������.
     */
    TicTacToe();

    /**
     * @brief ����������� �����������.
     * �������� ������ �� ������� ������� TicTacToe.
     *
     * @param other ������, �� �������� ����� ����������� ���������.
     */
    TicTacToe(const TicTacToe& other);

    /**
     * @brief ����������� � �����������.
     * �������������� ������� ���� ��������� ����������.
     *
     * @param initialBoard ��������� ������� ����.
     */
    TicTacToe(std::vector<std::vector<char>> initialBoard);

    /**
     * @brief �������� ������������.
     * ����������� ������ ������� ������� TicTacToe �������� �������.
     *
     * @param other ������, ������ �������� ����� ���������.
     * @return ������ �� ������� ������.
     */
    TicTacToe& operator=(const TicTacToe& other);

    /**
     * @brief �������� ���������.
     * ���������� ��� ������� TicTacToe �� ���������.
     *
     * @param other ������ ��� ���������.
     * @return true, ���� ������� �����, ����� false.
     */
    bool operator==(const TicTacToe& other) const;

    /**
     * @brief ���� �������� ����.
     *
     * @param is ����� �����.
     * @param game ������ ����.
     * @return ����� �����.
     */
    friend std::istream& operator>>(std::istream& is, TicTacToe& game);

    /**
     * @brief ����� �������� ����.
     *
     * @param os ����� ������.
     * @param game ������ ����.
     * @return ����� ������.
     */
    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);

    /**
     * @brief ������������� ����.
     * ��������� ���� ������� ����������.
     */
    void initializeBoard();

    /**
     * @brief ������������� ���� � �������.
     *
     * @param initialBoard ��������� ������� ����.
     */
    void initializeBoardFrom(const std::vector<std::vector<char>>& initialBoard);

    /**
     * @brief ��������, ���� ���� ���������.
     *
     * @return true, ���� ���� ��������� ���������, ����� false.
     */
    bool isFull() const;

    /**
     * @brief �������� ����������.
     *
     * @param player ������ ������.
     * @return true, ���� ����� �������, ����� false.
     */
    bool checkWinner(char player) const;
};

/**
 * @class TicTacToeBoard
 * @brief ����� ��� ���������� �������� ����.
 *
 * ���� ����� ������������ ��� ����������� �������� ���� �� ������ � ��������������
 * ���������� SFML.
 */
class TicTacToeBoard : public Drawable {
public:
    /**
     * @brief ������ ������� ����.
     *
     * @param window ���� ��� ����������� �������� ����.
     */
    void draw(sf::RenderWindow& window) const override;
};

#endif // TIC_TAC_TOE_HPP
