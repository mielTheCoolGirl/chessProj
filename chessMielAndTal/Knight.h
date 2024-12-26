#pragma once
#include "Piece.h"

class Knight : public Piece
{
	Knight(const char& knightType, const std::string& coords);
	~Knight();
	bool legalMovement(const std::string& dstCoords) const override;
	void move(Board& board, std::string dstCoords) override;
};
