#include "Rook.h"
Rook::Rook(const char& rookType, const std::string& coords, const bool& color) : LinearMovement(rookType, coords, color)
{

}

Rook::Rook() : LinearMovement('r', "0000", WHITE)
{
}
Rook::~Rook()
{
}


bool Rook::legalMovement(const std::string& dstCoords)const
{
	//if the rook doesnt move in a line
	if ((this->_currentCoords[0] == dstCoords[0] && this->_currentCoords[1] != dstCoords[1]) ||
		 this->_currentCoords[0] != dstCoords[0] && this->_currentCoords[1] != dstCoords[1])
	{
		return true;
	}
	return false;
}
