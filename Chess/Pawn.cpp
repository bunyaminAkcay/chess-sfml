#include "Pawn.h"
#include <list>

Pawn::Pawn(Color color, Board* boardPointer) {

	this->color = color;
	this->boardPointer = boardPointer;
	std::string fileName;
	sf::Texture texture;
	if (this->color == Color::Black) {
		fileName = "assets/b_pawn_png_128px.png";
	}
	if (this->color == Color::White) {
		fileName = "assets/w_pawn_png_128px.png";
	}

	if (!texture.loadFromFile(fileName)) {
		//error handling
	}
	this->texture = texture;
}


std::list<sf::Vector2u> Pawn::getMoves(sf::Vector2u position) {
	std::list<sf::Vector2u> moves;
	int h = (int)color; 
	if (isCoordInBoard(position.x, position.y - h) && boardPointer->pieces[position.x][position.y - h] == boardPointer->nullPtr) {
		if (played == false && isCoordInBoard(position.x, position.y - 2*h) && boardPointer->pieces[position.x][position.y - 2*h] == boardPointer->nullPtr) {
			moves.push_back(sf::Vector2u(position.x, position.y - 2*h));
		}
		moves.push_back(sf::Vector2u(position.x, position.y - h));	
	}
	if (isCoordInBoard(position.x + 1, position.y - h) && boardPointer->pieces[position.x + 1][position.y - h] != boardPointer->nullPtr && boardPointer->pieces[position.x + 1][position.y - h]->color != color) {
		moves.push_back(sf::Vector2u(position.x + 1, position.y - h));
	}
	if (isCoordInBoard(position.x - 1, position.y - h) && boardPointer->pieces[position.x - 1][position.y - h] != boardPointer->nullPtr && boardPointer->pieces[position.x - 1][position.y - h]->color != color) {
		moves.push_back(sf::Vector2u(position.x - 1, position.y - h));
	}

	return moves;
}
