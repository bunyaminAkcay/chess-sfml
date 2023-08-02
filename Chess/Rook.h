#include "Piece.h"
#include "SFML/Graphics.hpp"
#include <list>

class Rook : Piece {

public:
	Rook(Color color, Board* boardPointer);
	std::list<sf::Vector2u> getMoves(sf::Vector2u position);
};
