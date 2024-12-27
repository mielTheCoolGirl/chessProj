#include "GameManager.h"
#include "Board.h"

#define NO_CHECKS 0
#define CHECKS 1
#define MAX_LEN 65


using std::cout;
using std::cin;
using std::endl;

bool GameManager::getCurrentPlayer() const
{
	return _currentPlayer;
}
//rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1
GameManager::GameManager():b(BUILD)
{
	std::string build = BUILD;
	_currentPlayer = build[MAX_LEN - 1] - ASC_NUM_TO_NUM;

	build.pop_back();
	b.printBoard();

}
void GameManager::setCurrentPlayer(bool current)
{
	_currentPlayer = current;
}



int GameManager::mainGame(std::string inputCoords)
{
	std::string coords = inputCoords;
	std::string originalPlace = Piece::lettersToCoords(inputCoords.substr(0, 2));
	try
	{

		coords = inputCoords;
		int srcX = (coords[0] - LOWER_LET_TO_NUM), srcY = BOARD_LEN - (coords[1] - ASC_NUM_TO_NUM);
		int dstX = (coords[2] - LOWER_LET_TO_NUM), dstY = BOARD_LEN - (coords[3] - ASC_NUM_TO_NUM);
		turnExpn(coords, b);
		b.board[srcY][srcX]->move(b, coords.substr(2, 4));
		_currentPlayer = !_currentPlayer;
		b.printBoard();
		if (b.checkDanger(b.findKing(_currentPlayer)))
		{
			return CHECKS;
		}
		return NO_CHECKS;


	}

	catch (int e)
	{
		return e;
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
	else if (b.board[srcY][srcX]->legalMovement(b,coords.substr(2,4)) == false)
	{
		throw int(6); //not legal move of piece
	}


}