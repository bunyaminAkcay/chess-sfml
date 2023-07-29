#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <list>

using namespace std;

class Board;

class Piece {

public:
	static enum class Color { White = 1, Black = -1 } White;
	Color color;
	Board* boardPointer;
	sf::Sprite sprite;
	sf::Texture texture;
	
	virtual std::list<sf::Vector2u> getMoves(sf::Vector2u position) = 0;

};