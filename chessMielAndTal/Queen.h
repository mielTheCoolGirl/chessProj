#pragma once
#include "LinearMovement.h"
#include "Bishop.h"
#include "Rook.h"
class Queen :public LinearMovement
{
	Queen(const char& queenType, const std::string& coords);
	~Queen();
	bool legalMovement(const Board& board, const std::string& dstCoords)const override;
};