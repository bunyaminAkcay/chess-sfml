#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Horse.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Chess");
    
    Board board(&window);

    Piece* p = (Piece*) new Horse(Piece::Color::White);
    board.pieces[2][1] = p;

    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                board.controlDrag(event.mouseButton.x, event.mouseButton.y);
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                board.undrag(event.mouseButton.x, event.mouseButton.y);
            }
        }
        window.clear();
        board.draw();
        window.display();
    }

    return 0;
}