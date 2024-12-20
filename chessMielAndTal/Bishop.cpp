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
	return false;
}
