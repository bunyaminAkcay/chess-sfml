#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Horse.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Chess");
    
    Board board(&window);

    Piece* p = (Piece*) new Horse(Piece::Color::White);
    board.pieces[2][1] = p;
    Piece* rook = (Piece*) new Rook(Piece::Color::White, &board);
    board.pieces[3][3] = rook;
    Piece* pawn1 = (Piece*) new Pawn(Piece::Color::Black, &board);
    board.pieces[2][2] = pawn1;
    Piece* pawn2 = (Piece*) new Pawn(Piece::Color::White, &board);
    board.pieces[7][6] = pawn2;
    Piece* king = (Piece*) new King(Piece::Color::White, &board);
    board.pieces[5][3] = king;
    Piece* queen = (Piece*) new Queen(Piece::Color::White, &board);
    board.pieces[4][4] = queen;
    Piece* bishop = (Piece*) new Bishop(Piece::Color::White, &board);
    board.pieces[6][6] = bishop;

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