#pragma once
#include <string>
#include "Board.h"

class Board;

class Piece
{
protected:
	char _type;
	std::string _currentCoords;
public:
	Piece(char const type,std::string const currentCoords);
	~Piece();

	void eat(std::string endCoords);
	
	std::string lettersToCoords(std::string coords);
	
	char getType()const;

	std::string getCurrentCoords()const;

	void setType(char newType);

	void setCurrentCoords(std::string newCoords);

	//checks legal movement on board
	bool legalMovement();
	
	//moves on board
	void move(Board& board);

};
