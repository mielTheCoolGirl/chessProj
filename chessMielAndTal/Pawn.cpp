#include "Pawn.h"



Pawn::Pawn(const char& pawnType, const std::string& coords, bool firstTurn):Piece(pawnType,coords),_isFirstTurn(firstTurn)
{
}

Pawn::~Pawn()
{
}

void Pawn::move(Board& board, const std::string dstCoords)
{
	_isFirstTurn = false;//after the first move it can no longer move two steps at a time
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
	if (abs(srcX - dstX) == 1 && abs(srcY - dstY) == 1)
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
			delete eaten;
			throw(4); //check expn
		}
	}
	else
	{
		if (board.board[dstY][dstX] != nullptr)
		{
			//throwing it under code 6 since pawns cant eat like rooks/queens
			throw(6);
		}
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
	
}


bool Pawn::legalMovement(const Board& board, const std::string& dstCoords) const
{
	std::string numDst, numSrc;
	numDst = lettersToCoords(dstCoords);
	numSrc = lettersToCoords(_currentCoords);
	int subY = (numSrc[0] - ASC_NUM_TO_NUM) - (numDst[0] - ASC_NUM_TO_NUM);
	int subX = (numSrc[1] - ASC_NUM_TO_NUM) - (numDst[1] - ASC_NUM_TO_NUM);
	int direction = this->getColor() ? -1 : 1; //The color of the piece determines its direction

	if (abs(subX) > 1)
		return false;

	if (!(subY == direction || (subY == 2 * direction && _isFirstTurn)))
		return false;
		
	//checking legal movement including checking if the pawn wants to eat(and if its possible)
	if (abs(subX) == 1)
	{
		if (abs(subY) != 1 || board.board[numDst[0] - ASC_NUM_TO_NUM][numDst[1] - ASC_NUM_TO_NUM] == nullptr)
			return false;
	}
	
	return true;
}

bool Pawn::getFirstTurn() const
{
	return _isFirstTurn;
}

void Pawn::setFirstTurn(const bool state)
{
	_isFirstTurn = state;
}
