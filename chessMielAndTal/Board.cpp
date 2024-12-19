#include "Board.h"
#define A_VALUE 97
Board::Board()
{
	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j=0;j<BOARD_LEN;j++)
			board[i][j] = nullptr;
	}
	for (int i = 0; i < BOARD_LEN; i++)
	{
		char res = char(i + A_VALUE);
		std::string coordsStr = "2";
		coordsStr += res;
		board[1][i] = new Piece('P',  coordsStr);
		
	}
	for (int i = 0; i < BOARD_LEN; i++)
	{
		char res = char(i + A_VALUE);
		std::string coordsStr = "6";
		coordsStr += res;
		board[6][i] = new Piece('p', coordsStr);
	}
	
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
