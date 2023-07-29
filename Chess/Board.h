#pragma once
#include "Piece.h"
#include "SFML/Graphics.hpp"
#include <list>

class Piece;

class Board {
private:
	bool dragging = false;
	sf::Vector2u dragStartCoords;
	sf::Vector2f dragDiff;
	Piece* dragObject;
	Piece* nullPtr = NULL;
	Piece* choosenPiece = NULL;
	std::list<sf::Vector2u> legalMoves = {};
	sf::Vector2u boardPosition = sf::Vector2u(25, 25);
	int squareSize = 100;
	bool isReverse = false;
	sf::RenderWindow* windowPointer;


	std::list<sf::Vector2u> getLegalMoves(Piece* piece, sf::Vector2u position);
	sf::Vector2u position2coords(sf::Vector2f position);
	
public:
	
	static enum class Thema { Classic, blackWhite, Purple } Classic;
	Thema thema = Thema::Purple;
	Piece* pieces[8][8] = { {nullPtr, nullPtr , nullPtr, nullPtr, nullPtr, nullPtr, nullPtr, nullPtr }, {nullPtr, nullPtr , nullPtr, nullPtr, nullPtr, nullPtr, nullPtr, nullPtr } ,{nullPtr, nullPtr , nullPtr, nullPtr, nullPtr, nullPtr, nullPtr, nullPtr } ,{nullPtr, nullPtr , nullPtr, nullPtr, nullPtr, nullPtr, nullPtr, nullPtr } ,{nullPtr, nullPtr , nullPtr, nullPtr, nullPtr, nullPtr, nullPtr, nullPtr } ,{nullPtr, nullPtr , nullPtr, nullPtr, nullPtr, nullPtr, nullPtr, nullPtr } ,{nullPtr, nullPtr , nullPtr, nullPtr, nullPtr, nullPtr, nullPtr, nullPtr } ,{nullPtr, nullPtr , nullPtr, nullPtr, nullPtr, nullPtr, nullPtr, nullPtr } };
	
	Board(sf::RenderWindow* windowPointer);
	void draw();
	void reverse();
	void setStartingPosition();
	void controlDrag(int mouseX, int mouseY);
	void undrag(int mouseX, int mouseY);
	void playPiece(int mouseX, int mouseY);
};