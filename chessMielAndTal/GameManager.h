#pragma once
#include "Board.h"

//defining current build for chessboard(we start with white)
#define BUILD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"
class GameManager
{
private:
	bool _currentPlayer;
public:
	Board b;
	GameManager();
	bool turnExpn(const std::string& coords, const Board& b);
	bool getCurrentPlayer()const;
	void setCurrentPlayer(bool current);
	int mainGame(std::string inputCoords);
	
};
