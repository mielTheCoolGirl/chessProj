#pragma once
#define BOARD_LEN 8
#include <iostream>
#include "Piece.h"

#define WHITE 0
#define BLACK 1
class Piece;

class Board
{
private:
	//function checks the rook/queen department
	bool checkHorizonAndVert(const Piece* king, const int kingX, const int kingY);

	bool pawnCheck(const Piece* king,const int kingX,const int kingY);
	
	bool knightCheck(const Piece* king,const int kingX,const int kingY);
	
	bool diagonalCheck(const Piece* king, const int kingX, const int kingY);
	//checks if there is a possible check that could happen becuase of a king next to a king
	bool kingDanger(const Piece* king, const int kingX, const int kingY);
	
public:
	Piece* board[BOARD_LEN][BOARD_LEN];
	Board(const std::string& build);
	~Board();
	void printBoard()const;
	//getter and setter
	static bool isInBounds(int x, int y);
	Piece* findKing(const bool& color);
	//checks danger for a king, returns true or false(checks for current king peice)
	bool checkDanger(const Piece* king);
	
};
