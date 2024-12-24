#pragma once
#include "LinearMovement.h"

class Rook : public LinearMovement
{
public:
	Rook(const char& rookType, const std::string& coords, const bool& color);
	~Rook();
	bool legalMovement(const std::string& dstCoords) const override;
};
