#include "Bishop.h"

Bishop::Bishop(const char& bishopType, const std::string& coords) : 
	LinearMovement(bishopType, coords)
{
}

Bishop::~Bishop()
{
}

bool Bishop::legalMovement(const Board& board, const std::string& dstCoords) const
{
	int x1, x2, y1, y2, slope;
	std::string coordsCalc = lettersToCoords(dstCoords);
	std::string firstCoords = lettersToCoords(_currentCoords);
	y1 = firstCoords[0] - ASC_NUM_TO_NUM;
	x1 = firstCoords[1] - ASC_NUM_TO_NUM;
	y2 = coordsCalc[0] - ASC_NUM_TO_NUM;
	x2 = coordsCalc[1] - ASC_NUM_TO_NUM;
	if ((y2 - y1) == 0)
		return false;
	slope = (x2 - x1) / (y2 - y1);
	if (abs(slope) != 1)
	{
		return false;
	}
	return true;
	
}
