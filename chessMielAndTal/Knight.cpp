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


