#pragma once
#include "LinearMovement.h"
class LinearMovement;
class Rook : public LinearMovement
{
public:
	Rook(const char& rookType, const std::string& coords);
	~Rook();
	bool legalMovement(const std::string& dstCoords) const override;
};
