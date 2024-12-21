#include "LinearMovement.h"

LinearMovement::LinearMovement(char linearPieceType, std::string coords, const bool& color) :  Piece(linearPieceType, coords, color)
{

}
LinearMovement::~LinearMovement()
{
}
void LinearMovement::move(Board& b, std::string dstCoords)
{ 
	//The function is checked assuming that there isnt same color piece in target slot 
	std::string numSrc = lettersToCoords(this->_currentCoords);
	std::string numDst = lettersToCoords(dstCoords);

	int srcX = int(numSrc[0]); int srcY = int(numSrc[1]);
	int dstX = int(numDst[0]); int dstY = int(numDst[1]);
	//change of X and Y per tile 
	int dx = (dstX > srcX) ? 1 : (dstX < srcX) ? -1 : 0;
	int dy = (dstY > srcY) ? 1 : (dstY < srcY) ? -1 : 0;

	int x = srcX + dx;
	int y = srcY + dy;

	while (x != dstX || y != dstY)
	{
		if (b.board[y][x] != nullptr)
			throw (PIECE_IN_WAY_EXPN);
		x += dx;
		y += dy;
	}

	//move the piece
	b.board[dstY][dstX] = b.board[srcY][srcX];
	b.board[srcY][srcX] = nullptr;

	b.board[dstY][dstX]->setCurrentCoords(dstCoords); //new coords of piece
	
}

void LinearMovement::eat(Board & board, const std::string & endCoords)
{
}
