#pragma once
#include "Piece.h"

#define BLACK 1
#define WHITE 0



class Pawn :public Piece
{
private:
	bool _isFirstTurn;
public:
	Pawn(const char& pawnType, const std::string& coords,bool firstTurn);
	~Pawn();

	void move(Board& board, const std::string dstCoords) override;
	bool legalMovement(const Board& b, const std::string& dstCoords)const override;

	bool getFirstTurn()const;
	void setFirstTurn(const bool state);
};
