#include "Bishop.h"

Bishop::Bishop(const char& bishopType, const string& coords, const bool& color) : 
	LinearMovement(bishopType, coords, color)
{
}

Bishop::~Bishop()
{
}

bool Bishop::legalMovement(const string& dstCoords) const
{
	int x1, x2, y1, y2, slope;
	string coordsCalc= lettersToCoords(dstCoords);
	x1 = coordsCalc[0]-'0';
	y1 = coordsCalc[1] - '0';
	x2 = coordsCalc[2] - '0';
	y2 = coordsCalc[3] - '0';
	slope = (x2 - x1) / (y2 - y1);
	if (slope != 1)
	{
		return false;
	}
	return true;
	
}
