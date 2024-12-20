#include "LinearMovement.h"

LinearMovement::LinearMovement(char linearPieceType, std::string coords, const bool& color) : 
	Piece(linearPieceType, coords, color)
{

}
LinearMovement::~LinearMovement()
{
}
void LinearMovement::move(Board& board)
{
}

bool LinearMovement::legalMovement(const string& dstCoords)const
{
	return false;
}
