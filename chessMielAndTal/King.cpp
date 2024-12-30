#include "King.h"
#define BOARD_LEN 8
King::King(const char& kingType, const std::string& coords) : Piece(kingType, coords)
{

}

King::~King()
{
}

bool King::legalMovement(const Board& board, const std::string& dstCoords) const
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
