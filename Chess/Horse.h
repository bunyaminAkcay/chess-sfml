#include "Piece.h"
#include "SFML/Graphics.hpp"
#include <list>

class Horse : Piece {

public:
	Horse(Color color);
	std::list<sf::Vector2u> getMoves(sf::Vector2u position);
};