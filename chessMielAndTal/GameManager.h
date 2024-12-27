#pragma once
#include "Board.h"

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
