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
	//change of X and Y per tile 
	int dx = (numDst[0] > numSrc[0]) ? 1 : (numDst[0] < numSrc[0]) ? -1 : 0;
	int dy = (numDst[1] > numSrc[1]) ? 1 : (numDst[1] < numSrc[1]) ? -1 : 0;

	int x = numSrc[0] + dx;
	int y = numSrc[1] + dy;

	while (x != dstCoords[1] || y != dstCoords[0])
	{
		if (b.board[y][x] != nullptr)
			throw (PIECE_IN_WAY_EXPN);
		x += dx;
		y += dy;
	}

	//move the piece
	b.board[numDst[1]][numDst[0]] = b.board[numSrc[1]][numSrc[0]];
	b.board[numSrc[1]][numSrc[0]] = nullptr;

	b.board[numDst[1]][numDst[0]]->setCurrentCoords(dstCoords); //new coords of piece
	
}

void LinearMovement::eat(Board & board, const std::string & endCoords)
{
}
