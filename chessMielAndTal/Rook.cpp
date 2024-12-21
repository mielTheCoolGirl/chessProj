#include "Rook.h"
Rook::Rook(const char& rookType, const std::string& coords, const bool& color) : LinearMovement(rookType, coords, color)
{

}

Rook::~Rook()
{
}

void Rook::eat(Board & board, const std::string & endCoords)
{
}


bool Rook::legalMovement(const std::string& dstCoords)const
{
	//if the rook doesnt move in a line
	if ((this->_currentCoords[0] == dstCoords[0] && this->_currentCoords[1] != dstCoords[1]) ||
		 this->_currentCoords[0] != dstCoords[0] && this->_currentCoords[1] != dstCoords[1])
	{
		return false;
	}
	return true;
}
