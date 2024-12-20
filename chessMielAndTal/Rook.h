#pragma once
#include "LinearMovement.h"

class Rook : public LinearMovement
{
public:
	Rook(const char& rookType, const std::string& coords);
	~Rook();
	bool legalMovement(const string& dstCoords)const override;
};
