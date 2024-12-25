#include "Bishop.h"

Bishop::Bishop(const char& bishopType, const std::string& coords) : 
	LinearMovement(bishopType, coords)
{
}

Bishop::~Bishop()
{
}

bool Bishop::legalMovement(const std::string& dstCoords) const
{
	int x1, x2, y1, y2, slope;
	std::string coordsCalc = lettersToCoords(dstCoords);
	std::string firstCoords = lettersToCoords(_currentCoords);
	y1 = firstCoords[0] - '0';
	x1 = firstCoords[1] - '0';
	y2 = coordsCalc[0] - '0';
	x2 = coordsCalc[1] - '0';

	slope = (x2 - x1) / (y2 - y1);
	if (slope != 1)
	{
		return false;
	}
	return true;
	
}
