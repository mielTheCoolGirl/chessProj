#pragma once
#include "Piece.h"

class Pawn :public Piece
{
private:
	bool _isFirstTurn;
public:
	Pawn(const char& pawnType, const std::string& coords,bool firstTurn);
	~Pawn();

	void move(Board& board, const std::string dstCoords) override;
	bool legalMovement(Board& board,const std::string& dstCoords)const;
};
