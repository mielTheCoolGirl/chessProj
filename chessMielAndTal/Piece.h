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
	bool _color; //true is white, false is black
public:
	Piece(const char& type, const std::string& currentCoords, const bool& color);
	virtual ~Piece();

	Piece* eat(Board & b, const std::string & targetCoords);
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

	Piece& operator=(const Piece& other);
};
