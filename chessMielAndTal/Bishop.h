#pragma once
#include "LinearMovement.h"

class Bishop : public LinearMovement
{
public:
	Bishop(const char& bishopType, const string& coords);
	~Bishop();
	bool legalMovement(const string& dstCoords)const override;
};

