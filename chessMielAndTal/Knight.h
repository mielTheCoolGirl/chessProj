#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(const char& knightType, const std::string& coords);
	~Knight();
	bool legalMovement(const Board& board, const std::string& dstCoords) const override;
	void move(Board& board, const std::string dstCoords) override;
};
