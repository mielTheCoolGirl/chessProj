#pragma once
#include "LinearMovement.h"
class Rook : public LinearMovement
{
	Rook(char rookType, std::string coords);
	~Rook();
	bool legalMovement();
};
