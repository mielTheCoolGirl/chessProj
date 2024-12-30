#include "Pawn.h"


Pawn::Pawn(const char& pawnType, const std::string& coords):Piece(pawnType,coords)
{
}

Pawn::~Pawn()
{
}

void Pawn::move(Board& board, const std::string dstCoords)
{
	_isFirstTurn = _isFirstTurn == TRUE ? AFTER : FALSE;//after the first move it can no longer move two steps at a time
	int srcX, srcY, dstX, dstY;
	Piece* eaten = nullptr;
	Piece* king = nullptr;
	std::string originCoords = lettersToCoords(_currentCoords);
	std::string destnationCoords = lettersToCoords(dstCoords);
	std::string prevCoords = _currentCoords;

	srcY = originCoords[0] - ASC_NUM_TO_NUM;
	srcX = originCoords[1] - ASC_NUM_TO_NUM;
	dstY = destnationCoords[0] - ASC_NUM_TO_NUM;
	dstX = destnationCoords[1] - ASC_NUM_TO_NUM;
	
	king = board.findKing(board.board[srcY][srcX]->getColor());
	//checking if its eating
	if (abs(srcX - dstX) == 1)
	{
		eaten = eat(board, destnationCoords);
		board.board[dstY][dstX] = board.board[srcY][srcX];
		board.board[srcY][srcX] = nullptr;
		board.board[dstY][dstX]->setCurrentCoords(dstCoords);
		//if the king of the current color is checked after movement
		if (board.checkDanger(king))
		{
			board.board[dstY][dstX]->setCurrentCoords(prevCoords);
			board.board[srcY][srcX] = board.board[dstY][dstX];
			board.board[dstY][dstX] = eaten;
			throw(4); //check expn
		}
	}
	else
	{
		board.board[dstY][dstX] = board.board[srcY][srcX];
		board.board[srcY][srcX] = nullptr;
		board.board[dstY][dstX]->setCurrentCoords(dstCoords);
		//if the king of the current color is checked after movement
		if (board.checkDanger(king))
		{
			board.board[dstY][dstX]->setCurrentCoords(prevCoords);
			board.board[srcY][srcX] = board.board[dstY][dstX];
			board.board[dstY][dstX] = nullptr;
			throw(4); //check expn
		}
		
	}
	//promoting pawn if he reached the end
	if (this->getColor()==false && dstY == 0)
	{
		board.board[dstY][dstX] = new Queen('Q', dstCoords);
		delete this;
	}
	else if (this->getColor() == true && dstY == 7)
	{
		board.board[dstY][dstX] = new Queen('q', dstCoords);
		delete this;
	}
		
	
}


bool Pawn::legalMovement(const Board& b, const std::string& dstCoords) const
{
	std::string numDst, numSrc;
	numDst = lettersToCoords(dstCoords);
	numSrc = lettersToCoords(_currentCoords);
	int subY = (numDst[0] - ASC_NUM_TO_NUM) - (numSrc[0] - ASC_NUM_TO_NUM);
	int subX = (numDst[1] - ASC_NUM_TO_NUM) - (numSrc[1] - ASC_NUM_TO_NUM);
	int direction = this->getColor() ? 1 : -1; //The color of the piece determines its direction
	int dstY = numDst[0] - ASC_NUM_TO_NUM, dstX = numDst[1] - ASC_NUM_TO_NUM;
	int srcY = numSrc[0] - ASC_NUM_TO_NUM, srcX = numSrc[1] - ASC_NUM_TO_NUM;
	if (abs(subX) > 1 || !(subY == direction || (subY == 2 * direction && _isFirstTurn)))
		return false;
		
	//checking legal movement including checking if the pawn wants to eat(and if its possible)
	if (abs(subX) == 1)
	{
		if (abs(subY) != 1 ||
			b.board[dstY][dstX] == nullptr && (b.board[srcY][srcX + subX] == nullptr ||
			b.board[srcY][srcX + subX]->getColor() != _color && b.board[srcY][srcX + subX]->getFirstTurn() != AFTER))
			return false;
		return true;
	}

	//subX = 0
	for (int i = direction; i != subY + direction; i += direction)
	{
		//if there is piece in way
		if (b.board[srcY + i][srcX] != nullptr)
			return false;
	}

	return true;
}




