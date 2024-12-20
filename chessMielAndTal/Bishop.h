#pragma once
#include "LinearMovement.h"

class Bishop : public LinearMovement
{
public:
	Bishop(const char& bishopType, const std::string& coords, const bool& color);
	~Bishop();
	bool legalMovement(const std::string& dstCoords)const override;
};

