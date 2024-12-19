#include "LinearMovement.h"

LinearMovement::LinearMovement(char linearPieceType, std::string coords):Piece(linearPieceType, coords)
{

}
LinearMovement::~LinearMovement()
{
}
void LinearMovement::move(Board& board)
{
}

bool LinearMovement::legalMovement()
{
	return false;
}
