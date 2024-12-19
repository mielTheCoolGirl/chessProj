#pragma once
#include "LinearMovement.h"
class Bishop : public LinearMovement
{
	Bishop(char bishopType, std::string coords);
	~Bishop();
	bool legalMovement();
};

