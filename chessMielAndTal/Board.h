#pragma once
#define BOARD_LEN 8
#include <iostream>
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"

class Piece;

class Board
{
private:
	int _isChecking;

public:
	Piece* board[BOARD_LEN][BOARD_LEN];
	Board();
	~Board();
	void printBoard()const;
	int getIsChecking()const;
	void setIsChecking(int state);
	bool checkDanger(Piece* king);
};
