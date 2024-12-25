#include "King.h"
#define BOARD_LEN 8
King::King(const char& kingType, const std::string& coords, const bool& color) : Piece(kingType, coords, color)
{

}
King::King() : Piece('k', "0000", WHITE)
{
}



King::~King()
{
}

void King::move(Board& b, std::string dstCoords)
{
	int srcY, srcX, dstY, dstX;
	std::string coordsCalc = lettersToCoords(dstCoords);
	std::string firstCoords = lettersToCoords(_currentCoords);
	Piece* eaten = nullptr;
	srcY = firstCoords[0] - '0';
	srcX = firstCoords[1] - '0';
	dstY = coordsCalc[0] - '0';
	dstX = coordsCalc[1] - '0';

	eaten = eat(b, coordsCalc);
	//delete (b.board[dstY][dstX]);
	b.board[dstY][dstX] = b.board[srcY][srcX];
	b.board[srcY][srcX] = nullptr;

	if (b.checkDanger(b.board[dstY][dstX])) //if king is checked
	{
		b.board[srcY][srcX] = b.board[dstY][dstX];
		b.board[dstY][dstX] = eaten;
		//b.board[srcY][srcX] = new King();
		//*b.board[srcY][srcX] = *b.board[dstY][dstX]; //return king back to place
		//if (eaten == nullptr)
		//{
		//	delete (b.board[dstY][dstX]);
		//	b.board[dstY][dstX] = nullptr;
		//}
		//else
		//	*b.board[dstY][dstX] = *eaten;
		//delete eaten;
		throw(4); //check expn
	}
	b.board[dstY][dstX]->setCurrentCoords(dstCoords);
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
