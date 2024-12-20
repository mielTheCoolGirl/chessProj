#include "Rook.h"
Rook::Rook(const char& rookType, const std::string& coords, const bool& color) : LinearMovement(rookType, coords, color)
{

}

Rook::~Rook()
{
}

void Rook::eat(const std::string& endCoords)
{
}


bool Rook::legalMovement(const std::string& dstCoords)const
{
	//if the rook dosnt move in a line
	if (!(dstCoords[0] == dstCoords[2] || dstCoords[1] == dstCoords[3]))
	{
		return false;
	}
	return true;
}
