#pragma once
#include "Piece.h"
//since board includes piece
class Board;

class LinearMovement: public Piece
{
public:
	LinearMovement(char linearPieceType, std::string coords);
	~LinearMovement();
	void move(Board& board) override;
	bool legalMovement(const string& dstCoords)const override;

};