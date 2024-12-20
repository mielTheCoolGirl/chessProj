#include "LinearMovement.h"

LinearMovement::LinearMovement(char linearPieceType, std::string coords, const bool& color) :  Piece(linearPieceType, coords, color)
{

}
LinearMovement::~LinearMovement()
{
}
void LinearMovement::move(Board& board, std::string dstCoords)
{
}

void LinearMovement::eat(Board & board, const std::string & endCoords)
{
}
