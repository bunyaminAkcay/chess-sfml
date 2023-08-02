#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <list>

using namespace std;

class Board;

class Piece {

public:
	bool played = false;
	static enum class Color { White = 1, Black = -1 } White;
	Color color;
	Board* boardPointer;
	sf::Sprite sprite;
	sf::Texture texture;
	
	virtual std::list<sf::Vector2u> getMoves(sf::Vector2u position) = 0;
    bool isCoordInBoard(int x, int y) {
		if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
			return true; 
		} 
		return false;
	}

		

};