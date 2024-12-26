#include "Rook.h"
Rook::Rook(const char& rookType, const std::string& coords) : LinearMovement(rookType, coords)
{

}

Rook::~Rook()
{
}


bool Rook::legalMovement(const Board& board, const std::string& dstCoords)const
{
	//if the rook doesnt move in a line
	if ((this->_currentCoords[0] == dstCoords[0] && this->_currentCoords[1] != dstCoords[1]) ||
		 this->_currentCoords[0] != dstCoords[0] && this->_currentCoords[1] == dstCoords[1])
	{
		return true;
	}
	return false;
}
