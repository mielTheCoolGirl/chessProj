#pragma once
#include <string>
#include "Board.h"

class Piece
{
protected:
	char _type;
	std::string currentCoords;
public:
	void eat(std::string endCoords);
	std::string lettersToCoords(std::string coords);
	bool legalMovement();
	void move(Board& board);

};
