#pragma once
#include <string>
#define LOWER_LET_TO_NUM 49
//taking only the class since we dont need all the board's traits just the board itself
class Board;

class Piece
{
protected:
	char _type;
	std::string _currentCoords;
public:
	Piece(char type,std::string currentCoords);
	virtual ~Piece();

	void eat(std::string endCoords);
	//checks legal movement on board
	virtual bool legalMovement() = 0;

	//moves on board
	virtual void move(Board& board)=0;

	
	std::string lettersToCoords(std::string coords);
	
	char getType()const;

	std::string getCurrentCoords()const;

	void setType(char newType);

	void setCurrentCoords(std::string newCoords);

};
