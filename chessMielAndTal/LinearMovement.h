#pragma once
#include "Piece.h"
//since board includes piece

class LinearMovement: public Piece
{
public:
	LinearMovement(char linearPieceType, std::string coords, const bool& color);
	~LinearMovement();
	void move(Board& board, std::string dstCoords) override;
	virtual void eat(const std::string& endCoords) override;
	virtual bool legalMovement(const std::string& dstCoords)const=0;

};