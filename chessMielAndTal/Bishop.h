#pragma once
#include "LinearMovement.h"

class Bishop : public LinearMovement
{
public:
	Bishop(const char& bishopType, const std::string& coords);
	~Bishop();
	bool legalMovement(const Board& board, const std::string& dstCoords)const override;
};

