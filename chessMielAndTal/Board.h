#pragma once
#define BOARD_LEN 8
#include <iostream>
#include "Piece.h"

class Piece;

class Board
{
private:
	int _isChecking;

public:
	Piece* board[BOARD_LEN][BOARD_LEN];
	void printBoard();
	bool checkDanger(Piece* king);
};
