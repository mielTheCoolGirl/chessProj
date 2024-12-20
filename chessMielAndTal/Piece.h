#pragma once
#include <string>

#define LOWER_LET_TO_NUM 49
//taking only the class since we dont need all the board's traits just the board itself
using namespace std;
class Board;

class Piece
{
protected:
	char _type;
	std::string _currentCoords;
	bool _color;
public:
	Piece(const char& type, const string& currentCoords, const bool& color);
	virtual ~Piece();

	void eat(const string& endCoords);
	//checks legal movement on board
	virtual bool legalMovement(const string& dstCoords)const = 0;

	//moves on board
	virtual void move(Board& board)=0;

	
	static std::string lettersToCoords(string coords);
	char getType()const;

	std::string getCurrentCoords()const;

	void setType(const char& newType);

	void setCurrentCoords(const string& newCoords);

};
