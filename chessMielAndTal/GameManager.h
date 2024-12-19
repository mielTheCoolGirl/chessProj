#pragma once
class GameManager
{
private:
	bool _currentPlayer;
public:
	bool getCurrentPlayer()const;
	void setCurrentPlayer(bool current);
	void switchPlayer();
	void mainGame();
};
