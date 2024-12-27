#pragma once
#include "Board.h"

//"rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"
#define BUILD "############################k######P############################0"
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
	void switchPlayer();
	int mainGame(std::string inputCoords);
};
