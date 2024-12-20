#include "King.h"
#define BOARD_LEN 8
King::King(const char& kingType, const std::string& coords, const bool& color) : Piece(kingType, coords, color)
{

}
King::~King()
{
}

void King::eat(Board& board, const std::string& endCoords)
{
	std::string newCoords = lettersToCoords(_currentCoords);
	board.board[endCoords[0] - '0'][endCoords[1] - '0'] = board.board[BOARD_LEN - (newCoords[1] - '0')][newCoords[0] - '0'];
	board.board[BOARD_LEN - (newCoords[1] - '0')][newCoords[0] - '0'] = nullptr;
}

void King::move(Board& board, std::string dstCoords)
{
	int x1, x2, y1, y2;
	std::string coordsCalc = lettersToCoords(dstCoords);
	std::string firstCoords = lettersToCoords(_currentCoords);
	y1 = firstCoords[0] - '0';
	x1 = BOARD_LEN-(firstCoords[1] - '0');
	y2 = coordsCalc[0] - '0';
	x2 = coordsCalc[1] - '0';

	if (board.board[y2][x2] != nullptr)
	{
		if (board.board[y2][x2]->getColor() != this->getColor())
		{
			eat(board,coordsCalc);
		}
		else
		{
			throw std::string("Exit Code 3- Improper move, in the target slot there is a tool of the current player");
		}
	}
	else
	{
		board.board[y2][x2] = board.board[y1][x1];
		board.board[y1][x1] = nullptr;
		_currentCoords = dstCoords;
	}

}

bool King::legalMovement(const std::string& dstCoords) const
{
	int x1, x2, y1, y2;
	std::string coordsCalc = lettersToCoords(dstCoords);
	std::string firstCoords = lettersToCoords(_currentCoords);

	y1 = firstCoords[0] - '0';
	x1 = firstCoords[1] - '0';
	y2 = coordsCalc[0] - '0';
	x2 = coordsCalc[1] - '0';


	//check if the movement is only by one step (horizontal vertical or diagnoal)
	if (abs(x2 - x1) <= 1 && abs(y2 - y1) <= 1)
	{
		return true;
	}
	return false;
}

