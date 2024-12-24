#include "LinearMovement.h"
#include "Rook.h"
class Rook;
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
	Piece* eaten = nullptr;
	Piece* king = nullptr;
	int srcX = int(numSrc[1] - ASC_NUM_TO_NUM); int srcY = int(numSrc[0] - ASC_NUM_TO_NUM);
	int dstX = int(numDst[1] - ASC_NUM_TO_NUM); int dstY = int(numDst[0] - ASC_NUM_TO_NUM);
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
	
	eaten = eat(b, numDst);
	delete (b.board[dstY][dstX]);
	b.board[dstY][dstX] = b.board[srcY][srcX];
	b.board[srcY][srcX] = nullptr;
	
	king = b.findKing(b.board[dstY][dstX]->getColor());
	if (b.checkDanger(b.board[dstY][dstX]))
	{
		if (b.board[dstY][dstX]->getType() == tolower('r'))
		{
			b.board[srcY][srcX] = new Rook();
		}
		else
		{
			b.board[srcY][srcX] = new Rook(); //currently there is only rook
		}
		
		*b.board[srcY][srcX] = *b.board[dstY][dstX]; //return king back to place
		if (eaten == nullptr)
		{
			delete (b.board[dstY][dstX]);
			b.board[dstY][dstX] = nullptr;
		}
		else
		{
			*b.board[dstY][dstX] = *eaten;
		}
		delete eaten;
		throw(4); //check expn
	}
	
	b.board[dstY][dstX]->setCurrentCoords(dstCoords); //new coords of piece
	
}


