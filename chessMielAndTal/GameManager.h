#pragma once
#include "Board.h"

class GameManager
{
private:
	bool _currentPlayer;
public:
	void turnExpn(const std::string& coords, const Board& b);
	bool getCurrentPlayer()const;
	void setCurrentPlayer(bool current);
	void switchPlayer();
	const char* mainGame(std::string inputCoords);
};
