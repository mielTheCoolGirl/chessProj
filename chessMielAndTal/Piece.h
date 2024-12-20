#pragma once
#include <string>
#include "Board.h"
#define LOWER_LET_TO_NUM 97
#define ASC_NUM_TO_NUM '0'
#define PIECE_IN_WAY_EXPN 9
class Board;

class Piece
{
protected:
	char _type;
	std::string _currentCoords;
	bool _color;
public:
	Piece(const char& type, const std::string& currentCoords, const bool& color);
	virtual ~Piece();

	virtual void eat(Board & board, const std::string & endCoords)=0;
	//checks legal movement on board
	virtual bool legalMovement(const std::string& dstCoords) const = 0;

	//moves on board
	virtual void move(Board& board, std::string dstCoords)=0;

	
	static std::string lettersToCoords(std::string coords);
	char getType()const;

	std::string getCurrentCoords()const;

	void setType(const char& newType);

	void setCurrentCoords(const std::string newCoords);

	bool getColor()const;
	void setColor(const bool& color);
};
