#include "Board.h"
#include "SFML/Graphics.hpp"

Board::Board(sf::RenderWindow* windowPointer) {
	this->windowPointer = windowPointer;
}

void Board::draw() {

	//draw rectangles
	sf::Color lightColor, darkColor;
	if ( thema == Board::Thema::Classic ) {
		lightColor = sf::Color{ 0xF0D9B5FF };
		darkColor = sf::Color{ 0xB58863FF };
	}
	else if(thema == Board::Thema::blackWhite){
		lightColor = sf::Color::White;
		darkColor = sf::Color::Black;
	}
	else if (thema == Board::Thema::Purple) {
		lightColor = sf::Color{ 0xE6DBF1FF };
		darkColor = sf::Color{ 0x957AB0FF };
	}

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			sf::RectangleShape rectangle(sf::Vector2f((float) squareSize, (float) squareSize));
			
			if( (i+j) %2 == 0){
				rectangle.setFillColor(lightColor);
			}
			else {
				rectangle.setFillColor(darkColor);
			}
			rectangle.setPosition((float) boardPosition.x + i*squareSize , (float)boardPosition.y + j * squareSize);

			windowPointer->draw(rectangle);
		}
	}
	//draw Pieces
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			if (pieces[i][j] != nullPtr){
				sf::Sprite s = sf::Sprite(pieces[i][j]->texture);
				
				if (pieces[i][j] == dragObject) {
					if (dragging == false) {
						dragging = true;
						dragDiff = sf::Vector2f(sf::Mouse::getPosition(*windowPointer).x - pieces[i][j]->sprite.getPosition().x, sf::Mouse::getPosition(*windowPointer).y - pieces[i][j]->sprite.getPosition().y);
					}
					s.setPosition(sf::Vector2f( sf::Mouse::getPosition(*windowPointer).x - dragDiff.x, sf::Mouse::getPosition(*windowPointer).y - dragDiff.y));
				}
				else {
					s.setPosition(sf::Vector2f((float) boardPosition.x + squareSize * i, (float) boardPosition.y + squareSize * j));
				}
				s.setScale(((float)squareSize / 128), ((float)squareSize / 128));
				pieces[i][j]->sprite = s;
				windowPointer->draw(s);

			}
		}
	}
	//draw legal moves
	
	if (choosenPiece != NULL) {
		std::list<sf::Vector2u>::iterator it;
		for (it = legalMoves.begin(); it != legalMoves.end(); ++it) {
			int circleSize = 10;
			sf::CircleShape shape(circleSize);
			shape.setFillColor(sf::Color(100, 250, 50));
			shape.setPosition( ((sf::Vector2u)*it).x * squareSize + boardPosition.x + (squareSize)/2 - circleSize, ((sf::Vector2u)*it).y * squareSize + boardPosition.y + (squareSize) / 2 - circleSize);
			windowPointer->draw(shape);
		}
	}
	
}

list<sf::Vector2u> Board::getLegalMoves(Piece* piece, sf::Vector2u position) {
	if (piece != nullPtr) {
		list<sf::Vector2u> moves = piece->getMoves(position);
		/*
		std::list<sf::Vector2u>::iterator it;
		for (it = moves.begin(); it != moves.end(); ++it) {
			std::cout << it->name;
		}
		*/
		return moves;
	}
	else {
		list<sf::Vector2u> emptyList;
		return emptyList;
	}
}


void Board::controlDrag(int mouseX, int mouseY) {
	if (choosenPiece != nullPtr ) {
		playPiece(mouseX, mouseY);
	}

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			if (pieces[i][j] != nullPtr) {
				if (pieces[i][j]->sprite.getGlobalBounds().contains((float) mouseX, (float) mouseY )){
					dragObject = pieces[i][j];
					choosenPiece = pieces[i][j];
					dragStartCoords = position2coords(sf::Vector2f(mouseX, mouseY));
					legalMoves = getLegalMoves(choosenPiece, sf::Vector2u(i,j));
				}
			}
		}
	}
}

void Board::undrag(int mouseX, int mouseY) {
	dragging = false;
	dragObject = NULL;
	if (choosenPiece != NULL){
		playPiece(mouseX, mouseY);
	}
}

sf::Vector2u Board::position2coords(sf::Vector2f position) {
	int i = (position.x - (float)boardPosition.x) / squareSize;
	int j = (position.y - (float)boardPosition.y) / squareSize;
	return sf::Vector2u(i,j);
}

void Board::playPiece(int mouseX, int mouseY) {

	sf::Vector2u targetCoord = position2coords(sf::Vector2f((float)mouseX, (float)mouseY));

	if (targetCoord.x != dragStartCoords.x or targetCoord.y != dragStartCoords.y) {
		std::list<sf::Vector2u> legalMoves = getLegalMoves(choosenPiece, dragStartCoords);

		choosenPiece = NULL;

		std::list<sf::Vector2u>::iterator it;
		for (it = legalMoves.begin(); it != legalMoves.end(); ++it) {
			if ((*it).x == targetCoord.x and (*it).y == targetCoord.y) {
				pieces[targetCoord.x][targetCoord.y] = pieces[dragStartCoords.x][dragStartCoords.y];
				pieces[dragStartCoords.x][dragStartCoords.y] = nullPtr;
				//destroy target piece
				break;
			}
		}
	}
}