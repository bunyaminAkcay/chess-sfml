#include "Queen.h"
#include <list>

Queen::Queen(Color color, Board* boardPointer) {

	this->color = color;
	this->boardPointer = boardPointer;
	std::string fileName;
	sf::Texture texture;
	if (this->color == Color::Black) {
		fileName = "assets/b_queen_png_128px.png";
	}
	if (this->color == Color::White) {
		fileName = "assets/w_queen_png_128px.png";
	}

	if (!texture.loadFromFile(fileName)) {
		//error handling
	}
	this->texture = texture;
}

std::list<sf::Vector2u> Queen::getMoves(sf::Vector2u position) {
	std::list<sf::Vector2u> moves;
	int directions[8][2] = { {0,-1},{0,1},{-1,0},{1,0},{1,1},{-1,1},{-1,-1},{1,-1} };
	for (int j = 0; j < 8; j++) {
		for (int i = 1; i < 8; i++) {
			int x = position.x + i * directions[j][0];
			int y = position.y + i * directions[j][1];

			if (isCoordInBoard(x, y)) {
				if (boardPointer->pieces[x][y] == boardPointer->nullPtr) {
					moves.push_back(sf::Vector2u(x, y));
				}
				else if (boardPointer->pieces[x][y]->color == color) {
					break;
				}
				else {
					moves.push_back(sf::Vector2u(x, y));
					break;
				}
			}
			else {
				break;
			}
		}
	}
	return moves;
}