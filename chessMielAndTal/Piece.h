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

	virtual void eat(std::string endCoords)=0;
	//checks legal movement on board
	virtual bool legalMovement()=0;

	//moves on board
	virtual void move(Board& board)=0;

	
	std::string lettersToCoords(std::string coords);
	
	char getType()const;

	std::string getCurrentCoords()const;

	void setType(char newType);

	void setCurrentCoords(std::string newCoords);

};
