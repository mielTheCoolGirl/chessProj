#include "Queen.h"

Queen::Queen(const char& queenType, const std::string& coords):LinearMovement(queenType,coords)
{

}

Queen::~Queen()
{
}
bool Queen::legalMovement(const Board& board, const std::string& dstCoords) const
{
	std::string originCoords = lettersToCoords(_currentCoords);
	std::string destnationCoords = lettersToCoords(dstCoords);
	int distanceX, distanceY;
	distanceY = (originCoords[0] - ASC_NUM_TO_NUM) - (destnationCoords[0] - ASC_NUM_TO_NUM);
	distanceX = (originCoords[1] - ASC_NUM_TO_NUM) - (destnationCoords[1] - ASC_NUM_TO_NUM);
	//check rook like moves
	if (distanceX == 0 || distanceY == 0)
		return true;
	//check bishop like moves
	if (abs(distanceX) == abs(distanceY))
		return true;
	return false;
}
