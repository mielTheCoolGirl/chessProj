#include "Rook.h"
Rook::Rook(const char& rookType, const string& coords, const bool& color) : LinearMovement(rookType, coords, color)
{

}

Rook::~Rook()
{
}

bool Rook::legalMovement(const string& dstCoords) const
{
	return false;
}

bool Rook::legalMovement(const string& dstCoords)const
{
	//if the rook dosnt move in a line
	if (!(dstCoords[0] == dstCoords[2] || dstCoords[1] == dstCoords[3]))
	{
		return false;
	}
	return true;
}
