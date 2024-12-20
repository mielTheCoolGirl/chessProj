#include "Bishop.h"

Bishop::Bishop(const char& bishopType, const string& coords) : LinearMovement(bishopType, coords)
{
}

Bishop::~Bishop()
{
}

bool Bishop::legalMovement(const string& dstCoords) const
{
	return false;
}
