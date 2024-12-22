#pragma once
#define BOARD_LEN 8
#include <iostream>
#include "Piece.h"

class Piece;

class Board
{
private:
	int _isChecking;
	//function checks the rook/queen department
	bool checkHorizonAndVert(Piece* king, int kingX, int kingY);
	bool pawnCheck(Piece* king, int kingX, int kingY);
	bool knightCheck(Piece* king, int kingX, int kingY);
	bool diagonalCheck(Piece* king, int kingX, int kingY);

public:
	Piece* board[BOARD_LEN][BOARD_LEN];
	Board();
	~Board();
	void printBoard()const;
	//getter and setter
	int getIsChecking()const;
	void setIsChecking(int state);
	//checks danger for a king, returns true or false(checks for current king peice)
	bool checkDanger(Piece* king);
};
