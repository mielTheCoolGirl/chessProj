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
	Piece(char type,std::string currentCoords);
	~Piece();

	void eat(std::string endCoords);
	
	std::string lettersToCoords(std::string coords);
	
	//checks legak movement on board
	bool legalMovement();
	
	//moves on board
	void move(Board& board);

};
