#include "King.h"
#define BOARD_LEN 8
King::King(const char& kingType, const std::string& coords, const bool& color) : Piece(kingType, coords, color)
{

}
King::King() : Piece('k', "0000", true)
{
}



King::~King()
{
}

//void King::eat(Board& board, const std::string& endCoords)
//{
//	std::string newCoords = lettersToCoords(_currentCoords);
//	board.board[endCoords[0] - '0'][endCoords[1] - '0'] = board.board[newCoords[0] - '0'][newCoords[1] - '0'];
//	board.board[newCoords[0] - '0'][newCoords[1] - '0'] = nullptr;
//}

void King::move(Board& board, std::string dstCoords)
{
	int srcY, srcX, dstY, dstX;
	std::string coordsCalc = lettersToCoords(dstCoords);
	std::string firstCoords = lettersToCoords(_currentCoords);
	Piece* eaten = nullptr;
	srcY = firstCoords[0] - '0';
	srcX = firstCoords[1] - '0';
	dstY = coordsCalc[0] - '0';
	dstX = coordsCalc[1] - '0';

	/*if (board.board[y2][x2] != nullptr)
	{
		if (board.board[y2][x2]->getColor() != this->getColor())
		{
			eat(board, coordsCalc);
		}
		else
		{
			throw int(3);
		}
	}*/

	eaten = eat(board, coordsCalc);
	board.board[dstY][dstX] = board.board[srcY][srcX];
	board.board[srcY][srcX] = nullptr;
	if (board.checkDanger(board.board[dstY][dstX]))
	{
		board.board[srcY][srcX] = new King();
		*board.board[srcY][srcX] = *board.board[dstY][dstX]; //return king back to place
		*board.board[dstY][dstX] = *eaten;
		delete eaten;
		throw(4); //check expn
	}
	board.board[dstY][dstX]->setCurrentCoords(dstCoords);
	delete eaten;
	
	

		
	

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
