#include <SFML/Graphics.hpp>
#include "tic_tac_toe.hpp"

int main() {
    // Инициализация окна с SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tic-Tac-Toe");

    TicTacToe game;
    TicTacToeBoard board;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        board.draw(window); // Рисуем поле
        window.display();
    }

    return 0;
}
