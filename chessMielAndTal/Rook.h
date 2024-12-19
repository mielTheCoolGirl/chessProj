#pragma once
#include "LinearMovement.h"

class Rook : public LinearMovement
{
public:
	Rook(char rookType, std::string coords);
	~Rook();
	bool legalMovement();
};
