#include "King.h"
King::King(const char& kingType, const string& coords, const bool& color) : Piece(kingType, coords, color)
{

}
King::~King()
{
}

bool King::legalMovement(const string& dstCoords) const
{
	int x1, x2, y1, y2;
	string coordsCalc = lettersToCoords(dstCoords);
	x1 = coordsCalc[0] - '0';
	y1 = coordsCalc[1] - '0';
	x2 = coordsCalc[2] - '0';
	y2 = coordsCalc[3] - '0';
	//check if the movement is only by one step (horizontal vertical or diagnoal)
	if (abs(x2 - x1) <= 1 && abs(y2 - y1) <= 1)
	{
		return true;
	}
	return false;
}

