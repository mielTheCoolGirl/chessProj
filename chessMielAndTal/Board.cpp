#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#define A_VALUE 97
#define WHITE 1
#define BLACK 0
#define BLACK_CHECKS 2 
#define WHITE_CHECKS 1
Board::Board() : _isChecking(0)
{

	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
			board[i][j] = nullptr;
	}
	//putting all the rooks in place(for checking, in the main game it will be pawns)
	for (int i = 0; i < BOARD_LEN; i++)
	{
		std::string resCoord = "";
		char res = char(i + A_VALUE);
		resCoord += res;
		resCoord += "7";
		board[1][i] = new Rook('R', resCoord, WHITE);

	}
	for (int i = 0; i < BOARD_LEN; i++)
	{
		std::string resCoord = "";
		char res = char(i + A_VALUE);
		resCoord += res;
		resCoord += "2";
		board[6][i] = new Rook('r', resCoord, BLACK);
	}
	//setting them up just for testing
	/*board[7][0] = new Bishop('b', "a1", BLACK);
	board[6][1] = new Bishop('B', "b2", WHITE);*/
	board[5][2] = new King('K', "c3", WHITE);//setting up a king 
	


}

Board::~Board()
{
	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
		{
			if (board[i][j] != nullptr)
			{
				delete board[i][j];
				board[i][j] = nullptr;
			}
		}

	}

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
	std::string kingCoords = Piece::lettersToCoords(king->getCurrentCoords());
	int kingX = kingCoords[1] - '0';
	int kingY = kingCoords[0] - '0';
	if (pawnCheck(king, kingX, kingY) || knightCheck(king, kingX, kingY) || checkHorizonAndVert(king, kingX, kingY) || diagonalCheck(king, kingX, kingY))
	{
		if (king->getColor() == WHITE)
		{
			_isChecking = BLACK_CHECKS;
		}
		else
		{
			_isChecking = WHITE_CHECKS;
		}
		return true;
	}
	_isChecking = 0;
	return false;

}

bool Board::isInBounds(int x, int y)
{
	return !(x > BOARD_LEN - 1 || x < 0 || y > BOARD_LEN - 1 || y < 0);
}

bool Board::checkHorizonAndVert(Piece* king, int kingX, int kingY)
{
	bool kingColor = king->getColor();
	bool potCheck = true; //Potiential check
	Piece* p = nullptr;
	for (int y = kingY + 1; y < BOARD_LEN && potCheck == true; y++) //check below to king
	{
		p = board[y][kingX];
		if (p != nullptr)
		{
			if (kingColor != p->getColor() && (tolower(p->getType()) == 'q' || tolower(p->getType()) == 'r'))
			{
				return true;
			}
			else
			{
				potCheck = false;
			}
		}
	}
	potCheck = true;
	for (int y = kingY - 1; y >= 0 && potCheck == true; y--) //check above the king
	{
		p = board[y][kingX];
		if (p != nullptr)
		{
			if (kingColor != p->getColor() && (tolower(p->getType()) == 'q' || tolower(p->getType()) == 'r'))
			{
				return true;
			}
			else
			{
				potCheck = false;
			}
		}
	}
	potCheck = true;
	for (int x = kingX + 1; x < BOARD_LEN && potCheck == true; x++) //check right to the king
	{
		p = board[kingY][x];
		if (p != nullptr)
		{
			if (kingColor != p->getColor() && (tolower(p->getType()) == 'q' || tolower(p->getType()) == 'r'))
			{
				return true;
			}
			else
			{
				potCheck = false;
			}
		}
	}
	potCheck = true;
	for (int x = kingX - 1; x >= 0 && potCheck == true; x--) //check left to the king
	{
		p = board[kingY][x];
		if (p != nullptr)
		{
			if (kingColor != p->getColor() && (tolower(p->getType()) == 'q' || tolower(p->getType()) == 'r'))
			{
				return true;
			}
			else
			{
				potCheck = false;
			}
		}
	}
	return false;
}


bool Board::pawnCheck(Piece* king, int kingX, int kingY)
{					
	if (king->getColor() == WHITE)
	{
		if ((isInBounds(kingX + 1, kingY + 1) && board[kingY + 1][kingX + 1] != nullptr && board[kingY + 1][kingX + 1]->getType() == 'p') ||
			(isInBounds(kingX + 1, kingY - 1) && board[kingY - 1][kingX + 1] != nullptr && board[kingY - 1][kingX + 1]->getType() == 'p'))
		{
			return true;
		}
	}
	else //black color
	{
		if ((isInBounds(kingX - 1, kingY - 1) && board[kingY - 1][kingX - 1] != nullptr && board[kingY - 1][kingX - 1]->getType() == 'P') ||
			(isInBounds(kingX + 1, kingY - 1) && board[kingY - 1][kingX + 1] != nullptr && board[kingY - 1][kingX + 1]->getType() == 'P'))
		{
			return true;
		}
	}
	return false;
	
}

bool Board::knightCheck(Piece* king, int kingX, int kingY)
{
	//storing all the possible attack places of knight's x and y across the board 
	int amountOfMovs = 8;
	int posX, posY;
	int knightMoveOptions[8][2] = { {-1,-2},{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2}};
	for (int i = 0; i < amountOfMovs; i++)
	{
		posX = knightMoveOptions[i][0] + kingX;
		posY = knightMoveOptions[i][1] + kingY;
		if (posX < BOARD_LEN && posX >= 0 && posY < BOARD_LEN && posY >= 0)
		{
			if (board[posY][posX] != nullptr)
			{
				if (board[posY][posX]->getColor() != king->getColor() && tolower(board[posY][posX]->getType()) == 'n')
				{
					/*if (board[posY][posX]->getColor())
					{
						_isChecking = WHITE_CHECKS;
					}
					else
					{
						_isChecking = BLACK_CHECKS;
					}*/
					return true;
				}
			}
		}
	}
	

	return false;
}

bool Board::diagonalCheck(Piece* king, int kingX, int kingY)
{
	bool possibleThreat = true;
	for (int i = kingX, j = kingY; i < BOARD_LEN && j < BOARD_LEN && possibleThreat == true; i++, j++)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				possibleThreat = true;
				if (board[j][i]->getColor())
				{
					_isChecking = WHITE_CHECKS;
				}
				else
				{
					_isChecking = BLACK_CHECKS;
				}
			}
			else //if its a piece that doesnt threaten the king(diagonally)
			{
				possibleThreat = false;
			}
		}
	}
	
	for (int i = kingX, j = kingY; i >= 0 && j >= 0 && possibleThreat == true; i--, j--)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				possibleThreat = true;
				if (board[j][i]->getColor())
				{
					_isChecking = WHITE_CHECKS;
				}
				else
				{
					_isChecking = BLACK_CHECKS;
				}
			}
			else
			{
				possibleThreat = false;
			}
	
		}
	}
	
	for (int i = kingX, j = kingY; i >= 0 && j < BOARD_LEN && possibleThreat == true; i--, j++)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				possibleThreat = true;
				if (board[j][i]->getColor())
				{
					_isChecking = WHITE_CHECKS;
				}
				else
				{
					_isChecking = BLACK_CHECKS;
				}
			}
			else
			{
				possibleThreat = false;
			}
		}
	}

	for (int i = kingX, j = kingY; i < BOARD_LEN && j >= 0; i++, j--)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				possibleThreat = true;
				if (board[j][i]->getColor())
				{
					_isChecking = WHITE_CHECKS;
				}
				else
				{
					_isChecking = BLACK_CHECKS;
				}
			}
			else
			{
				possibleThreat = false;
			}
		}
	}
	return possibleThreat;
}


