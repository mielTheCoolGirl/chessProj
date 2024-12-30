#pragma once
#include "Piece.h"
#include "Queen.h"
#define BLACK 1
#define WHITE 0
#define PROMOTION 9




class Pawn :public Piece
{
private:
	//int _isFirstTurn;
public:
	Pawn(const char& pawnType, const std::string& coords);
	~Pawn();

	void move(Board& board, const std::string dstCoords) override;
	bool legalMovement(const Board& b, const std::string& dstCoords)const override;

	
};
