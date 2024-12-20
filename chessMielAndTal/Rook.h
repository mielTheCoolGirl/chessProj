#pragma once
#include "LinearMovement.h"

class Rook : public LinearMovement
{
public:
	Rook(const char& rookType, const std::string& coords, const bool& color);
	~Rook();
	void eat(const std::string& endCoords)override ;
	bool legalMovement(const std::string& dstCoords) const override;
};
