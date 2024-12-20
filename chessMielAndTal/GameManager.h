#pragma once
#include "Board.h"
#include "Piece.h"
class GameManager
{
private:
	bool _currentPlayer;
public:
	bool turnExpn(const string& coords, const Board& board);
	bool getCurrentPlayer()const;
	void setCurrentPlayer(bool current);
	void switchPlayer();
	void mainGame();
};
