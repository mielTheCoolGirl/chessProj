#pragma once
#include "Board.h"

//"####p#######################k######P###################P#####K##0"
//"rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"
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
	void switchPlayer();
	int mainGame(std::string inputCoords);
};
