#include "GameManager.h"
#include "Board.h"

#define BLACK_CHECKS 2 
#define WHITE_CHECKS 1
#define MAX_LEN 65

using std::cout;
using std::cin;
using std::endl;

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
	std::string a = "";
	std::string coords = "a7a5";
	std::string build = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1";

	//cout << "Enter board build: "; //rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1
	//std::getline(std::cin, build);
	//if (build.length() > MAX_LEN)
	//{
	//	build.erase(MAX_LEN);
	//}
	_currentPlayer = build[MAX_LEN - 1];

	build.pop_back();
	Board b(build);
	b.printBoard();

	while (coords != "exit")
	{
		try
		{
			switch (_currentPlayer)
			{
			case WHITE:
				cout << "Current Player: white" << endl;
				break;
			default:
				cout << "Current Player: black" << endl;
			}
			
			cout << "Enter Move: ";
			std::cin >> coords;
			int srcX = (coords[0] - LOWER_LET_TO_NUM), srcY = (coords[1] - ASC_NUM_TO_NUM - 1);
			int dstX = (coords[2] - LOWER_LET_TO_NUM), dstY = (coords[3] - ASC_NUM_TO_NUM - 1);
			turnExpn(coords, b);
			b.board[srcY][srcX]->move(b, coords.substr(2, 4));
			_currentPlayer = !_currentPlayer;
		}

		catch (int e)
		{
			
			if (e == 7)
			{
				std::cout << "src and dst are the same" << std::endl;
			}
			else if (e == 4)
			{
				std::cout << "Error: check will occur on you king with this move" << std::endl;
			}
			else
			{
				cout << "Error. Code: " << e << endl;
			}

		}
		b.printBoard();
	}
	
	
	
}

bool GameManager::turnExpn(const std::string& coords, const Board& b)
{
	std::string numSrc = "";
	std::string numDst = "";
	if (coords.length() != 4)
	{
		throw int(5);
	}
	numSrc = Piece::lettersToCoords(coords.substr(0, 2));
	numDst = Piece::lettersToCoords(coords.substr(2, 4));
	
	int srcX = int(numSrc[1] - ASC_NUM_TO_NUM); int srcY = int(numSrc[0] - ASC_NUM_TO_NUM);
	int dstX = int(numDst[1] - ASC_NUM_TO_NUM); int dstY = int(numDst[0] - ASC_NUM_TO_NUM);

	// format: srcCoords + dstCoords (each coord is 2 chars letter and number)
	if (Board::isInBounds(srcX, srcY) == false || Board::isInBounds(dstX, dstY) == false)
	{
		throw int(5); //src or dst are not in bounds
	}
	else if (numSrc == numDst)
	{
		throw (7); //dst and src are the same
	}
	else if (b.board[srcY][srcX] == nullptr || b.board[srcY][srcX]->getColor() != this->_currentPlayer)
	{
		throw int(2); //no player's piece in tile
	}
	else if (b.board[dstY][dstX] != nullptr && b.board[dstY][dstX]->getColor() == this->_currentPlayer)
	{
		throw int(3); //same color piece in dst
	}
	else if (b.board[srcY][srcX]->legalMovement(coords.substr(2,4)) == false)
	{
		throw int(6); //not legal move of piece
	}


}