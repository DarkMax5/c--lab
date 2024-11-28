/**
 * @file tic_tac_toe.hpp
 * @brief Заголовочный файл для игры "Крестики-нолики"
 *
 * Метаинформация:
 * - Проект: Крестики-нолики
 * - Автор: Косарчук Максим
 * - Год: 2024
 *
 * Описание:
 * Этот файл содержит объявления классов, представляющих игровое поле и логику игры.
 * Класс TicTacToe представляет логику игры, а TicTacToeBoard отвечает за прорисовку.
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
 * @brief Абстрактный базовый класс для объектов, которые могут быть нарисованы.
 *
 * Этот класс предоставляет чисто виртуальную функцию для рисования объекта на экране.
 */
class Drawable {
public:
    /**
     * @brief Рисует объект на экране.
     *
     * @param window Окно, в котором будет рисоваться объект.
     */
    virtual void draw(sf::RenderWindow& window) const = 0;

    virtual ~Drawable() {}
};

/**
 * @class TicTacToe
 * @brief Класс для логики игры "Крестики-нолики".
 *
 * Класс содержит методы для инициализации поля, проверки победителей, заполненности
 * поля и другие важные функции игры.
 */
class TicTacToe {
private:
    std::vector<std::vector<char>> board; ///< Игровое поле

public:
    /**
     * @brief Конструктор по умолчанию.
     * Инициализирует игровое поле пустыми значениями.
     */
    TicTacToe();

    /**
     * @brief Конструктор копирования.
     * Копирует данные из другого объекта TicTacToe.
     *
     * @param other Объект, из которого будет скопировано состояние.
     */
    TicTacToe(const TicTacToe& other);

    /**
     * @brief Конструктор с параметрами.
     * Инициализирует игровое поле заданными значениями.
     *
     * @param initialBoard Начальное игровое поле.
     */
    TicTacToe(std::vector<std::vector<char>> initialBoard);

    /**
     * @brief Оператор присваивания.
     * Присваивает данные другого объекта TicTacToe текущему объекту.
     *
     * @param other Объект, данные которого будут присвоены.
     * @return Ссылка на текущий объект.
     */
    TicTacToe& operator=(const TicTacToe& other);

    /**
     * @brief Оператор сравнения.
     * Сравнивает два объекта TicTacToe на равенство.
     *
     * @param other Объект для сравнения.
     * @return true, если объекты равны, иначе false.
     */
    bool operator==(const TicTacToe& other) const;

    /**
     * @brief Ввод игрового поля.
     *
     * @param is Поток ввода.
     * @param game Объект игры.
     * @return Поток ввода.
     */
    friend std::istream& operator>>(std::istream& is, TicTacToe& game);

    /**
     * @brief Вывод игрового поля.
     *
     * @param os Поток вывода.
     * @param game Объект игры.
     * @return Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);

    /**
     * @brief Инициализация поля.
     * Заполняет поле пустыми значениями.
     */
    void initializeBoard();

    /**
     * @brief Инициализация поля с данными.
     *
     * @param initialBoard Начальное игровое поле.
     */
    void initializeBoardFrom(const std::vector<std::vector<char>>& initialBoard);

    /**
     * @brief Проверка, если поле заполнено.
     *
     * @return true, если поле полностью заполнено, иначе false.
     */
    bool isFull() const;

    /**
     * @brief Проверка победителя.
     *
     * @param player Символ игрока.
     * @return true, если игрок выиграл, иначе false.
     */
    bool checkWinner(char player) const;
};

/**
 * @class TicTacToeBoard
 * @brief Класс для прорисовки игрового поля.
 *
 * Этот класс используется для отображения игрового поля на экране с использованием
 * библиотеки SFML.
 */
class TicTacToeBoard : public Drawable {
public:
    /**
     * @brief Рисует игровое поле.
     *
     * @param window Окно для отображения игрового поля.
     */
    void draw(sf::RenderWindow& window) const override;
};

#endif // TIC_TAC_TOE_HPP
