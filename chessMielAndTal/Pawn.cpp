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
	srcY = originCoords[0] - '0';
	srcX = originCoords[1] - '0';
	dstY = destnationCoords[0] - '0';
	dstX = destnationCoords[1] - '0';
	//checking if its eating
	if (abs(srcX - dstX) == 1 && abs(srcY - dstY) == 1)
	{
		eaten = eat(board, destnationCoords);
		board.board[dstY][dstX] = board.board[srcY][srcX];
		board.board[srcY][srcX] = nullptr;
		board.board[dstY][dstX]->setCurrentCoords(dstCoords);
		king = board.findKing(board.board[dstY][dstX]->getColor());
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
	board.board[dstY][dstX] = board.board[srcY][srcX];
	board.board[srcY][srcX] = nullptr;
}


bool Pawn::legalMovement(const Board& board, const std::string& dstCoords) const
{
	std::string numDst, numSrc;
	numDst = lettersToCoords(dstCoords);
	numSrc = lettersToCoords(_currentCoords);
	int sumY = (numSrc[0] - ASC_NUM_TO_NUM) - (numDst[0] - ASC_NUM_TO_NUM);
	int sumX = (numSrc[1] - ASC_NUM_TO_NUM) - (numDst[1] - ASC_NUM_TO_NUM);

	//checking legal movement including checking if the pawn wants to eat(and if its possible)
	if (abs(sumX) == 1 && abs(sumY) == 1)
	{
		if (board.board[numDst[0] - ASC_NUM_TO_NUM][numDst[1] - ASC_NUM_TO_NUM] == nullptr)
			return false;
		return true;
	}
	if (sumX != 0 || (_isFirstTurn==false && abs(sumY) > 1) || (_isFirstTurn && sumY > 2))
		return false;
	
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
