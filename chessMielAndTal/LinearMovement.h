#pragma once
#include "Piece.h"
//since board includes piece
class Board;
class LinearMovement: public Piece
{
public:
	LinearMovement(char linearPieceType, std::string coords, const bool& color);
	~LinearMovement();
	void move(Board& board) override;
	virtual bool legalMovement(const string& dstCoords)const=0;

};