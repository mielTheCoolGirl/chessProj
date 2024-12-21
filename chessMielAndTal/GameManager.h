#pragma once
#include "Board.h"

class GameManager
{
private:
	bool _currentPlayer;
public:
	bool turnExpn(const std::string& coords, const Board& b);
	bool getCurrentPlayer()const;
	void setCurrentPlayer(bool current);
	void switchPlayer();
	void mainGame();
};
