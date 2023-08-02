#include "Piece.h"
#include "SFML/Graphics.hpp"
#include <list>

class King : Piece
{
public:
    King(Color color, Board* boardPointer);
    std::list<sf::Vector2u> getMoves(sf::Vector2u position);
};

