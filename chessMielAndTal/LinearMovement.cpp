#include "LinearMovement.h"
LinearMovement::LinearMovement(char linearPieceType, std::string coords) :  Piece(linearPieceType, coords)
{

}
LinearMovement::~LinearMovement()
{
}
void LinearMovement::move(Board& b,const std::string dstCoords)
{ 
	
	//The function is checked assuming that there isnt same color piece in target slot 
	std::string numSrc = lettersToCoords(this->_currentCoords);
	std::string numDst = lettersToCoords(dstCoords);
	int srcX = int(numSrc[1] - ASC_NUM_TO_NUM); int srcY = int(numSrc[0] - ASC_NUM_TO_NUM);
	int dstX = int(numDst[1] - ASC_NUM_TO_NUM); int dstY = int(numDst[0] - ASC_NUM_TO_NUM);
	//change of X and Y per tile 
	int dx = (dstX > srcX) ? 1 : (dstX < srcX) ? -1 : 0;
	int dy = (dstY > srcY) ? 1 : (dstY < srcY) ? -1 : 0;
	if (b.board[srcY][srcX] == nullptr)
		throw(3);
	
	int x = srcX + dx;
	int y = srcY + dy;

	while (x != dstX || y != dstY)
	{
		if (b.board[y][x] != nullptr)
			throw (6);
		x += dx;
		y += dy;
	}
	
	eat(b, dstCoords);
}


