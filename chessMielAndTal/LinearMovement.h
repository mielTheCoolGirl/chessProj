#pragma once
#include "Piece.h"
//since board includes piece

class LinearMovement: public Piece
{
public:
	LinearMovement(char linearPieceType, std::string coords);
	~LinearMovement();
	void move(Board& b,const std::string dstCoords) override;

	virtual bool legalMovement(const Board& board, const std::string& dstCoords)const=0;

};