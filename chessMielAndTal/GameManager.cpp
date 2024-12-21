#include "GameManager.h"
#include "Board.h"

bool GameManager::getCurrentPlayer() const
{
	return _currentPlayer;
}

void GameManager::setCurrentPlayer(bool current)
{
	_currentPlayer = current;
}

void GameManager::switchPlayer()
{
	if (!_currentPlayer)
		_currentPlayer = true;
	else
		_currentPlayer = false;
}

void GameManager::mainGame()
{
	Board b;
	b.printBoard();
	b.board[7][0]->move(b,"b1");
	b.printBoard();
}

bool GameManager::turnExpn(const std::string& coords, const Board& board)
{
	std::string src = "";
	std::string dst = "";
	if (coords.length() != 4)
	{
		throw int(5);
	}
	src = coords.substr(0, 1);
	dst = coords.substr(2, 3);

	// format: srcCoords + dstCoords (each coord is 2 chars letter and number)
	if (coords[0] < 'a' || coords[0] > 'h' || coords[2] < 'a' || coords[2] > 'h' || //letter checking
		coords[1] < '1' || coords[1] > '8' || coords[3] < '1' || coords[3] > '8') //number cheking
	{
		throw int(5);
	}
	else if (board.board[src[0]][src[1]]->getColor() != this->_currentPlayer)
	{
		throw int(2);
	}
	else if (board.board[dst[0]][dst[1]]->getColor() == this->_currentPlayer)
	{
		throw int(3);
	}


}