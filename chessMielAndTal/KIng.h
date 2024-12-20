#pragma once
#include "Piece.h"

class King :public Piece
{
public:
	King(const char& kingType, const std::string& coords, const bool& color);
	~King();

	void eat(Board & board, const std::string & endCoords) override;
	void move(Board& board , std::string dstCoords) override;

	bool legalMovement(const std::string& dstCoords)const override;
};