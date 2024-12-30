#pragma once
#include "Piece.h"

class King :public Piece
{
public:
	King(const char& kingType, const std::string& coords);
	~King();

	bool legalMovement(const Board& board, const std::string& dstCoords)const override;
};