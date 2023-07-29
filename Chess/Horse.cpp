#include "Horse.h"
#include <list>

Horse::Horse(Color color) {

	this->color = color;

	std::string fileName;
	sf::Texture texture;
	if (this->color == Color::Black) {
		fileName = "assets/b_knight_png_128px.png";
	}
	if (this->color == Color::White) {
		fileName = "assets/w_knight_png_128px.png";
	}

	if (!texture.loadFromFile(fileName)) {
		//error handling
	}
	this->texture = texture;
}


std::list<sf::Vector2u> Horse::getMoves(sf::Vector2u position) {
	std::list<sf::Vector2u> moves;
	const int m[8][2] = { {2,1},{1,2},{2,-1},{-1,2},{-2,1},{1,-2},{-1,-2},{-2,-1} };
	
	for (int i = 0; i < 8; i++){
		int x = position.x + m[i][0];
		int y = position.y + m[i][1];
		if ( x >= 0  and x <8 and y >=0 and y<8 ){
			moves.push_back(sf::Vector2u(x, y));
		}
	}

	return moves;
}

