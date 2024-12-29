#include "Knight.h"

Knight::Knight(const char& knightType, const std::string& coords): Piece(knightType,coords)
{

}
Knight::~Knight()
{
}

bool Knight::legalMovement(const Board& board, const std::string& dstCoords) const
{
	int knightMoveOptions[8][2] = { {-1,-2},{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2} };
	std::string originCoords = lettersToCoords(_currentCoords);
	std::string destnationCoords = lettersToCoords(dstCoords);
	int ySum = (originCoords[0] - ASC_NUM_TO_NUM) - (destnationCoords[0] - ASC_NUM_TO_NUM);
	int xSum = (originCoords[1] - ASC_NUM_TO_NUM) - (destnationCoords[1] - ASC_NUM_TO_NUM);
	for (int i=0;i<BOARD_LEN;i++)
	{
		if (xSum == knightMoveOptions[i][0] && ySum == knightMoveOptions[i][1])
			return true;
	}
	return false;
}

void Knight::move(Board& board, const std::string dstCoords)
{ 
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
	delete eaten;
	

}
