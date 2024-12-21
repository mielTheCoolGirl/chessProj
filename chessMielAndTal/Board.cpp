#include "Board.h"
#include "Rook.h"
#include "King.h"
#define A_VALUE 97
#define WHITE 1
#define BLACK 0
Board::Board() : _isChecking(0)
{

	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
			board[i][j] = nullptr;
	}
	//putting all the pawns in place
	for (int i = 0; i < BOARD_LEN; i++)
	{
		char res = char(i + A_VALUE);
		std::string coordsStr = "2";
		coordsStr += res;
		board[1][i] = new Rook('R', coordsStr, WHITE);

	}
	for (int i = 0; i < BOARD_LEN; i++)
	{
		char res = char(i + A_VALUE);
		std::string coordsStr = "6";
		coordsStr += res;
		board[6][i] = new Rook('r', coordsStr, BLACK);
	}
	board[7][0] = new King('K', "a1", WHITE);//setting up a king to see if he eats


}

Board::~Board()
{
}

void Board::printBoard() const
{
	std::string boardRes = "";
	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
		{
			if (board[i][j] == nullptr)
				boardRes += "#";
			else
				boardRes += board[i][j]->getType();
			boardRes += " ";
		}
		boardRes += "\n";
	}
	std::cout << boardRes << std::endl;
}

int Board::getIsChecking() const
{
	return _isChecking;
}

void Board::setIsChecking(int state)
{
	_isChecking = state;
}

bool Board::checkDanger(Piece* king)
{
	return false;
}