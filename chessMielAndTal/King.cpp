#include "King.h"
#define BOARD_LEN 8
King::King(const char& kingType, const std::string& coords) : Piece(kingType, coords)
{

}

King::~King()
{
}

void King::move(Board& b, std::string dstCoords)
{
	int srcY, srcX, dstY, dstX;
	std::string coordsCalc = lettersToCoords(dstCoords);
	std::string firstCoords = lettersToCoords(_currentCoords);
	std::string prevCoords = _currentCoords;
	Piece* eaten = nullptr;
	srcY = firstCoords[0] - '0';
	srcX = firstCoords[1] - '0';
	dstY = coordsCalc[0] - '0';
	dstX = coordsCalc[1] - '0';

	eaten = eat(b, coordsCalc);
	b.board[dstY][dstX] = b.board[srcY][srcX];
	b.board[srcY][srcX] = nullptr;
	b.board[dstY][dstX]->setCurrentCoords(dstCoords);

	if (b.checkDanger(b.board[dstY][dstX])) //if king is checked
	{
		b.board[dstY][dstX]->setCurrentCoords(prevCoords);
		b.board[srcY][srcX] = b.board[dstY][dstX];
		b.board[dstY][dstX] = eaten;
		delete eaten;
		throw(4); //check expn
	}
	delete eaten;
	
	

		
	

}

bool King::legalMovement(const std::string& dstCoords) const
{
	int x1, x2, y1, y2;
	std::string coordsCalc = lettersToCoords(dstCoords);
	std::string firstCoords = lettersToCoords(_currentCoords);

	y1 = firstCoords[0] - '0';
	x1 = firstCoords[1] - '0';
	y2 = coordsCalc[0] - '0';
	x2 = coordsCalc[1] - '0';


	//check if the movement is only by one step (horizontal vertical or diagnoal)
	if (abs(x2 - x1) <= 1 && abs(y2 - y1) <= 1)
	{
		return true;
	}
	return false;
}
