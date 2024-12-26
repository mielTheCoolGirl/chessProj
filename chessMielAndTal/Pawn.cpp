#include "Pawn.h"

Pawn::Pawn(const char& pawnType, const std::string& coords, bool firstTurn):Piece(pawnType,coords),_isFirstTurn(firstTurn)
{
}

Pawn::~Pawn()
{
}

void Pawn::move(Board& board, const std::string dstCoords)
{
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
	if (abs(srcX - dstX) == 1)
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

bool Pawn::legalMovement(Board& board, const std::string& dstCoords) const
{
	int sumX, sumY;
	std::string numDst, numSrc;
	numDst = lettersToCoords(dstCoords);
	numSrc = lettersToCoords(_currentCoords);
	int SumY = (numSrc[0] - ASC_NUM_TO_NUM) - (numDst[0] - ASC_NUM_TO_NUM);
	int SumX = (numSrc[1] - ASC_NUM_TO_NUM) - (numDst[1] - ASC_NUM_TO_NUM);

	//checking legal movement including checking if the pawn wants to eat(and if its possible)
	
	if (sumX != 0 ||SumY < 1 ||(_isFirstTurn && SumY>2) || (!_isFirstTurn && SumY!=1)||
		!((board.board[numDst[0] - ASC_NUM_TO_NUM][numDst[1] - ASC_NUM_TO_NUM])!=nullptr && abs(sumX==1) &&SumY==1))
		return false;
	return true;
}
