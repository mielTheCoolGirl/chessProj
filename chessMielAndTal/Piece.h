#pragma once
#include <string>
#include "Board.h"
#define LOWER_LET_TO_NUM 97
#define ASC_NUM_TO_NUM 48
#define TRUE 2
#define AFTER 1
#define FALSE 0
class Board;

class Piece
{
protected:
	char _type;
	std::string _currentCoords;
	bool _color; //true is white, false is black
	int _isFirstTurn;
public:
	Piece(const char& type, const std::string& currentCoords);
	virtual ~Piece();
	//returns the eaten piece
	Piece* eat(Board& b, const std::string& dstCoords);
	//checks legal movement on board
	virtual bool legalMovement(const Board& board, const std::string& dstCoords) const = 0;

	//moves on board
	virtual void move(Board& board, const std::string dstCoords) =0;

	
	static std::string lettersToCoords(std::string letters);
	char getType()const;

	std::string getCurrentCoords()const;

	void setType(const char& newType);

	void setCurrentCoords(const std::string newCoords);

	bool getColor()const;
	void setColor(const bool& color);

	int getFirstTurn()const;
	void setFirstTurn(const int state);
};
