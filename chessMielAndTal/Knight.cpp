#include "Knight.h"

Knight::Knight(const char& knightType, const std::string& coords): Piece(knightType,coords)
{

}
Knight::~Knight()
{
}

bool Knight::legalMovement(const std::string& dstCoords) const
{
	std::string originCoords = lettersToCoords(_currentCoords);
	std::string destnationCoords = lettersToCoords(dstCoords);
	int ySum = (originCoords[0] - ASC_NUM_TO_NUM) - (destnationCoords[0] - ASC_NUM_TO_NUM);
	int xSum = (originCoords[1] - ASC_NUM_TO_NUM) - (destnationCoords[1] - ASC_NUM_TO_NUM);
	if (abs(ySum)!=2 && abs(ySum) != 1 && abs(xSum) != 2 && abs(xSum) != 1)
	{
		return true;
	}
	return false;
}

void Knight::move(Board& board, std::string dstCoords)
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
	delete eaten;
	

}
