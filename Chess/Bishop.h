#pragma once
#include "Piece.h"
class Bishop :public Piece
{
public: 
	Bishop(Color color, Board* boardPointer);
	std::list<sf::Vector2u> getMoves(sf::Vector2u position);
};

